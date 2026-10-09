# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Amanda Septiana Salsabila - 109082500145</p>

## Dasar Teori
Abstract Data Type (ADT) adalah sebuah TYPE beserta sekumpulan PRIMITIF (operasi dasar) terhadap type tersebut. ADT yang lengkap juga menyertakan definisi invarian dari type dan aksioma yang berlaku, dan ADT merupakan definisi yang bersifat statik [1].

### A. Abstract Data Type (ADT)<br/>
#### 1. Definisi ADT
ADT terdiri dari TYPE dan sekumpulan PRIMITIF terhadap type tersebut. Selain itu, ADT yang lengkap menyertakan definisi invarian dari type dan aksioma yang berlaku [1]. ADT juga dapat didefinisikan sebagai model matematika dari objek data yang menyempurnakan tipe data dengan cara mengaitkannya dengan fungsi-fungsi yang beroperasi pada data tersebut [2]. Bahasa pemrograman memiliki tipe data bawaan (built-in) dan tipe bentukan pemrogram (User Defined Type), misalnya record pada Pascal, struct pada C, dan class pada Java. ADT memperluas konsep tipe bentukan tersebut dengan menambahkan enkapsulasi, yaitu penggabungan sifat-sifat data dengan operasi yang dapat dilakukan terhadapnya [2].
#### 2. ADT di dalam ADT
Definisi type dari sebuah ADT dapat mengandung definisi ADT lain. Contohnya, ADT waktu terdiri dari ADT JAM dan ADT DATE, sebuah garis terdiri dari dua buah ADT POINT, dan sebuah SEGI4 terdiri dari pasangan dua buah POINT (Top, Left) dan (Bottom, Right) [1].
#### 3. TYPE dan PRIMITIF dalam Bahasa Pemrograman
TYPE diterjemahkan menjadi type yang terdefinisi dalam bahasa yang bersangkutan. Jika dalam bahasa C digunakan struct, maka PRIMITIF dalam konteks prosedural diterjemahkan menjadi fungsi atau prosedur [1]. Pada C++, TYPE diwujudkan sebagai tipe data bentukan (user defined data type) berupa record yang disusun oleh satu atau lebih field dan dideklarasikan dengan kata kunci struct. Nama record kemudian menjadi nama tipe baru [3]. PRIMITIF diwujudkan sebagai modul program berupa prosedur atau fungsi. Prosedur dapat mengembalikan atau tidak mengembalikan nilai, sedangkan fungsi wajib mengembalikan nilai keluaran [3]. Pemecahan program menjadi modul-modul kecil seperti ini membuat program lebih mudah dibaca dan kesalahan yang terjadi bersifat lokal [3].

### B. Primitif dan Implementasi ADT<br/>
#### 1. Jenis-Jenis Primitif
Primitif dikelompokkan menjadi sembilan jenis [1] :
- Konstruktor/kreator, yang membentuk nilai type. Semua objek (variabel) bertype tersebut harus melalui konstruktor, dan namanya biasanya diawali Make.
- Selector, untuk mengakses komponen type (biasanya diawali Get).
- Prosedur pengubah nilai komponen.
- Validator komponen, untuk menguji apakah komponen dapat membentuk type sesuai batasan.
- Destruktor/dealokator, untuk menghancurkan nilai objek/variabel sekaligus memori penyimpanannya.
- Baca/tulis, sebagai antarmuka dengan perangkat input/output.
- Operator relasional, untuk mendefinisikan lebih besar, lebih kecil, sama dengan, dan sebagainya.
- Aritmatika terhadap type tersebut, karena aritmatika pada bahasa C hanya terdefinisi untuk bilangan numerik.
- Konversi dari type tersebut ke tipe dasar dan sebaliknya.
#### 2. Struktur Implementasi ADT
ADT biasanya diimplementasikan menjadi dua modul utama dan satu modul antarmuka program utama (driver) [1] :
- Definisi/spesifikasi type dan primitif (header fungsi) pada file .h.
- Body/realisasi dari primitif pada file .cpp.
- Driver, yaitu program utama (main.cpp) yang menggunakan ADT tersebut.
#### 3. Spesifikasi dan Realisasi Primitif
Pada file .h, spesifikasi type mengikuti kaidah bahasa yang dipakai. Spesifikasi primitif mengikuti kaidah dalam konteks prosedural: untuk fungsi dituliskan nama, domain, range, dan prekondisi jika ada, sedangkan untuk prosedur dituliskan initial state, final state, dan proses yang dilakukan [1]. Pada file .cpp, realisasi primitif berupa kode program dalam bahasa yang bersangkutan (dalam praktikum ini, C++), dan realisasi fungsi serta prosedur sebaiknya memanfaatkan selector dan konstruktor sebisa mungkin [1]. Untuk menerapkan konsep ADT, deklarasi tipe, variabel, dan fungsi dipisahkan ke dalam file .h, sedangkan definisi fungsinya dipisahkan ke file .cpp [1].

