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
