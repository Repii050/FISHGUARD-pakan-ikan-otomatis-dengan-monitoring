#include <Wire.h>
#include <RTClib.h>
#include <Servo.h>

RTC_DS3231 rtc;         // Inisialisasi modul RTC
Servo servoMotor;       // Inisialisasi servo

// Variabel untuk menyimpan jadwal pakan
const int feedingHour = 14;     // Jam penjadwalan (misalnya 08:00)
const int feedingMinute = 20;   // Menit penjadwalan (misalnya jam 8:00)

// Variabel kontrol servo
const int servoPin = 9;        // Pin yang terhubung ke servo
const int openAngle = 90;      // Sudut saat servo membuka pakan
const int closeAngle = 0;      // Sudut saat servo menutup kembali pakan
const int feedDuration = 3000; // Durasi servo membuka (dalam milidetik)

void setup() {
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
  
  // Setup RTC jika belum diinisialisasi
  if (!rtc.begin()) {
    Serial.println("RTC tidak terdeteksi");
    while (1);
  }

  // Set RTC jika belum diatur (hapus comment untuk setting waktu awal sekali)
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  // Setup servo
  servoMotor.attach(servoPin);
  servoMotor.write(closeAngle); // Mulai dari posisi tertutup
}

void loop() {
  DateTime now = rtc.now();

  // Tampilkan waktu saat ini di Serial Monitor
  Serial.print("Sekarang: ");
  Serial.print(now.hour());
  Serial.print(":");
  Serial.println(now.minute());

  // Mengecek apakah waktu saat ini sama dengan waktu penjadwalan
  if (now.hour() == feedingHour && now.minute() == feedingMinute) {
    Serial.println("Waktu pakan, menggerakkan servo...");
    
    // Menggerakkan servo ke posisi terbuka
    servoMotor.write(openAngle);
    delay(feedDuration);
    
    // Menggerakkan servo kembali ke posisi tertutup
    servoMotor.write(closeAngle);
    
    // Tunggu satu menit untuk menghindari servo bergerak terus-menerus pada menit yang sama
    delay(60000);
  }
  
  delay(1000); // Update setiap detik
}
