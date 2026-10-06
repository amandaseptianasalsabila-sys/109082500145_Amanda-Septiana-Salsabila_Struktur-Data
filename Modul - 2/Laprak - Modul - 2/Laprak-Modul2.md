# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Amanda Septiana Salsabila - 109082500145</p>

## Dasar Teori

### A. Array<br/>
Array merupakan kumpulan data dengan nama yang sama dan setiap elemennya bertipe data sama. Untuk mengakses setiap komponen atau elemen array, digunakan indeks dari setiap elemen tersebut[1].
1. Array Satu Dimensi : Array yang hanya terdiri dari satu larik data saja. Cara pendeklarasian array satu dimensi adalah tipe_data nama_var[ukuran], di mana tipe_data menyatakan jenis elemen array dan ukuran menyatakan jumlah maksimum array. Dalam C++, data array disimpan dalam memori pada lokasi yang berurutan, di mana elemen pertama memiliki indeks 0 dan elemen selanjutnya memiliki indeks 1 dan seterusnya[1].
2. Array Dua Dimensi : Bentuk array dua dimensi mirip seperti tabel dan dapat digunakan untuk menyimpan data dalam bentuk tabel. Array ini terbagi menjadi dua bagian, yaitu dimensi pertama dan dimensi kedua. Cara akses, deklarasi, inisialisasi, dan menampilkan datanya sama dengan array satu dimensi, hanya saja indeks yang digunakan ada dua[1].
3. Array Berdimensi Banyak : Array yang mempunyai indeks banyak, lebih dari dua. Indeks inilah yang menyatakan dimensi array. Array berdimensi banyak lebih sulit dibayangkan, sejalan dengan jumlah dimensi dalam array[1].

### B. Pointer<br/>
Pointer merupakan variabel dasar yang berisi integer dalam format heksadesimal dan digunakan untuk menyimpan alamat memori variabel lain, sehingga pointer dapat mengakses nilai dari variabel yang alamatnya ditunjuk[1].
1. Data dan Memori : Semua data yang digunakan oleh program komputer disimpan di dalam memori (RAM). Memori dapat digambarkan sebagai sebuah array 1 dimensi yang berukuran sangat besar, di mana setiap cell memory memiliki “indeks” atau “alamat” unik yang biasa disebut sebagai “address”. Saat program berjalan, Sistem Operasi (OS) akan mengalokasikan space memory untuk setiap variabel. Untuk mengetahui alamat memori tempat suatu variabel dialokasikan, digunakan keyword & yang ditempatkan di depan nama variabel[1].
2. Pointer dan Alamat : Cara pendeklarasian variabel pointer adalah type *nama_variabel. Agar suatu pointer menunjuk ke variabel lain, pointer harus diisi dengan alamat memori yang ditunjuk. Untuk mendapatkan nilai dari variabel yang ditunjuk pointer, digunakan tanda * di depan nama variabel pointer. Pointer juga merupakan variabel biasa, sehingga pointer juga akan menggunakan space memory dan memiliki alamat sendiri[1].
3. Pointer dan Array : Terdapat keterhubungan yang kuat antara array dan pointer. Nama array merepresentasikan alamat dari elemen pertama array. Jika pa merupakan pointer yang menunjuk ke elemen tertentu dari array, maka pa + i akan menunjuk elemen ke-i setelah pa, dan *(pa + i) akan mengandung isi dari elemen a[i][1].
4. Pointer dan String : Dalam bahasa C++, string pada dasarnya merupakan kumpulan dari karakter atau array dari karakter yang diakhiri dengan karakter NULL '\0'. Untuk mengakses string digunakan pointer karakter, di mana standar input/output akan menerima pointer dari awal karakter array[1].

### C. Fungsi dan Prosedur<br/>
Dalam pemrograman terstruktur, program yang kompleks perlu dipecah menjadi modul-modul kecil atau subprogram agar mudah dipahami, diuji, dan dikembangkan[2]. Fungsi merupakan blok dari kode yang dirancang untuk melaksanakan tugas khusus dengan tujuan program menjadi terstruktur serta dapat mengurangi pengulangan kode (duplikasi kode) sehingga menghemat ukuran program[1].
1. Fungsi : Pada umumnya fungsi memerlukan masukan yang dinamakan sebagai parameter dan menghasilkan sebuah nilai (nilai balik fungsi). Bentuk umum sebuah fungsi adalah tipe_keluaran nama_fungsi(daftar_parameter) { blok pernyataan fungsi; }[1].
2. Prosedur : Dalam bahasa pemrograman C++, prosedur merujuk pada fungsi yang tidak mengembalikan nilai (return value) kepada pemanggilnya. Dalam istilah C++, prosedur ini dikenal sebagai fungsi void. Bentuk umum sebuah prosedur adalah void nama_prosedur(daftar_parameter) { blok pernyataan prosedur; }[1].