## Guided 

### 1. Mahasiswa
#### a. mahasiswa.h

```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs (mahasiswa &m) ;
float rata2 (mahasiswa m) ;
#endif //MAHASISWA_H_INCLUDED
```
#### b. mahasiswa.cpp
```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "input nim = ";
    cin >> (m).nim;
    cout << "input nilai 1 = ";
    cin >> (m).nilai1;
    cout << "input nilai 2 = ";
    cin >> (m).nilai2;
}

float rata2(mahasiswa m) {
    return float(m.nilai1+m.nilai2)/2;
}
```
#### c. main.cpp
```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() 
{
    mahasiswa mhs;
    inputMhs (mhs) ;
    cout << "rata-rata = " << rata2 (mhs) ;
    return 0;
}
```
Program ini menerapkan konsep Abstract Data Type dengan memisahkan kode menjadi tiga file agar lebih terstruktur dan modular. File mahasiswa.h berfungsi sebagai spesifikasi yang mendefinisikan tipe data struct mahasiswa beserta prototipe fungsinya. File mahasiswa.cpp berisi realisasi logika di mana fungsi inputMhs menggunakan mekanisme referensi agar data asli berubah dan fungsi rata2 menggunakan mekanisme nilai untuk menghitung rata-rata. Terakhir file main.cpp bertindak sebagai program utama yang membuat variabel mhs lalu memanggil fungsi input dan menampilkan hasil perhitungan sehingga alur eksekusi program sesuai kaidah pemisahan antarmuka dan implementasi ADT.

## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3 * uts + 0.4 * uas + 0.3 * tugas.
#### a. mahasiswa.h

