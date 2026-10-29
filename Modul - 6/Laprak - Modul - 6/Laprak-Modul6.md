# <h1 align="center">Laporan Praktikum Modul 6 - DOUBLY LINKED LIST (BAGIAN PERTAMA) </h1>
<p align="center">Amanda Septiana Salsabila - 109082500145</p>

## Dasar Teori
Linked list atau yang disebut juga senarai berantai adalah salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dan dinamis [1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer [1]. Pointer sendiri adalah variabel penunjuk yang berisi alamat suatu lokasi memori, bukan nilai datanya [1]. Salah satu jenis linked list adalah doubly linked list, yaitu linked list yang setiap elemennya memiliki dua successor, yang menunjuk ke elemen sebelumnya (prev) dan ke elemen sesudahnya (next) [3].

### A. Konsep Doubly Linked List<br/>
Pada singly linked list, setiap node hanya memiliki satu pointer [1], sedangkan doubly linked list menambahkan pointer prev untuk bergerak mundur sehingga lebih fleksibel, dengan konsekuensi memori tambahan [1]. Proses akses elemen pada doubly linked list juga lebih mudah karena iterasi bisa dilakukan maju dan mundur [3].
### 1. Komponen Doubly Linked List
Doubly linked list terdiri dari empat komponen [3] :
- First : pointer pada list yang menunjuk ke elemen pertama.
- Last : pointer pada list yang menunjuk ke elemen terakhir.
- Next : pointer pada elemen yang menunjuk ke elemen sesudahnya.
- Prev : pointer pada elemen yang menunjuk ke elemen sebelumnya.
### 2. Deklarasi Struktur Data
Struct adalah tipe data bentukan yang mengelompokkan beberapa variabel bertipe sama atau berbeda dalam satu nama [1][2]. Doubly linked list dideklarasikan dengan struct yang berisi info, next, dan prev untuk elemen, serta first dan last untuk list [3]. Pointer next elemen terakhir dan prev elemen pertama bernilai Nil [3].
```
typedef int infotype;
typedef struct elmlist *address;
struct elmlist {
    infotype info;
    address next;
    address prev;
};
struct list {
    address first, last;
};
```
### 3. Abstract Data Type (ADT)
Doubly linked list memiliki ADT yang pada dasarnya sama dengan ADT pada singly linked list [3], yaitu pendefinisian tipe data (infotype, address, elmlist, list) beserta primitif seperti CreateList, alokasi, dealokasi, dan printInfo [3].

### B. Operasi pada Doubly Linked List
### 1. Insert
Insert adalah operasi menambahkan elemen baru ke dalam list [3]. Elemen baru dialokasikan terlebih dahulu, dengan next dan prev bernilai Nil [3]. Ada empat jenis insert [3] :
- Insert First : elemen disisipkan di awal list. P->next = L.first, (L.first)->prev = P, lalu L.first = P.
- Insert Last : elemen disisipkan di akhir list. P->prev = L.last, (L.last)->next = P, lalu L.last = P.
- Insert After : elemen disisipkan setelah elemen R. P->next = R->next, P->prev = R, (R->next)->prev = P, lalu R->next = P.
- Insert Before : kebalikan dari insert after, perbedaannya terletak pada pencarian elemennya.
### 2. Delete
Delete adalah operasi menghapus elemen dari list [3]. Elemen yang dihapus dapat dikembalikan atau didealokasi dari memori [3]. Jenis delete antara lain [3] :
- Delete First : P = L.first, L.first = (L.first)->next, (L.first)->prev = Nil, lalu P->next = Nil.
- Delete Last : P = L.last, L.last = (L.last)->prev, (L.last)->next = Nil, lalu P->prev = Nil.
- Delete After : menghapus elemen P yang berada setelah R. R->next = P->next, (P->next)->prev = R, lalu P->prev = Nil dan P->next = Nil.
- Delete Before : kebalikan dari delete after, perbedaannya terletak pada pencarian elemennya.
### 3. Update, View, dan Searching
Proses pencarian (searching), pengubahan data (update), dan penampilan data (view) pada dasarnya sama dengan singly linked list [3]. Perbedaannya, doubly linked list dapat melakukan iterasi maju (dari first dengan next) maupun mundur (dari last dengan prev) [3].

## Guided 

### 1. Doubly Linked List
### a. Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <string>
using namespace std;

struct barang {
    string kode;
    string nama;
    int tahun;
};

using infotype = barang;
struct elmlist;
using address = elmlist*;
struct elmlist { infotype info; address prev; address next; };
struct list { address first; address last; };

void CreateList(list &L);
address alokasi(const infotype &x);
void dealokasi(address &P);
void insertFirst(list &L, address P);
void insertLast(list &L, address P);
void insertAfter(list &L, address R, address P);
void insertBefore(list &L, address R, address P);
void printInfo(const list &L);
address findElm(const list &L, const string &kode);
void deleteFirst(list &L, address &P);
void deleteLast(list &L, address &P);
void deleteAfter(list &L, address prec, address &P);
void deleteBefore(list &L, address prec, address &P);
#endif
```

### b. Doublylist.cpp
```C++
#include <iostream>
#include <iomanip>
#include "Doublylist.h"
using namespace std;

void CreateList(list &L) { L.first = nullptr; L.last = nullptr; }

address alokasi(const infotype &x) {
    address P = new elmlist;
    P->info = x;
    P->prev = nullptr; P->next = nullptr;
    return P;
}
void dealokasi(address &P) {
    if (P != nullptr) { delete P; P = nullptr; }
}
void insertFirst(list &L, address P) {
    if (!P) return;
    P->prev = nullptr; P->next = L.first;
    if (L.first) L.first->prev = P;
    else L.last = P;
    L.first = P;
}
void insertLast(list &L, address P) {
    if (!P) return;
    P->next = nullptr; P->prev = L.last;
    if (L.last) L.last->next = P;
    else L.first = P;
    L.last = P;
}

// Menyisipkan P tepat setelah R.
void insertAfter(list &L, address R, address P) {
    if (!R || !P) return;
    P->prev = R;
    P->next = R->next;
    if (R->next) R->next->prev = P;
    else L.last = P;
    R->next = P;
}

// Menyisipkan P tepat sebelum R.
void insertBefore(list &L, address R, address P) {
    if (!R || !P) return;
    P->next = R;
    P->prev = R->prev;
    if (R->prev) R->prev->next = P;
    else L.first = P;
    R->prev = P;
}
void printInfo(const list &L) {
    address P = L.first;
    if (!P) {
        cout << "List kosong.\n";
        return;
    }

    cout << "+--------+------------+-------+\n";
    cout << "| Kode   | Nama       | Tahun |\n";
    cout << "+--------+------------+-------+\n";
    while (P) {
        cout << "| " << left << setw(6) << P->info.kode
             << " | " << setw(10) << P->info.nama
             << " | " << setw(5) << P->info.tahun << " |\n";
        P = P->next;
    }
    cout << "+--------+------------+-------+\n";
}
address findElm(const list &L, const string &kode) {
    address P = L.first;
    while (P) {
        if (P->info.kode == kode) return P;
        P = P->next;
    }
    return nullptr;
}
void deleteFirst(list &L, address &P) {
    if (!L.first) { P = nullptr; return; }
    P = L.first; L.first = P->next;
    if (L.first) L.first->prev = nullptr;
    else L.last = nullptr;
    P->prev = P->next = nullptr;
}
void deleteLast(list &L, address &P) {
    if (!L.last) { P = nullptr; return; }
    P = L.last; L.last = P->prev;
    if (L.last) L.last->next = nullptr;
    else L.first = nullptr;
    P->prev = P->next = nullptr;
}
// Menghapus node tepat setelah prec.
void deleteAfter(list &L, address prec, address &P) {
    P = nullptr;
    if (!prec || !prec->next) return;
    P = prec->next; prec->next = P->next;
    if (P->next) P->next->prev = prec;
    else L.last = prec;
    P->prev = P->next = nullptr;
}
// Menghapus node tepat sebelum succ.
void deleteBefore(list &L, address succ, address &P) {
    P = nullptr;
    if (!succ || !succ->prev) return;
    P = succ->prev; succ->prev = P->prev;
    if (P->prev) P->prev->next = succ;
    else L.first = succ;
    P->prev = P->next = nullptr;
}
```

### c. main.cpp
```C++
#include <iostream>
#include "Doublylist.h"
using namespace std;

void tampilkanJudul(const string &judul) {
    cout << "\n========================================\n";
    cout << judul << '\n';
    cout << "========================================\n";
}

int main() {
    list L;
    CreateList(L);

    infotype barang1 = {"B001", "Laptop", 2020};
    infotype barang2 = {"B002", "Monitor", 2022};
    infotype barang3 = {"B003", "Keyboard", 2023};
    infotype barang4 = {"B004", "Mouse", 2024};

    address P = nullptr;
    address posisi = nullptr;

    cout << "DEMONSTRASI OPERASI DOUBLY LINKED LIST\n";
    cout << "Data yang digunakan: B001, B002, B003, dan B004\n";

    tampilkanJudul("[1] INSERT FIRST");
    cout << "Menambahkan B002 di awal list.\n";
    insertFirst(L, alokasi(barang2));
    printInfo(L);

    tampilkanJudul("[2] INSERT LAST");
    cout << "Menambahkan B004 di akhir list.\n";
    insertLast(L, alokasi(barang4));
    printInfo(L);

    tampilkanJudul("[3] INSERT AFTER");
    cout << "Menambahkan B003 setelah B002.\n";
    posisi = findElm(L, "B002");
    if (posisi != nullptr) {
        insertAfter(L, posisi, alokasi(barang3));
    }
    printInfo(L);

    tampilkanJudul("[4] INSERT BEFORE");
    cout << "Menambahkan B001 sebelum B002.\n";
    posisi = findElm(L, "B002");
    if (posisi != nullptr) {
        insertBefore(L, posisi, alokasi(barang1));
    }
    printInfo(L);

    tampilkanJudul("[5] FIND ELEMENT");
    cout << "Mencari barang dengan kode B003.\n";
    posisi = findElm(L, "B003");
    if (posisi != nullptr) {
        cout << "Data ditemukan:\n";
        cout << "  Kode  : " << posisi->info.kode << '\n';
        cout << "  Nama  : " << posisi->info.nama << '\n';
        cout << "  Tahun : " << posisi->info.tahun << '\n';
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    tampilkanJudul("[6] DELETE AFTER");
    cout << "Menghapus node setelah B002 (B003).\n";
    posisi = findElm(L, "B002");
    deleteAfter(L, posisi, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "Tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("[7] DELETE BEFORE");
    cout << "Menghapus node sebelum B004 (B002).\n";
    posisi = findElm(L, "B004");
    deleteBefore(L, posisi, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "Tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("[8] DELETE FIRST");
    cout << "Menghapus node pertama.\n";
    deleteFirst(L, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "List kosong, tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("[9] DELETE LAST");
    cout << "Menghapus node terakhir.\n";
    deleteLast(L, P);
    if (P != nullptr) {
        cout << "Node yang dihapus: " << P->info.kode << '\n';
        dealokasi(P);
    } else {
        cout << "List kosong, tidak ada node yang dapat dihapus.\n";
    }
    printInfo(L);

    tampilkanJudul("SELESAI");
    cout << "Kondisi list: "
         << (L.first == nullptr && L.last == nullptr ? "kosong.\n" : "masih berisi data.\n");

    return 0;
}
```
Pada guided ini terdapat tiga file. Doublylist.h berisi deklarasi tipe data barang, node elmlist dengan pointer prev dan next, struct list dengan first dan last, serta prototipe fungsi yang dipakai. Doublylist.cpp berisi implementasi fungsi-fungsi tersebut, yaitu pembuatan list, alokasi dan dealokasi node, insert dan delete, pencarian data dengan findElm, dan penampilan data dengan printInfo. Pada main.cpp, empat data barang (B001 sampai B004) ditambahkan menggunakan insertFirst, insertLast, insertAfter, dan insertBefore. Untuk insertAfter dan insertBefore, node acuannya (B002) dicari lebih dulu dengan findElm. Setelah itu B003 dicari dengan findElm untuk ditampilkan datanya. Selanjutnya node dihapus satu per satu menggunakan deleteAfter, deleteBefore, deleteFirst, dan deleteLast sampai list kosong. Pada deleteAfter dan deleteBefore, node acuannya (B002 dan B004) juga dicari terlebih dahulu dengan findElm.

## Unguided 

### 1. Buatlah ADT Doubly Linked list sebagai berikut di dalam file “Doublylist.h”: 
```
Type infotype : kendaraan <
    nopol : string
    warna : string
    thnBuat : integer
>
Type address : pointer to ElmList
Type ElmList <
    info : infotype
    next :address
    prev : address
>
Type List <
    First : address
    Last : address
>
procedure CreateList( input/output L : List )
function alokasi( x : infotype ) → address
procedure dealokasi(input/output P : address )
procedure printInfo( input L : List )
procedure insertLast(input/output L : List,
   input P : address )

```
### Buatlah implementasi ADT Doubly Linked list pada file “Doublylist.cpp” dan coba hasil implementasi ADT pada file “main.cpp”. 
### a. Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

using infotype = kendaraan;
struct ElmList;
using address = ElmList*;
struct ElmList { infotype info; address next; address prev; };
struct List { address First; address Last; };

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
#endif
```
### b. Doublylist.cpp
```
#include <iostream>
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { L.First = nullptr; L.Last = nullptr; }

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr; P->prev = nullptr;
    return P;
}
void dealokasi(address &P) {
    if (P != nullptr) { delete P; P = nullptr; }
}
void printInfo(List L) {
    cout << "DATA LIST 1\n\n";
    address P = L.Last;
    while (P) {
        cout << "no polisi : " << P->info.nopol << '\n';
        cout << "warna     : " << P->info.warna << '\n';
        cout << "tahun     : " << P->info.thnBuat << '\n';
        P = P->prev;
    }
}
void insertLast(List &L, address P) {
    if (!P) return;
    P->next = nullptr; P->prev = L.Last;
    if (L.Last) L.Last->next = P;
    else L.First = P;
    L.Last = P;
}
```
### c. main.cpp
```
#include <iostream>
#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    CreateList(L);

    infotype x;
    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        bool terdaftar = false;
        address Q = L.First;
        while (Q != nullptr && !terdaftar) {
            if (Q->info.nopol == x.nopol) terdaftar = true;
            Q = Q->next;
        }

        if (terdaftar) {
            cout << "nomor polisi sudah terdaftar\n";
        } else {
            insertLast(L, alokasi(x));
        }
        cout << '\n';
    }

    printInfo(L);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%206/Unguided/Unguided%20-%201/Screenshot%202026-10-29%20161640.png?raw=true)

Pada nomor 1, program dibagi menjadi tiga file. Doublylist.h berisi deklarasi tipe kendaraan, node ElmList (dengan pointer next dan prev), struct List (dengan First dan Last), serta prototipe fungsinya. Doublylist.cpp berisi implementasi CreateList, alokasi, dealokasi, insertLast, dan printInfo, di mana printInfo mencetak data dari Last mundur lewat prev. Pada main.cpp, program meminta input empat data kendaraan, mengecek nomor polisi yang sudah terdaftar sebelum menambahkannya dengan insertLast, lalu menampilkan isi list dengan printInfo.

### 2. Carilah elemen dengan nomor polisi D001 dengan membuat fungsi baru. fungsi findElm( L : List, x : infotype ) : address 

### a. Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

using infotype = kendaraan;
struct ElmList;
using address = ElmList*;
struct ElmList { infotype info; address next; address prev; };
struct List { address First; address Last; };

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, infotype x);
#endif
```
### b. Doublylist.cpp
```
#include <iostream>
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { L.First = nullptr; L.Last = nullptr; }

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr; P->prev = nullptr;
    return P;
}
void dealokasi(address &P) {
    if (P != nullptr) { delete P; P = nullptr; }
}
void printInfo(List L) {
    cout << "DATA LIST 1\n\n";
    address P = L.Last;
    while (P) {
        cout << "no polisi : " << P->info.nopol << '\n';
        cout << "warna     : " << P->info.warna << '\n';
        cout << "tahun     : " << P->info.thnBuat << '\n';
        P = P->prev;
    }
}
void insertLast(List &L, address P) {
    if (!P) return;
    P->next = nullptr; P->prev = L.Last;
    if (L.Last) L.Last->next = P;
    else L.First = P;
    L.Last = P;
}
address findElm(List L, infotype x) {
    address P = L.First;
    while (P) {
        if (P->info.nopol == x.nopol) return P;
        P = P->next;
    }
    return nullptr;
}
```
### c. main.cpp
```
#include <iostream>
#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    CreateList(L);

    insertLast(L, alokasi({"D001", "hitam", 90}));
    insertLast(L, alokasi({"D003", "putih", 70}));
    insertLast(L, alokasi({"D004", "kuning", 90}));

    infotype x;
    cout << "Masukkan Nomor Polisi yang dicari : ";
    cin >> x.nopol;
    address P = findElm(L, x);
    cout << '\n';
    if (P != nullptr) {
        cout << "Nomor Polisi : " << P->info.nopol << '\n';
        cout << "Warna        : " << P->info.warna << '\n';
        cout << "Tahun        : " << P->info.thnBuat << '\n';
    } else {
        cout << "Data dengan nomor polisi " << x.nopol << " tidak ditemukan.\n";
    }
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_2](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%206/Unguided/Unguided%20-%202/Screenshot%202026-10-29%20161854.png?raw=true)

Pada nomor 2, program ditambahkan fungsi findElm untuk mencari data kendaraan berdasarkan nomor polisi. Doublylist.h memuat prototipe findElm(List L, infotype x) yang mengembalikan address. Doublylist.cpp mengimplementasikannya dengan menelusuri list dari First lewat next, lalu mengembalikan alamat node yang nopol-nya sama dengan x.nopol, atau nullptr jika tidak ditemukan. Pada main.cpp, tiga data awal (D001, D003, D004) dimasukkan dengan insertLast, kemudian program meminta nomor polisi yang dicari dan memanggil findElm. Jika ditemukan, nomor polisi, warna, dan tahun kendaraan ditampilkan, sedangkan jika tidak, muncul pesan bahwa data tidak ditemukan.

### 3. Hapus elemen dengan nomor polisi D003 dengan procedure delete. 
### - procedure deleteFirst( input/output L : List, P : address )
### - procedure deleteLast( input/output L : List, P : address)
### - procedure deleteAfter( input Prec : address, input/output P : address )

### a. Doublylist.h
```C++
#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include <string>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int thnBuat;
};

using infotype = kendaraan;
struct ElmList;
using address = ElmList*;
struct ElmList { infotype info; address next; address prev; };
struct List { address First; address Last; };

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
address findElm(List L, infotype x);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
#endif
```
### b. Doublylist.cpp
```
#include <iostream>
#include "Doublylist.h"
using namespace std;

void CreateList(List &L) { L.First = nullptr; L.Last = nullptr; }

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr; P->prev = nullptr;
    return P;
}
void dealokasi(address &P) {
    if (P != nullptr) { delete P; P = nullptr; }
}
void printInfo(List L) {
    cout << "DATA LIST 1\n\n";
    address P = L.Last;
    while (P) {
        cout << "no polisi : " << P->info.nopol << '\n';
        cout << "warna     : " << P->info.warna << '\n';
        cout << "tahun     : " << P->info.thnBuat << '\n';
        P = P->prev;
    }
}
void insertLast(List &L, address P) {
    if (!P) return;
    P->next = nullptr; P->prev = L.Last;
    if (L.Last) L.Last->next = P;
    else L.First = P;
    L.Last = P;
}
address findElm(List L, infotype x) {
    address P = L.First;
    while (P) {
        if (P->info.nopol == x.nopol) return P;
        P = P->next;
    }
    return nullptr;
}
void deleteFirst(List &L, address &P) {
    P = L.First;
    if (!P) return;
    L.First = P->next;
    if (L.First) L.First->prev = nullptr;
    else L.Last = nullptr;
    P->next = nullptr;
}
void deleteLast(List &L, address &P) {
    P = L.Last;
    if (!P) return;
    L.Last = P->prev;
    if (L.Last) L.Last->next = nullptr;
    else L.First = nullptr;
    P->prev = nullptr;
}
void deleteAfter(address Prec, address &P) {
    P = nullptr;
    if (!Prec || !Prec->next) return;
    P = Prec->next;
    Prec->next = P->next;
    if (P->next) P->next->prev = Prec;
    P->prev = nullptr; P->next = nullptr;
}
```
### c. main.cpp
```
#include <iostream>
#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    CreateList(L);

    insertLast(L, alokasi({"D001", "hitam", 90}));
    insertLast(L, alokasi({"D003", "putih", 70}));
    insertLast(L, alokasi({"D004", "kuning", 90}));

    infotype x;
    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> x.nopol;

    address target = findElm(L, x);
    address P = nullptr;
    if (target == nullptr) {
        cout << "Data dengan nomor polisi " << x.nopol << " tidak ditemukan.\n";
        return 0;
    }

    if (target == L.First) {
        deleteFirst(L, P);
    } else if (target == L.Last) {
        deleteLast(L, P);
    } else {
        deleteAfter(target->prev, P);
    }

    cout << "Data dengan nomor polisi " << P->info.nopol << " berhasil dihapus.\n";
    dealokasi(P);

    cout << "\nDATA LIST 1\n\n";
    address Q = L.Last;
    while (Q) {
        cout << "Nomor Polisi : " << Q->info.nopol << '\n';
        cout << "Warna        : " << Q->info.warna << '\n';
        cout << "Tahun        : " << Q->info.thnBuat << '\n';
        Q = Q->prev;
    }
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_3](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%206/Unguided/Unguided%20-%203/Screenshot%202026-10-29%20162257.png?raw=true)

Pada nomor 3, program ditambahkan tiga prosedur penghapusan, yaitu deleteFirst, deleteLast, dan deleteAfter. Doublylist.h memuat prototipe ketiganya. Doublylist.cpp mengimplementasikannya. deleteFirst dan deleteLast melepas node pertama atau terakhir lalu memperbarui First dan Last, yang keduanya menjadi nullptr jika list kosong. Sementara itu, deleteAfter melepas node tepat setelah Prec lalu menyambungkan kembali kedua tetangganya. Node yang dilepas dikembalikan lewat parameter P. Pada main.cpp, tiga data awal (D001, D003, D004) dimasukkan dengan insertLast, kemudian program meminta nomor polisi yang akan dihapus dan mencarinya dengan findElm. Jika node berada di awal list, dipakai deleteFirst. Jika di akhir, dipakai deleteLast. Jika di tengah seperti D003, dipakai deleteAfter dengan Prec berupa node sebelumnya. Setelah itu node di-dealokasi, pesan berhasil dihapus ditampilkan, dan sisa data dicetak dari Last mundur lewat prev.

## Kesimpulan
Dari praktikum modul 6 dapat disimpulkan bahwa doubly linked list adalah struktur data berantai yang setiap node-nya memiliki dua pointer, yaitu next ke node sesudahnya dan prev ke node sebelumnya, sehingga list dapat ditelusuri maju maupun mundur. Pada guided, operasi dasar seperti insert dan delete di awal, akhir, maupun sebelum dan sesudah node tertentu berhasil diimplementasikan, dengan pembaruan First dan Last saat node berada di ujung list atau list masih kosong. Pada latihan, ADT doubly linked list untuk data kendaraan berhasil dibuat, mulai dari penambahan data dengan insertLast disertai pengecekan nomor polisi yang sudah terdaftar, pencarian data dengan findElm, hingga penghapusan data dengan deleteFirst, deleteLast, dan deleteAfter. Hasil program sesuai dengan output yang diminta pada modul. Praktikum ini juga menunjukkan bahwa urutan pengubahan pointer harus diperhatikan agar tidak ada node yang terputus dan bahwa kondisi khusus, seperti list kosong atau list dengan satu node, harus ditangani supaya program tidak error.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyanti, Uce., Rahmawati, Yunianita. (2020). “BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++”. Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[3] Informatics Laboratory, Fakultas Informatika, Telkom University. (t.t.). Modul 6: Doubly Linked List (Bagian Pertama). Modul Praktikum Struktur Data.