### D. Parameter Fungsi<br/>
Parameter fungsi terbagi menjadi parameter formal (variabel yang ada pada daftar parameter ketika mendefinisikan fungsi) dan parameter aktual (parameter yang dipakai untuk memanggil fungsi). Parameter aktual tidak harus berupa variabel, melainkan bisa berupa konstanta atau ungkapan[1].
1. Pemanggilan dengan Nilai (Call by Value) : Pada pemanggilan dengan nilai, nilai dari parameter aktual akan disalin ke dalam parameter formal. Parameter aktual tidak akan berubah meskipun parameter formalnya berubah[1].
2. Pemanggilan dengan Pointer (Call by Pointer) : Pemanggilan dengan pointer merupakan cara untuk melewatkan alamat suatu variabel ke dalam suatu fungsi menggunakan operator &. Dengan cara ini, fungsi dapat mengubah nilai dari variabel aktual yang dilewatkan ke dalam fungsi karena yang diproses adalah alamat memorinya[1].
3. Pemanggilan dengan Referensi (Call by Reference) : Pemanggilan dengan referensi juga merupakan cara untuk melewatkan alamat suatu variabel ke dalam fungsi. Namun, operator & diletakkan pada deklarasi parameter formal (misal: int &x). Cara ini dapat mengubah nilai variabel aktual yang ada di luar fungsi tanpa perlu menambahkan operator tambahan saat pemanggilan fungsi[1].

## Guided 

### 1. Array

```C++
#include <iostream>
using namespace std;

int main(){
    int nilai[5];

    nilai[0]= 80;
    nilai[1]= 75;
    nilai[2]= 90;
    nilai[3]= 85;
    nilai[4]= 95;

    for (int i = 0;i<5;i++) {
        cout<<"Nilai ke-"<< i+1<<" = "<<nilai[i]<<endl;
    }

    return 0;
}
```
Program ini mendeklarasikan array integer nilai berukuran 5 elemen, mengisi secara manual dengan data (80, 75, 90, 85, 95), lalu menampilkan seluruh isi array ke layar menggunakan perulangan for dengan format "Nilai ke-X = Y".


### 2. Array 2D

```C++
#include <iostream>
using namespace std;

int main(){
    int nilai[3][3] = {
        {80,75,90},
        {85,90,88},
        {70,80,85}
    };
        // Print array 2 dimensi
    for (int i = 0;i<3;i++) {
        for (int j = 0;j<3;j++) {
            cout << nilai [i][j]<<" ";
        }

        cout << endl;
    }
    cout<<endl;
    cout<<nilai[1][2]<<endl; // menghasilkan baris ke 1, kolom ke 2 = 88 (ingat baris dan kolom dimulai dari 0)
    return 0;
}
```
Program ini menginisialisasi array 2D (matriks) 3x3 bernama nilai dengan data langsung, mencetak seluruh isinya baris demi baris menggunakan perulangan for bersarang, lalu menampilkan elemen spesifik nilai[1][2] (bernilai 88) untuk mendemonstrasikan bahwa pengindeksan array dalam C++ dimulai dari angka 0.

### 3. Array 3D

```C++
#include <iostream>
using namespace std;

int main(){

    //Format array 3 dimensi : nama_array[jumlah array 2D][jumlah baris setiap array 2D][kolom baris setiap array 2D]
    int data[2][2][3] = {
        {
            {10,20,30},
            {40,50,60}
        },
        {
            {70,80,90},
            {100,110,120}
        }
    };

    cout<< data[0][1][2]<<endl;

    return 0;
}
```
Program ini mendeklarasikan array 3D berukuran [2][2][3] berisi data integer, lalu mencetak elemen spesifik pada indeks [0][1][2] (yang bernilai 60) untuk mendemonstrasikan cara pengaksesan data pada array berdimensi banyak dengan pengindeksan yang dimulai dari angka 0.