```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa{
    char nama[50];
    char nim[16];
    int uts, uas, tugas;
    float nilaiAkhir;
};

void inputMhs (mahasiswa &m) ;

float hitungNilaiAkhir (mahasiswa m) ;

void tampilMhs (mahasiswa m) ;

#endif 
```
#### b. mahasiswa.cpp
```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "input nama = ";
    cin >> (m).nama;
    cout << "input nim = ";
    cin >> (m).nim;
    cout << "input uts = ";
    cin >> (m).uts;
    cout << "input uas = ";
    cin >> (m).uas;
    cout << "input tugas = ";
    cin >> (m).tugas;
    (m).nilaiAkhir = hitungNilaiAkhir(m);
}

float hitungNilaiAkhir(mahasiswa m) {
    return 0.3*m.uts + 0.4*m.uas + 0.3*m.tugas;
}

void tampilMhs(mahasiswa m) {
    cout << "nama = " << m.nama << endl;
    cout << "nim = " << m.nim << endl;
    cout << "uts = " << m.uts << endl;
    cout << "uas = " << m.uas << endl;
    cout << "tugas = " << m.tugas << endl;
    cout << "nilai akhir = " << m.nilaiAkhir << endl;
}
```
#### c. main.cpp
```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main()
{
    mahasiswa mhs[10];
    int n;

    do {
        cout << "jumlah mahasiswa (max 10) = ";
        cin >> n;
    } while (n < 1 || n > 10);

    for (int i = 0; i < n; i++) {
        cout << endl << "data mahasiswa ke-" << i+1 << endl;
        inputMhs (mhs[i]) ;
    }

    cout << endl << "=== DATA MAHASISWA ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << endl << "mahasiswa ke-" << i+1 << endl;
        tampilMhs (mhs[i]) ;
    }
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%203/Unguided/Unguided%20-%201/Screenshot%202026-10-09%20000339.png?raw=true)
![Screenshot Output Unguided 1_1](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%203/Unguided/Unguided%20-%201/Screenshot%202026-10-09%20000405.png?raw=true)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%203/Unguided/Unguided%20-%201/Screenshot%202026-10-09%20000726.png?raw=true)
![Screenshot Output Unguided 1_2](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%203/Unguided/Unguided%20-%201/Screenshot%202026-10-09%20000740.png?raw=true)

Program ini menerapkan konsep ADT dengan memisahkan kode menjadi tiga file. File mahasiswa.h berisi type struct mahasiswa dan header primitif inputMhs, hitungNilaiAkhir, dan tampilMhs. File mahasiswa.cpp berisi isi dari primitif tersebut, yaitu membaca data mahasiswa dari keyboard, menghitung nilai akhir dengan rumus `0.3*uts + 0.4*uas + 0.3*tugas`, dan menampilkan data beserta nilai akhirnya. File main.cpp bertugas sebagai driver yang meminta jumlah mahasiswa (maksimal 10), menyimpan datanya dalam array, lalu menampilkan seluruh data tersebut. 

### 2. Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h”:
```C++
Type pelajaran <
namaMapel : string
kodeMapel : string
>
function create_pelajaran( namapel : string,
 kodepel : string ) → pelajaran
procedure tampil_pelajaran( input pel : pelajaran )
```
### Buatlah implementasi ADT pelajaran pada file “pelajaran.cpp”
### Cobalah hasil implementasi ADT pada file “main.cpp”
```C++
using namespace std;
int main(){
string namapel = "Struktur Data";
string kodepel = "STD";
pelajaran pel = create_pelajaran(namapel,kodepel);
tampil_pelajaran(pel);
return 0;
}
```
### Contoh output hasil:
```C++
nama pelajaran : Struktur Data
nilai : STD
```

#### a. pelajaran.h
```C++
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>
using namespace std;

struct pelajaran{
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran (string namapel, string kodepel) ;

void tampil_pelajaran (pelajaran pel) ;

#endif 
```
#### b. pelajaran.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```
#### c. main.cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main(){
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel,kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%203/Unguided/Unguided%20-%202/Screenshot%202026-10-09%20001151.png?raw=true)

Program ini menerapkan konsep ADT dengan memisahkan kode menjadi tiga file. File pelajaran.h berisi type struct pelajaran yang menyimpan namaMapel dan kodeMapel, beserta header dua primitif yaitu create_pelajaran dan tampil_pelajaran. File pelajaran.cpp berisi isi dari primitif tersebut. Fungsi create_pelajaran berperan sebagai konstruktor yang membentuk data pelajaran dari nama dan kode yang diberikan, sedangkan prosedur tampil_pelajaran menampilkan nama dan kode pelajaran ke layar. File main.cpp bertugas sebagai driver yang membuat data pelajaran “Struktur Data” dengan kode “STD” lalu menampilkannya.

### 3. Buatlah program dengan ketentuan :
### - 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
### - fungsi/prosedur yang menampilkan isi sebuah array integer 2D
### - fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
### - fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

