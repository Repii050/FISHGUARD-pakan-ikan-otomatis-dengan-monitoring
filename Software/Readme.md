## Aktifasi SSL/TLS di Broker HiveMQ Cloud
Jika kamu menggunakan HiveMQ Cloud (layanan broker MQTT yang di-host oleh HiveMQ) dan ingin mengaktifkan SSL/TLS untuk koneksi aman, berikut langkah-langkahnya:
### 1. Buat Akun dan Masuk ke HiveMQ Cloud
   * Kunjungi situs HiveMQ Cloud.
   * Buat akun atau login jika sudah memiliki akun.
   * Setelah masuk, kamu akan diarahkan ke dashboard HiveMQ Cloud.
### 2.  Buat atau Kelola MQTT Cluster
   * Di dashboard, klik "Create Cluster" untuk membuat broker MQTT baru jika belum ada. Jika sudah ada cluster, pilih cluster yang ingin kamu konfigurasi.
![cluster](https://github.com/user-attachments/assets/750dd740-9dac-4716-9a62-1035a37236d5)

   
   * Setelah memilih atau membuat cluster, kamu akan masuk ke halaman detail cluster.
![Screenshot 2024-11-10 160504](https://github.com/user-attachments/assets/dba830f6-464f-493e-9fc2-14582ac12847)

   
### 3. Mengaktifkan SSL/TLS di HiveMQ Cloud
HiveMQ Cloud secara otomatis mengaktifkan SSL/TLS untuk koneksi aman. Kamu tidak perlu secara manual membuat atau mengunggah sertifikat, karena HiveMQ Cloud menggunakan sertifikat yang diterbitkan oleh Let's Encrypt atau penyedia sertifikat lainnya untuk mengamankan koneksi.
1. Port TLS: HiveMQ Cloud biasanya menyediakan dua port:
   * Port MQTT tanpa TLS (1883).
   * Port MQTT dengan TLS (8883).
Kamu hanya perlu memastikan bahwa klien MQTT yang kamu gunakan terhubung ke port 8883 untuk koneksi aman menggunakan SSL/TLS.

### 4. Navigasi ke Pengaturan Otentikasi
1. Pada halaman detail cluster, pilih menu "Access Management" atau "Authentication" di bagian navigasi atas.
2. Di halaman Authentication, kamu akan menemukan opsi untuk mengatur otentikasi username dan password.

### 5. Uji Koneksi Dengan Dengan MQTT.Cool
1. Buka Situs Test Client
   Kunjungi https://testclient-cloud.mqtt.cool/ menggunakan browser.

2. Masukkan Informasi Broker MQTT
   Setelah halaman terbuka, isi informasi koneksi broker yang relevan di antarmuka web:
   
   * Broker Address: Masukkan hostname atau alamat IP dari broker HiveMQ Cloud kamu. Misalnya, `your_hivemq_cluster_host`.
   * Port: Gunakan 8883, yang merupakan port standar untuk koneksi MQTT over TLS/SSL.
   * Client ID: Buat Client ID unik. Misalnya, `TestClient-12345`.
   * Username dan Password: Jika HiveMQ mengharuskan autentikasi, masukkan username dan password yang telah dikonfigurasi.
     
Aktifkan opsi untuk SSL/TLS dengan mencentang atau memilih opsi yang sesuai (biasanya berupa checkbox atau pilihan yang diberi label Enable SSL atau Use TLS). Ini memastikan bahwa koneksi ke broker HiveMQ menggunakan enkripsi.

![Screenshot 2024-11-09 194808](https://github.com/user-attachments/assets/ae554ad8-3c07-42e6-8780-1978a56a86f7)


3. Connection Settings
   
Pada navigasi Web client isi username dan password sesuai dengan Credential yang sudah dibuat pada autentification. Buatlah topik yang misalnya`Test` kemudian subcribe dan ubah Qos menjadi 2. 

![Screenshot 2024-11-09 200002](https://github.com/user-attachments/assets/1dd31ed6-2741-43ff-ae31-be3509f054cd)


setelah itu klik tombol connect untuk mengaktifkan koneksi broker.

4. Connect to Broker

Klik Connect atau tombol sejenis untuk mencoba terhubung ke broker HiveMQ. Jika semua konfigurasi sudah benar, klien testclient-cloud.mqtt.cool akan berhasil terhubung ke broker melalui TLS/SSL, dan status akan menunjukkan bahwa kamu terhubung.

![Screenshot 2024-11-09 200128](https://github.com/user-attachments/assets/bbb4531b-0fa0-4c02-bee1-23e4b2506b8e)


