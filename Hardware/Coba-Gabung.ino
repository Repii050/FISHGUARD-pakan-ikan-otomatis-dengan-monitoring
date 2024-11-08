#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

const int dataPin = 2;// Pin yang terhubung ke pin DATA DS18B20
const int tdsPin = A0; // Mendefinisikan pin analog yang terhubung ke sensor TDS
const float vRef = 5.0; // Tegangan input referensi di Arduino (biasanya 5V)
const float conversionFactor = 0.5; // Faktor konversi dari tegangan ke TDS, sesuaikan berdasarkan datasheet atau kalibrasi
const int trigPin = 9;// Mendefinisikan pin Trig
const int echoPin = 10;// Mendefinisikan pin Echo
long duration;// Variabel untuk menyimpan hasil pengukuran jarak
float distance;// Variabel untuk menyimpan hasil pengukuran jarak
const int servoPin = 5;// Mendefinisikan pin servo

Servo myServo;// Membuat objek servo
OneWire oneWire(dataPin);// Membuat instance dari OneWire
DallasTemperature sensors(&oneWire);// Membuat instance dari DallasTemperature
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
Serial.begin(9600);// Memulai komunikasi serial
sensors.begin();  // Memulai sensor DS18B20
// Mengatur pin trigPin sebagai output dan echoPin sebagai input
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
lcd.init();
lcd.backlight();

}
void loop() {
   pinMode(tdsPin, INPUT);  // Menentukan pin TDS sebagai input
  // Meminta sensor untuk melakukan pembacaan suhu
  sensors.requestTemperatures();
  // Menentukan pin servo dan menginisialisasi servo
  myServo.attach(servoPin);
  // Membaca suhu dalam Celsius dari sensor pertama (index 0)
  float temperatureC = sensors.getTempCByIndex(0);
   // Membaca nilai analog dari pin TDS
  int analogValue = analogRead(tdsPin);
  
  // Mengonversi nilai analog ke tegangan
  float voltage = analogValue * (vRef / 1024.0);
  
  // Menghitung nilai TDS (mg/L atau ppm)
  float tdsValue = voltage * conversionFactor * 1000; // Sesuaikan sesuai kalibrasi

  // Membersihkan pin trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Mengirimkan sinyal trigger selama 10 mikrodetik
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Membaca durasi waktu dari sinyal yang diterima oleh echoPin
  duration = pulseIn(echoPin, HIGH);

  // Menghitung jarak (dalam cm) berdasarkan waktu tempuh sinyal
  distance = duration * 0.034 / 2;

  // Menampilkan hasil pengukuran jarak di Serial Monitor
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
  
  // Menampilkan nilai TDS di Serial Monitor
  Serial.print("TDS Value: ");
  Serial.print(tdsValue);
  Serial.println(" ppm");

  delay(1000);

  // Menampilkan suhu di lcd
  lcd.setCursor(0, 0);
  lcd.print("Suhu: ");
  lcd.print(temperatureC);
  lcd.print(" C");

  // Menampilkan suhu di Serial Monitor
  Serial.print("Suhu: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

// Menampilkan suhu di lcd
  lcd.setCursor(0, 1);
  lcd.print("TDS Value: ");
  lcd.print(tdsValue);
  lcd.print(" ppm");

  delay(1000); // Membaca suhu setiap 1 detik
// Menampilkan nilai TDS di Serial Monitor
  Serial.print("TDS Value: ");
  Serial.print(tdsValue);
  Serial.println(" ppm");

  delay(1000);
  //  // Menggerakkan servo dari 0° ke 180°
  // for (int pos = 0; pos <= 180; pos += 1) { // Inkrementasi 1 derajat
  //   myServo.write(pos);
  //   Serial.print("Posisi Servo: ");
  //   Serial.print(pos);
  //   Serial.println(" derajat");
  //   delay(15); // Tunggu 15 ms agar servo memiliki waktu untuk bergerak
  // }

  // // Menggerakkan servo dari 180° ke 0°
  // for (int pos = 180; pos >= 0; pos -= 1) { // Dekrementasi 1 derajat
  //   myServo.write(pos);
  //   Serial.print("Posisi Servo: ");
  //   Serial.print(pos);
  //   Serial.println(" derajat");
  //   delay(15); // Tunggu 15 ms agar servo memiliki waktu untuk bergerak
  // }

}