### 4. Function

```C++
#include <iostream>
using namespace std;

int maks3(int a,int b,int c) {
    int temp_max = a;

    if (b>temp_max) {
        temp_max = b;
    }
    if (c>temp_max) {
        temp_max = c;
    }

    return temp_max;
}

int main(){
    int x,y,z;

    cout<<"Masukan nilai 1 : ";
    cin>>x;

    cout<<"Masukan nilai 2 : ";
    cin>>y;

    cout<<"Masukan nilai 3 : ";
    cin>>z;

    cout<<"Nilai Maksimum: "<< maks3(x,y,z);

    return 0;
}
```
Program ini menggunakan fungsi maks3() yang menerima tiga parameter integer, membandingkannya secara berurutan menggunakan variabel temp_max dan kondisi if, lalu mengembalikan nilai tertinggi untuk ditampilkan di fungsi main() setelah pengguna menginputkan tiga bilangan.

### 5. Procedure

```C++
#include <iostream>
using namespace std;

void sapa(){
    cout<<"Selamat datang di Praktikum Struktur data" << endl;
}

int main(){
    sapa();
    return 0;
}
```
Program ini mendeklarasikan prosedur void bernama sapa() untuk mencetak pesan selamat datang, lalu memanggil prosedur tersebut di dalam fungsi main().

### 6. Pointer 1

```C++
#include <iostream>
using namespace std;

int main(){
    int angka = 100;

    cout<<"Nilai variabel angka: "<< angka << endl;
    cout<<"Alamat variabel angka: "<< &angka << endl;

    return 0;
}
```
Program ini mendeklarasikan variabel angka bernilai 100, lalu mencetak nilai dan alamat memorinya menggunakan operator &.

### 7. Pointer 2

```C++
#include <iostream>
using namespace std;

int main(){
    int angka = 100;

    int *pointer;

    pointer = &angka;

    cout<<"Nilai angka  : "<<angka<<endl; //Nilai dari variabel angka yaitu 100
    cout<<"Alamat angka  : "<<&angka<<endl; //Alamat dari variabel angka
    cout<<"isi variabel pointer  : "<<pointer<<endl; //Alamat dari variabel angka
    cout<<"Nilai dari variabel pointer  : "<<*pointer<<endl;//Value dari variabel angka yaitu 100
}
```
Program ini mendeklarasikan variabel angka (bernilai 100) dan pointer yang menyimpan alamat memorinya (&angka). Program kemudian mencetak nilai asli angka, alamat memorinya, isi pointer (alamat memori), dan nilai yang ditunjuk oleh pointer (*pointer) yang menghasilkan angka 100.

### 8. Pointer Array

```C++
#include <iostream>
using namespace std;

int main(){
    char arr[6];

    arr[0]='a';
    arr[1]='b';
    arr[2]='c';
    arr[3]='b';
    arr[4]='d';
    arr[5]='e';

    cout<< arr[3]<<endl; //menampilkan value
    cout<< &(arr[4])<<endl; //menampilkan alamat value
}
```
Program ini menginisialisasi array karakter arr berukuran 6 elemen, lalu mencetak nilai pada indeks ke-3 (b) dan alamat memori elemen pada indeks ke-4 menggunakan operator &.

### 9. Call by Pointer Reference Value

```C++
#include <iostream>
using namespace std;

//BY POINTER
void tukar(int *x, int *y) {
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 4;
    int b = 6;

    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    tukar(&a, &b);

    cout << "\nSetelah ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}


// BY REFERENCE
// #include <iostream>
// using namespace std;

// void tukar(int &x, int &y) {
//     int temp;
//     temp = x;
//     x = y;
//     y = temp;
// }

// int main() {
//     int a = 4;
//     int b = 6;

//     cout << "Sebelum ditukar: " << endl;
//     cout << "a = " << a << endl;
//     cout << "b = " << b << endl;

//     tukar(a, b); 

//     cout << "\nSetelah ditukar: " << endl;
//     cout << "a = " << a << endl;
//     cout << "b = " << b << endl;
    
//     return 0;
// }

//BY VALUE
// #include <iostream>
// using namespace std;

// void tukar(int x, int y) {
//     int temp;
//     temp = x;
//     x = y;
//     y = temp;
// }

// int main() {
//     int a = 4;
//     int b = 6;

//     cout << "Sebelum ditukar: " << endl;
//     cout << "a = " << a << endl;
//     cout << "b = " << b << endl;

//     // Memanggil fungsi dengan mengirimkan nilainya saja
//     tukar(a, b);

//     // Hasil print di bawah ini angkanya akan tetap a = 4 dan b = 6
//     cout << "\nSetelah ditukar: " << endl;
//     cout << "a = " << a << endl;
//     cout << "b = " << b << endl;
    
//     return 0;
// }
```
Program ini mendemonstrasikan tiga cara pelewatan parameter di C++, yaitu Call by Pointer (aktif, mengubah nilai asli via alamat memori), Call by Reference (komentar, mengubah nilai asli via referensi langsung), dan Call by Value (komentar, hanya menyalin nilai sehingga nilai asli tidak berubah).

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 

