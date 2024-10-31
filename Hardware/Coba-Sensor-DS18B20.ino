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
