#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi RTC dan LCD
RTC_DS3231 rtc;
LiquidCrystal_I2C lcd(0x27, 16, 2); // Ubah 0x27 jika alamat I2C LCD berbeda

void setup() {
  Serial.begin(9600);
  lcd.init();       // Memulai LCD
  lcd.backlight();   // Menyalakan lampu latar LCD

  if (!rtc.begin()) {
    lcd.print("RTC Tidak Ada!");
    while (1);
  }

  if (rtc.lostPower()) {
    lcd.print("Atur ulang RTC!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // Setel waktu ke waktu saat ini
  }
rtc.adjust(DateTime(2024, 11, 02, 12, 31, 45)); // Atur ke 20 November 2024, 15:30:45

}

void loop() {
  DateTime now = rtc.now();

  // Menampilkan Tanggal di baris pertama LCD
  lcd.setCursor(0, 0);
  lcd.print("Tgl:");
  if (now.day() < 10) lcd.print("0"); // Tambah '0' jika hari < 10
  lcd.print(now.day());
  lcd.print('/');
  if (now.month() < 10) lcd.print("0"); // Tambah '0' jika bulan < 10
  lcd.print(now.month());
  lcd.print('/');
  lcd.print(now.year());

  // Menampilkan Waktu di baris kedua LCD
  lcd.setCursor(0, 1);
  lcd.print("Waktu: ");
  if (now.hour() < 10) lcd.print("0"); // Tambah '0' jika jam < 10
  lcd.print(now.hour());
  lcd.print(':');
  if (now.minute() < 10) lcd.print("0"); // Tambah '0' jika menit < 10
  lcd.print(now.minute());
  lcd.print(':');
  if (now.second() < 10) lcd.print("0"); // Tambah '0' jika detik < 10
  lcd.print(now.second());

  delay(1000); // Tunggu 1 detik
}