```C++
#include <iostream>
#define MAX 3
using namespace std;

int main() {
    int i, j, k;
    int A[MAX][MAX], B[MAX][MAX];
    int jumlah[MAX][MAX], kurang[MAX][MAX], kali[MAX][MAX];

    cout << "Masukkan elemen matriks A (3x3)" << endl;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "\nMasukkan elemen matriks B (3x3)" << endl;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }
    }

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            jumlah[i][j] = A[i][j] + B[i][j];
            kurang[i][j] = A[i][j] - B[i][j];
        }
    }

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            kali[i][j] = 0;
            for (k = 0; k < MAX; k++)
                kali[i][j] = kali[i][j] + A[i][k] * B[k][j];
        }
    }

    cout << "\nHasil penjumlahan (A + B) :\n";
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++)
            cout << jumlah[i][j] << "\t";
        cout << "\n";
    }

    cout << "\nHasil pengurangan (A - B) :\n";
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++)
            cout << kurang[i][j] << "\t";
        cout << "\n";
    }

    cout << "\nHasil perkalian (A x B) :\n";
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++)
            cout << kali[i][j] << "\t";
        cout << "\n";
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%202/Unguided/Unguided%20-%201/Screenshot%202026-10-06%20135045.png?raw=true)
![Screenshot Output Unguided 1_1](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%202/Unguided/Unguided%20-%201/Screenshot%202026-10-06%20135102.png?raw=true)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%202/Unguided/Unguided%20-%201/Screenshot%202026-10-06%20135425.png?raw=true)
![Screenshot Output Unguided 1_2](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%202/Unguided/Unguided%20-%201/Screenshot%202026-10-06%20135444.png?raw=true)

Program ini melakukan operasi matriks 3x3 (penjumlahan, pengurangan, dan perkalian). Pertama, program meminta pengguna memasukkan elemen-elemen untuk matriks A dan B. Kemudian, program menghitung penjumlahan dan pengurangan dengan menjumlahkan/mengurangi elemen-elemen yang bersesuaian pada kedua matriks. Untuk perkalian matriks, program menggunakan tiga perulangan bersarang (i, j, k) untuk mengalikan baris matriks A dengan kolom matriks B sesuai aturan matematika matriks. Terakhir, program menampilkan hasil ketiga operasi tersebut dalam format tabel yang rapi. 

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel 

```C++
#include <iostream>
using namespace std;

void tukarPointer(int *x, int *y, int *z) {
    int temp;

    temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}

void tukarReference(int &x, int &y, int &z) {
    int temp;

    temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a = 4;
    int b = 6;
    int c = 8;

    cout << "Sebelum ditukar: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    tukarPointer(&a, &b, &c);

    cout << "\nSetelah ditukar Pointer: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    tukarReference(a, b, c);

    cout << "\nSetelah ditukar Reference: " << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%202/Unguided/Unguided%20-%202/Screenshot%202026-10-06%20232840.png?raw=true)

Program ini mendemonstrasikan penukaran (rotasi) nilai 3 variabel menggunakan dua metode, yaitu Call by Pointer (mengirim alamat memori & dan mengubah nilai via dereference *) dan Call by Reference (mengirim referensi langsung & pada parameter). Kedua fungsi melakukan rotasi nilai (A ke B, B ke C, C ke A) menggunakan variabel temp, yang secara langsung mengubah nilai variabel asli di fungsi main().

### 3. Diketahui sebuah array 1 dimensi sebagai berikut : arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini :
### --- Menu Program Array ---
### • Tampilkan isi array
### • cari nilai maksimum
### • cari nilai minimum
### • Hitung nilai rata - rata

