#include <Servo.h>

// Membuat objek servo
Servo myServo;

// Mendefinisikan pin servo
const int servoPin = 9;

void setup() {
  // Menentukan pin servo dan menginisialisasi servo
  myServo.attach(servoPin);

  // Memulai komunikasi serial untuk menampilkan posisi di Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // Menggerakkan servo dari 0° ke 180°
  for (int pos = 0; pos <= 180; pos += 1) { // Inkrementasi 1 derajat
    myServo.write(pos);
    Serial.print("Posisi Servo: ");
    Serial.print(pos);
    Serial.println(" derajat");
    delay(15); // Tunggu 15 ms agar servo memiliki waktu untuk bergerak
  }

  // Menggerakkan servo dari 180° ke 0°
  for (int pos = 180; pos >= 0; pos -= 1) { // Dekrementasi 1 derajat
    myServo.write(pos);
    Serial.print("Posisi Servo: ");
    Serial.print(pos);
    Serial.println(" derajat");
    delay(15); // Tunggu 15 ms agar servo memiliki waktu untuk bergerak
  }
}
