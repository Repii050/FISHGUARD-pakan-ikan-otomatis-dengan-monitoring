# Video Pengujian Komponen

Berikut adalah beberapa video serta progam yang digunakan dalam pengujian berbagai komponen sistem FishGuard.

## FishGuard - Pengujian Servo
https://github.com/user-attachments/assets/23995870-86eb-4068-b8aa-cf2c34f3a0c6

### Program Pengujian servo
Program ini berfungsi untuk melakukan pengujian dengan mengendalikan sebuah servo motor menggunakan Arduino, menggerakkannya dari sudut 0° hingga 180° dan kembali, sambil menampilkan posisi aktuator pada Serial Monitor.
```cpp
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
```

## FishGuard - Pengujian Sensor Ultrasonic HC-SR04
https://github.com/user-attachments/assets/480f4f2f-f9c4-4a9e-84b7-378d93c347e1

### Program Pengujian Sensor Ultrasonic HC-SR04
Program ini berfungsi untuk melakukan pengujian dengan mengukur jarak.
```cpp
// Mendefinisikan pin Trig dan Echo
const int trigPin = 9;
const int echoPin = 10;

// Variabel untuk menyimpan hasil pengukuran jarak
long duration;
float distance;

void setup() {
  // Inisialisasi komunikasi serial
  Serial.begin(9600);

  // Mengatur pin trigPin sebagai output dan echoPin sebagai input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
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

  delay(500); // Delay 0,5 detik untuk stabilitas pembacaan
}
```

## FishGuard - Pengujian Sensor DS18B20 Suhu
https://github.com/user-attachments/assets/f8e08aa3-e3c8-4e6e-869c-6c9238689587

### Program Sensor DS18B20 Suhu
Program ini berfungsi untuk melakukan pengujian dengan membaca suhu dari sensor DS18B20 menggunakan Arduino, dan menampilkan hasilnya di Serial Monitor. Sensor ini terhubung melalui protokol OneWire.
```cpp
#include <OneWire.h>
#include <DallasTemperature.h>

// Pin yang terhubung ke pin DATA DS18B20
const int dataPin = 2;

// Membuat instance dari OneWire
OneWire oneWire(dataPin);

// Membuat instance dari DallasTemperature
DallasTemperature sensors(&oneWire);

void setup() {
  // Memulai komunikasi serial
  Serial.begin(9600);

  // Memulai sensor DS18B20
  sensors.begin();
}

void loop() {
  // Meminta sensor untuk melakukan pembacaan suhu
  sensors.requestTemperatures();

  // Membaca suhu dalam Celsius dari sensor pertama (index 0)
  float temperatureC = sensors.getTempCByIndex(0);

  // Menampilkan suhu di Serial Monitor
  Serial.print("Suhu: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  delay(1000); // Membaca suhu setiap 1 detik
}
```

## FishGuard - Pengujian Sensor TDS Meter
https://github.com/user-attachments/assets/90e463b5-ef5b-4650-b92f-95f3acb5ff2d

### Program Pengujian Sensor TDS Meter
Program ini berfungsi untuk melakukan pengujian dengan membaca nilai Total Dissolved Solids (TDS) dalam larutan menggunakan sensor TDS yang terhubung ke pin analog Arduino. TDS mengukur jumlah partikel terlarut (seperti mineral dan garam) dalam air, biasanya dinyatakan dalam ppm (parts per million).
```cpp
// Mendefinisikan pin analog yang terhubung ke sensor TDS
const int tdsPin = A0; 

// Tegangan input referensi di Arduino (biasanya 5V)
const float vRef = 5.0; 
// Faktor konversi dari tegangan ke TDS, sesuaikan berdasarkan datasheet atau kalibrasi
const float conversionFactor = 0.5; 

void setup() {
  Serial.begin(9600);  // Memulai komunikasi serial untuk membaca hasil TDS
  pinMode(tdsPin, INPUT);  // Menentukan pin TDS sebagai input
}

void loop() {
  // Membaca nilai analog dari pin TDS
  int analogValue = analogRead(tdsPin);
  
  // Mengonversi nilai analog ke tegangan
  float voltage = analogValue * (vRef / 1024.0);
  
  // Menghitung nilai TDS (mg/L atau ppm)
  float tdsValue = voltage * conversionFactor * 1000; // Sesuaikan sesuai kalibrasi
  
  // Menampilkan nilai TDS di Serial Monitor
  Serial.print("TDS Value: ");
  Serial.print(tdsValue);
  Serial.println(" ppm");

  delay(1000);  // Membaca nilai TDS setiap 1 detik
}
```
## FishGuard - Schematic
![WhatsApp Image 2024-11-03 at 12 50 31 AM (1)](https://github.com/user-attachments/assets/643c4b5d-407f-4f4f-8e89-340295ae1b01)
## FishGuard - PCB Bawah
![WhatsApp Image 2024-11-03 at 12 49 42 AM (1)](https://github.com/user-attachments/assets/767fb568-114a-40cb-a19b-5c52bac9cc2b)
## FishGuard - PCB Atas
![WhatsApp Image 2024-11-03 at 12 49 16 AM (1)](https://github.com/user-attachments/assets/f6bd6fdc-ea4b-4cb8-9d68-19df0edf0196)