```C++
#include <iostream>
#define MAX 10
using namespace std;

int cariMinimum(int *pa, int n);
int cariMaksimum(int *pa, int n);
void hitungRataRata(int *pa, int n);

int main() {
    int i;
    int pilihan;
    int arrA[MAX] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Isi array : ";
                for (i = 0; i < MAX; i++)
                    cout << arrA[i] << " ";
                cout << endl;
                break;
            case 2:
                cout << "Nilai maksimum = " << cariMaksimum(&arrA[0], MAX) << endl;
                break;
            case 3:
                cout << "Nilai minimum = " << cariMinimum(&arrA[0], MAX) << endl;
                break;
            case 4:
                hitungRataRata(&arrA[0], MAX);
                break;
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}

int cariMinimum(int *pa, int n) {
    int min = *pa;
    for (int i = 1; i < n; i++) {
        if (*(pa + i) < min)
            min = *(pa + i);
    }
    return min;
}

int cariMaksimum(int *pa, int n) {
    int maks = *pa;
    for (int i = 1; i < n; i++) {
        if (*(pa + i) > maks)
            maks = *(pa + i);
    }
    return maks;
}

void hitungRataRata(int *pa, int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total = total + *(pa + i);
    float rata_rata = (float) total / n;
    cout << "Nilai rata-rata = " << rata_rata << endl;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%202/Unguided/Unguided%20-%203/Screenshot%202026-10-06%20232647.png?raw=true)
![Screenshot Output Unguided 3_1](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%202/Unguided/Unguided%20-%203/Screenshot%202026-10-06%20232659.png?raw=true)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%202/Unguided/Unguided%20-%203/Screenshot%202026-10-06%20232759.png?raw=true)
![Screenshot Output Unguided 3_2](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%202/Unguided/Unguided%20-%203/Screenshot%202026-10-06%20232813.png?raw=true)

Program ini mengimplementasikan operasi pada array 1 dimensi arrA berukuran 10 elemen menggunakan konsep pointer untuk mengakses data. Program memiliki tiga sub-program: fungsi cariMinimum() dan cariMaksimum() yang mengembalikan nilai integer, serta prosedur void hitungRataRata() yang langsung mencetak hasil. Pada fungsi main(), array diakses menggunakan pointer &arrA[0] (alamat elemen pertama) yang dilewatkan ke sub-program, lalu di dalam fungsi/ prosedur nilai array diakses dengan notasi pointer *(pa + i) sebagai alternatif dari pa[i]. Program utama menggunakan struktur do-while dan switch-case untuk menampilkan menu interaktif yang memungkinkan pengguna memilih operasi (tampilkan isi array, cari maksimum, cari minimum, hitung rata-rata, atau keluar) secara berulang hingga memilih opsi 0.

## Kesimpulan
Praktikum Modul 2 Struktur Data berfokus pada penguasaan konsep dasar manipulasi data dan memori dalam bahasa C++, yang mencakup penggunaan array (satu dimensi, dua dimensi/matriks, dan berdimensi banyak) untuk mengelola kumpulan data bertipe sama, serta pemahaman mendalam tentang pointer dan alamat memori menggunakan operator alamat (&) dan dereference (*). Modul ini juga mengajarkan implementasi pemrograman modular melalui fungsi (yang mengembalikan nilai) dan prosedur void (yang tidak mengembalikan nilai), serta membedakan teknik pelewatan parameter (parameter passing) seperti Call by Value (menyalin nilai tanpa mengubah data asli), Call by Pointer (mengirim alamat memori), dan Call by Reference (mengirim referensi langsung) yang memungkinkan perubahan nilai variabel asli di luar fungsi. Konsep-konsep tersebut dipraktikkan secara langsung melalui studi kasus seperti operasi matriks 3x3, penukaran nilai tiga variabel, dan pengolahan data array satu dimensi (mencari minimum, maksimum, dan rata-rata) menggunakan menu interaktif switch-case, sehingga membentuk fondasi yang kuat untuk manipulasi data yang lebih terstruktur dan efisien.

## Referensi
[1] Modul 2: PENGENALAN BAHASA C++ (BAGIAN KEDUA). Modul Praktikum Struktur Data. (Referensi Modul). 
<br>[2] Munir, R. (2013). Algoritma dan Pemrograman dalam Bahasa Pascal dan C. Bandung: Informatika.