#### a. array2d.h
```C++
#ifndef ARRAY2D_H_INCLUDED
#define ARRAY2D_H_INCLUDED

void tampilArray (int a[3][3]) ;

void tukarArray (int a[3][3], int b[3][3], int baris, int kolom) ;

void tukarPointer (int *p1, int *p2) ;

#endif 
```
#### b. array2d.cpp
```C++
#include <iostream>
#include "array2d.h"
using namespace std;

void tampilArray(int a[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray(int a[3][3], int b[3][3], int baris, int kolom) {
    int temp = a[baris][kolom];
    a[baris][kolom] = b[baris][kolom];
    b[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
```
#### c. main.cpp
```C++
#include <iostream>
#include "array2d.h"
using namespace std;

int main()
{
    int A[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int B[3][3] = {{9,8,7},{6,0,4},{3,2,1}};
    int x = 10, y = 20;
    int *p1 = &x;
    int *p2 = &y;
    int baris, kolom;

    cout << "array A" << endl;
    tampilArray (A) ;
    cout << "array B" << endl;
    tampilArray (B) ;

    cout << "tukar posisi (baris kolom, 0-2) = ";
    cin >> baris >> kolom;
    if (baris >= 0 && baris <= 2 && kolom >= 0 && kolom <= 2) {
        tukarArray (A, B, baris, kolom) ;
        cout << "setelah ditukar" << endl;
        cout << "array A" << endl;
        tampilArray (A) ;
        cout << "array B" << endl;
        tampilArray (B) ;
    } else {
        cout << "posisi tidak valid" << endl;
    }

    cout << "sebelum tukar pointer : x = " << *p1 << ", y = " << *p2 << endl;
    tukarPointer (p1, p2) ;
    cout << "sesudah tukar pointer : x = " << *p1 << ", y = " << *p2 << endl;
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%203/Unguided/Unguided%20-%203/Screenshot%202026-10-09%20001407.png?raw=true)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%203/Unguided/Unguided%20-%203/Screenshot%202026-10-09%20001508.png?raw=true)

Program ini menerapkan konsep ADT dengan memisahkan kode menjadi tiga file. File array2d.h berisi header primitif tampilArray, tukarArray, dan tukarPointer. File array2d.cpp berisi isinya, yaitu menampilkan array 2D berukuran 3x3, menukar elemen pada posisi tertentu antara dua array, dan menukar isi dua variabel melalui pointer. File main.cpp bertugas sebagai driver yang menampilkan dua array, menukar elemen sesuai baris dan kolom yang diinput, lalu menukar nilai x dan y lewat pointer.

## Kesimpulan
Dari praktikum Modul 3, dapat disimpulkan bahwa Abstract Data Type (ADT) adalah cara menyusun program dengan menggabungkan sebuah type dan primitif (operasi dasar) terhadap type tersebut. Penerapannya dalam C++ dilakukan dengan memisahkan program menjadi tiga bagian, yaitu file .h untuk type dan header primitif, file .cpp untuk isi primitif, dan main.cpp sebagai driver. Pada latihan pertama, ADT mahasiswa dipakai untuk menyimpan data dalam array dan menghitung nilai akhir dengan fungsi. Pada latihan kedua, ADT pelajaran memperlihatkan penggunaan konstruktor dan prosedur tampil. Pada latihan ketiga, array 2D dan pointer dipakai untuk menukar isi data. Dengan pemisahan ini, program menjadi lebih terstruktur, mudah dibaca, mudah diperbaiki, dan primitifnya bisa dipakai ulang dengan data yang berbeda. Praktikum ini juga menunjukkan bahwa program yang terdiri dari beberapa file harus dikompilasi bersama agar dapat dijalankan.

## Referensi
[1] Modul 3: ABSTRACT DATA TYPE (ADT). Modul Praktikum Struktur Data. (Referensi Modul). 
<br>[2] Triase, Diktat Struktur Data, Universitas Islam Negeri Sumatera Utara, 2020. Diakses melalui http://repository.uinsu.ac.id/9717/2/Diktat%20Struktur%20Data.pdf
<br>[3] Indahyanti, Uce., Rahmawati, Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
