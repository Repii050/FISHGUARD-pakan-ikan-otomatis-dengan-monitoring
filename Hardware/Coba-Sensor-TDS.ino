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
