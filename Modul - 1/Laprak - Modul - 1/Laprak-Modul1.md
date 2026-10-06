# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Amanda Septiana Salsabila - 109082500145</p>

## Dasar Teori
Struktur data adalah cara menyimpan, mengorganisasikan, dan mengelola data di dalam memori komputer agar data tersebut dapat digunakan secara efisien [1]. Sebelum mempelajari struktur data yang lebih kompleks, pemahaman mengenai lingkungan pengembangan (IDE) serta dasar-dasar bahasa pemrograman C++ sangat diperlukan. Modul ini membahas penggunaan Code Blocks IDE serta konsep dasar C++ seperti variabel, operator, dan struktur kontrol yang menjadi fondasi dalam pembuatan program [2].

### A. Pengenalan Code Blocks IDE
Code Blocks adalah aplikasi IDE (Integrated Development Environment) yang bersifat gratis, open-source, dan dapat berjalan di berbagai sistem operasi. Aplikasi ini umumnya digunakan untuk mengembangkan program berbasis bahasa C, C++, dan Fortran [1].
1. Instalasi Code Blocks dilakukan dengan mengunduh file installer dari situs resminya. Disarankan untuk memilih versi yang sudah menyertakan mingw-setup agar compiler GCC sudah terinstal secara otomatis dan program bisa langsung dijalankan [1].
2. Penggunaan Code Blocks dapat dimulai dengan membuat project baru (Console application) atau membuat file source code baru. Setelah kode ditulis, program dapat dikompilasi menggunakan tombol Build (Ctrl+F9) dan dijalankan dengan Run (Ctrl+F10) [2].
3. Jika terjadi error saat menjalankan program padahal kode sudah benar, kita dapat menggunakan fitur Clean. Caranya dengan klik kanan pada nama project lalu pilih Clean untuk menghapus file build lama yang mungkin menyebabkan konflik [1].

### B. Dasar Pemrograman C++
Bahasa C++ dikembangkan dari bahasa C dan merupakan bahasa pemrograman yang sangat populer karena mendukung pemrograman berorientasi objek serta memiliki eksekusi yang cepat [2].
1. Struktur dasar program C++ selalu diawali dengan pemanggilan library menggunakan #include, misalnya `#include <iostream>`. Setelah itu terdapat fungsi utama int main() yang menjadi titik awal eksekusi program dan diakhiri dengan return 0; [1].
2. Identifier adalah nama yang dibuat oleh programmer untuk variabel, fungsi, atau konstanta. Aturan penulisannya harus diawali dengan huruf atau underscore, tidak boleh menggunakan spasi, dan C++ bersifat case-sensitive (huruf besar dan kecil dianggap berbeda) [2].
3. Tipe data dasar di C++ digunakan untuk menentukan jenis nilai yang akan disimpan. Beberapa tipe data yang umum digunakan adalah int untuk bilangan bulat, float dan double untuk bilangan desimal, serta char untuk karakter [1].

### C. Variabel, Konstanta, dan Input/Output
Dalam membuat program, kita membutuhkan tempat untuk menyimpan data dan cara untuk berinteraksi dengan pengguna.
1. Variabel digunakan untuk menyimpan nilai yang bisa berubah-ubah saat program berjalan, sedangkan konstanta (ditambahkan kata kunci const di depannya) digunakan untuk menyimpan nilai yang tetap dan tidak dapat diubah [2].
2. Untuk menampilkan output ke layar, kita menggunakan fungsi cout dari library iostream. Tampilan output juga bisa diatur menggunakan escape sequence seperti \n untuk ganti baris atau \t untuk tabulasi [1].
3. Untuk menerima inputan dari keyboard, kita menggunakan fungsi cin. Fungsi ini akan membaca nilai yang diketik oleh pengguna dan menyimpannya ke dalam variabel yang telah ditentukan [2].

### D. Operator dan Struktur Kontrol
Program tidak hanya berjalan lurus dari atas ke bawah, tetapi alurnya dapat diatur berdasarkan kondisi atau perulangan tertentu.
1. Operator adalah simbol yang digunakan untuk melakukan operasi pada data. C++ menyediakan berbagai jenis operator, seperti operator aritmatika (+, -, *, /), operator logika (&&, ||), dan operator increment/decrement (++, --) [1].
2. Struktur kontrol kondisional digunakan untuk mengambil keputusan di dalam program. Kita bisa menggunakan pernyataan if-else untuk kondisi yang sederhana, atau switch-case jika terdapat banyak pilihan kondisi [2].
3. Perulangan (looping) digunakan untuk mengeksekusi blok kode yang sama secara berulang-ulang tanpa harus menuliskannya berkali-kali. C++ menyediakan tiga jenis perulangan, yaitu for, while, dan do-while [1].

### E. Struktur (Struct)
Selain tipe data bawaan, C++ memungkinkan programmer untuk membuat tipe data bentukan agar pengelolaan data lebih rapi.
1. Struct (struktur) adalah cara untuk mengelompokkan beberapa variabel yang memiliki tipe data berbeda ke dalam satu nama kesatuan. Misalnya, menggabungkan variabel nama dan nilai ke dalam satu struct "DataSiswa" [2].
2. Untuk mengakses isi atau field di dalam struct, kita menggunakan tanda titik (.). Contohnya, jika kita memiliki variabel struct bernama siswa, kita bisa mengakses namanya dengan menulis siswa.nama [1].
3. Struct sering dikombinasikan dengan array untuk menyimpan banyak data sekaligus. Contohnya, membuat array of struct untuk menampung data dari puluhan siswa dalam satu variabel array [2].

## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Masukkan bilangan pertama : ";
    cin >> a;
    cout << "Masukkan bilangan kedua : ";
    cin >> b;

    cout << "\nHasil operasi : " << endl;
    cout << "Penjumlahan : " << a << " + " << b << " = " << a + b << endl;
    cout << "Pengurangan : " << a << " - " << b << " = " << a - b << endl;
    cout << "Perkalian : " << a << " * " << b << " = " << a * b << endl;

    if (b != 0) {
        cout << "Pembagian : " << a << " / " << b << " = " << a / b << endl;
    } else {
        cout << "Pembagian : Tidak dapat dibagi dengan nol!" << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%201/Unguided/Unguided%20-%201/Screenshot%202026-09-28%20172752.png?raw=true)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%201/Unguided/Unguided%20-%201/Screenshot%202026-09-28%20172855.png?raw=true)

Program ini berfungsi untuk menghitung operasi aritmatika dari dua bilangan float. Program dimulai dengan membuat variabel a dan b bertipe float, lalu meminta user menginputkan angkanya lewat cin. Setelah itu, program langsung menampilkan hasil penjumlahan, pengurangan, dan perkalian. Khusus untuk pembagian, ada pengecekan menggunakan if-else untuk memastikan angka pembagi (b) tidak nol, agar program tidak error. 

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100

```C++
#include <iostream>
using namespace std;

int main() {
    int angka;
    cout << "Masukkan angka (0-100) : ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka di luar jangkauan!" << endl;
        return 1;
    }

    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};

    if (angka == 0) {
        cout << "nol" << endl;
    } else if (angka == 100) {
        cout << "seratus" << endl;
    } else if (angka < 10) {
        cout << satuan[angka] << endl;
    } else if (angka == 10) {
        cout << "sepuluh" << endl;
    } else if (angka < 20) {
        if (angka == 11) {
            cout << "sebelas" << endl;
        } else {
            cout << satuan[angka - 10] << "belas" << endl;
        }
    } else {
        int puluh = angka / 10;
        int satu  = angka % 10;

        cout << satuan[puluh] << " puluh";
        if (satu > 0) {
            cout << " " << satuan[satu];
        }
        cout << endl;
    }


    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%201/Unguided/Unguided%20-%202/Screenshot%202026-09-28%20173118.png?raw=true)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%201/Unguided/Unguided%20-%202/Screenshot%202026-09-28%20173137.png?raw=true)

Program ini berfungsi untuk mengubah angka bulat 0 sampai 100 menjadi bentuk tulisan. Awalnya program meminta input dari user dan mengecek apakah angkanya berada di luar rentang 0-100. Jika valid, program menggunakan array string satuan untuk menyimpan teks angka 1 sampai 9. Setelah itu, program menggunakan percabangan if-else untuk memproses angka. Angka 0, 10, dan 100 dicetak secara langsung, sedangkan angka di bawah 10 diambil dari array satuan. Untuk angka 11 sampai 19, program mengambil teks dari array lalu menambahkan akhiran "belas". Terakhir, untuk angka 20 sampai 99, program menggunakan operator pembagian (/) untuk mendapatkan nilai puluhan dan modulus (%) untuk nilai satuan, kemudian menggabungkan keduanya menjadi satu kalimat.

### 3. Buatlah program yang dapat memberikan input dan output sbb.

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input : ";
    cin >> n;
    
    cout << "output :" << endl;
    
    for (int i = 0; i <= n; i++) {
        for (int s = 0; s < i * 2; s++) {
            cout << " ";
        }
        
        int angka = n - i;
        
        for (int j = angka; j >= 1; j--) {
            if (j != angka || i > 0) cout << " ";
            cout << j;
        }
        
        if (angka > 0) cout << " ";
        cout << "*";
        
        for (int j = 1; j <= angka; j++) {
            cout << " " << j;
        }
        
        cout << endl;
    }
    
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%201/Unguided/Unguided%20-%203/Screenshot%202026-09-28%20173255.png?raw=true)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%201/Unguided/Unguided%20-%203/Screenshot%202026-09-28%20173320.png?raw=true)

Program ini digunakan untuk membuat pola angka berbentuk cermin sesuai inputan user. Pertama, program meminta input nilai n, lalu menggunakan perulangan for bersarang untuk mengatur spasi di awal setiap baris supaya polonya rapi. Di setiap baris, program menentukan angka tertinggi yang akan dicetak (n - i), kemudian mencetak angka secara menurun hingga 1, diikuti tanda bintang (*) di tengah, dan diakhiri mencetak angka secara menaik dari 1. Perulangan ini terus berjalan sampai angka tertingginya habis, di mana baris terakhir hanya akan menampilkan tanda bintang saja.


## Kesimpulan
Praktikum Modul 1 membahas penggunaan Code Blocks IDE untuk menulis, mengompilasi, dan menjalankan program C++, termasuk cara mengatasi error dengan fitur Clean. Selain itu, dipelajari pula dasar-dasar C++ seperti tipe data, operator, percabangan, dan perulangan. Pemahaman teori ini diimplementasikan langsung melalui tiga latihan. Latihan pertama menguji tipe data float dan logika if-else untuk mencegah error pembagian dengan nol. Latihan kedua mengasah logika percabangan dan array untuk mengonversi angka menjadi tulisan. Sedangkan latihan ketiga melatih perulangan bersarang (nested loop) untuk membuat pola cermin (mirror). Secara keseluruhan, modul ini berhasil membangun fondasi logika pemrograman dan penguasaan IDE yang krusial sebelum mempelajari struktur data yang lebih kompleks di modul selanjutnya.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.