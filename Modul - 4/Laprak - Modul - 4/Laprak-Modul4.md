# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">Amanda Septiana Salsabila - 109082500145</p>

## Dasar Teori
Linked list adalah salah satu bentuk struktur data berupa rangkaian elemen data yang saling berhubungan dan bersifat fleksibel, karena dapat bertambah dan berkurang sesuai kebutuhan [2]. Data yang disimpan dapat berupa data tunggal atau data majemuk (record), misalnya data mahasiswa yang terdiri dari beberapa field [2]. Linked list dapat diimplementasikan dengan array maupun pointer. Pointer dipilih karena bersifat dinamis dan sesuai dengan sifat linked list yang fleksibel, sedangkan array bersifat statis sehingga lebih cocok untuk data yang jumlah maksimumnya sudah diketahui sejak awal [2]. Sebagai pembanding, array adalah tipe data terstruktur yang komponennya bertipe sama dan jumlahnya ditentukan lewat indeks pada saat dideklarasikan [1].

### A. Singly Linked List<br/>
Singly linked list adalah model linked list yang hanya memiliki satu arah pointer, sehingga pembacaan hanya dapat dilakukan maju [2].
1. Struktur node. Setiap node terdiri dari data (info) dan penghubung ke node berikutnya (next). List sendiri memiliki pointer first yang menunjuk ke node pertama [2].
2. Istilah penting. first/head adalah penunjuk elemen pertama, next adalah penunjuk elemen berikutnya, dan Nil/NULL menandakan pointer tidak menunjuk ke mana pun. Node terakhir menunjuk ke Nil, dan list dinyatakan kosong jika first = Nil [2].
3. Sifat. Singly linked list hanya membutuhkan satu pointer per node, pencarian dilakukan secara sekuensial, dan penyisipan atau penghapusan di tengah list lebih mudah [2].

### B. Tipe Data Bentukan (Struct)<br/>
Tipe data bentukan adalah tipe yang didefinisikan sendiri oleh pemrogram dan dapat tersusun dari beberapa tipe data dasar. Salah satu bentuknya adalah rekaman (record), yang disusun oleh satu atau lebih field, dan di C++ dideklarasikan dengan kata kunci struct [1]. Field di dalam record diakses dengan bentuk namavar.namafield [1]. Pada linked list, struct dipakai untuk mendeklarasikan node (ElmList) yang berisi info dan next, serta list (List) yang berisi First. Untuk node yang diakses lewat pointer, modul menggunakan operator panah (->) atau tanda titik [2].

### C. Prosedur dan Fungsi sebagai Primitif List
Pemrograman modular adalah metode membuat program dengan memecah masalah menjadi bagian-bagian yang lebih kecil, sehingga program lebih mudah dibaca, kesalahan lebih mudah dicari, dan penulisan bagian yang sama tidak perlu diulang [1]. Bentuk modulnya adalah prosedur dan fungsi. Prosedur dapat mengembalikan atau tidak mengembalikan nilai, sedangkan fungsi wajib mengembalikan nilai keluaran [1]. Pada ADT linked list, operasi-operasi dasar disebut primitif, dengan prototipe disimpan di file .h dan implementasinya di .cpp [2].
1. createList (prosedur) membentuk list kosong dengan mengatur first menjadi Nil [2].
2. alokasi (fungsi) mengalokasikan memori untuk node baru dan mengembalikan alamatnya. Pada C++ alokasi memakai new, dan dealokasi memakai delete [2].
3. dealokasi (prosedur) mengembalikan memori yang dipakai node kepada sistem [2].

### D. Operasi Insert dan Delete
Node baru lebih dulu dialokasikan dengan P = alokasi(X) dan P -> next = Nil [2].
1. Insert first menempatkan node di awal list dengan langkah P -> next = L.first lalu L.first = P [2].
2. Delete first menghapus node pertama dengan langkah P = L.first, L.first = (L.first) -> next, lalu P -> next = Nil, kemudian node didealokasi [2].
3. Delete last dan delete after melepas node terakhir atau node setelah node tertentu dengan mengatur ulang next node sebelumnya, lalu node didealokasi [2]. Karena kondisi list bisa kosong, pemeriksaan dilakukan dengan struktur pemilihan if-else [1].

### E. Operasi View, Penghitungan, dan Penghapusan List
1. View (printInfo) menelusuri list dari first sampai Nil sambil menampilkan info tiap node [2]. Penelusuran ini memakai struktur perulangan while, yang memeriksa kondisi terlebih dahulu dan mengulang perintah selama kondisi bernilai benar [1].
2. nbList menelusuri list dengan cara yang sama untuk menghitung jumlah node [2].
3. deleteList membebaskan memori seluruh node sehingga list kembali kosong [2].

## Guided 

### 1. Singly Linked List

### a. list.h
```C++
//hear guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalamm satu program
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedList { //ini linked listnya
    address first;
};

//semua function & procedure yang akan dipakai
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi (address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address Prev);
void insertLast(linkedList &List, address nodeBaru);

void delFirst(linkedList &List);
void delLast(linkedList &List);
void delAfter(linkedList &List, address nodeHapus, address nodePrev);
int nbList(linkedList List);
void deleteList(linkedList &List);

#endif
```
### b. list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak 
bool isEmpty(linkedList List) {
    if(List.first == Nil) {
        return true;
    } else  {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil*/
    address nodeBaru = new node;
    nodeBaru -> isidata.nama = nama;
    nodeBaru -> isidata.nim = nim;
    nodeBaru -> isidata.umur = umur;
    nodeBaru -> next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S memori yang digunakan node dikembalikan ke sistem */
    node -> next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarangan, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru -> next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesusah elemen node prev */
    if (Prev != Nil) {
        nodeBaru -> next = Prev -> next;
        Prev -> next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList & List, address nodeBaru) {
    /* I.S. sembarangan, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu -> next != Nil) {
            nodeBantu = nodeBantu -> next;
        }
        nodeBantu -> next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedList &List) {
    /* I.S. list tidak kosong
       F.S. node pertama di list terhapus */
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first -> next;
        nodeHapus -> next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List) {
    /* I.S. list tidak kosong
       F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false) {
        nodeHapus = List.first;
        if(nodeHapus -> next == Nil) {
            List.first -> next == Nil;
            dealokasi(nodeHapus);
        } else {
            while(nodeHapus -> next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus -> next;
            }
            nodePrev -> next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "List kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev) {
    /* I.S. list tidak kosong, Prev alamat salah satu elemen list
       F.S. nodeBantu adalah alamat dari Prev -> next, menghapus prev -> next dari list */
    if(isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev -> next != Nil) {
            nodeHapus = nodePrev -> next;
            nodePrev -> next = nodeHapus -> next;
            nodeHapus -> next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama: " << nodeBantu -> isidata.nama << ", NIM: " << nodeBantu -> isidata.nim << ", Usia: " << nodeBantu -> isidata.umur << endl;
            nodeBantu = nodeBantu -> next;
        }
    }
}

//function untuk menampilkan jumlah node di dalam list
int nbList(linkedList List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list */
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu -> next;
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node di dalam list)
void deleteList(linkedList &List) {
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu -> next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```

### c. main.cpp 
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main() {
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "231110014", 21);
    nodeC = alokasi("Rizal", "231110029", 20);
    nodeD = alokasi("Satrio", "2311102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node: " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah node: " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "Jumlah node: " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

Kode ini membuat singly linked list untuk data mahasiswa (nama, NIM, umur). list.h berisi struct dan prototype fungsi, list.cpp berisi operasi insert, delete, print, hitung node, dan hapus seluruh list dengan mengatur pointer next, sedangkan main.cpp mencoba semuanya dengan menyisipkan lima node, menghapus node pertama, terakhir, dan setelah Rizal, lalu menghapus seluruh list. Ada satu bug di delLast pada kasus satu node, yaitu List.first -> next == Nil yang seharusnya List.first = Nil.

## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”
```
Type infotype : int
Type address  : pointer to ElmList

Type ElmList <
    info : infotype
    next : address
>
Type List : < First : address >

procedure CreateList( input/output L : List )
function alokasi( x : infotype ) -> address
procedure dealokasi(input/output P : address )
procedure printInfo( input L : List )
procedure insertFirst(input/output L : List, input P :address)
```
### Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp”
### Kemudian buat program utama didalam file “main.cpp” dengan implementasi sebagai berikut :
```
int main(){
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L,P1);

    P2 = alokasi(0);
    insertFirst(L,P2);

    P3 = alokasi(8);
    insertFirst(L,P3);

    P4 = alokasi(12);
    insertFirst(L,P4);

    P5 = alokasi(9);
    insertFirst(L,P5);

    printInfo(L)
    return 0;
}
```

### a. singlylist.h 
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include<iostream>
using namespace std;

typedef int infotype; 

typedef struct ElmList *address; 

struct ElmList { 
    infotype info;
    address next;
};

struct List { 
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```

### b. singlylist.cpp
```C++
#include "singlylist.h"
#include <iostream>
using namespace std;

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P -> info = x;
    P -> next = Nil;
    return P;
}

void dealokasi(address &P) {
    P -> next = Nil;
    delete P;
    P = Nil;
}

void printInfo(List L) {
    if (L.First == Nil) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = L.First;
        while (nodeBantu != Nil) {
            cout << nodeBantu -> info << " ";
            nodeBantu = nodeBantu -> next;
        }
        cout << endl;
    }
}

void insertFirst(List &L, address P) {
    P -> next = L.First;
    L.First = P;
}
```

### c. main.cpp
```C++
#include "singlylist.h"

#include<iostream>
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}
```
### Output Unguided 1 :

##### Output 
![Screenshot Output Unguided 1_1](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%204/Unguided/Unguided%20-%201/Screenshot%202026-10-21%20102151.png?raw=true)

Di singlylist.h ada deklarasi infotype, address, struct ElmList yang isinya info dan next, struct List dengan pointer First, plus prototype kelima primitif. Implementasinya ada di singlylist.cpp: CreateList mengisi First dengan Nil, alokasi bikin node baru pakai new, dealokasi menghapus node lalu P diisi Nil, printInfo jalan dari First sambil mencetak tiap node, dan insertFirst menyambung node baru ke First yang lama lalu menjadikannya First. Di main.cpp, nilai 2, 0, 8, 12, 9 dimasukkan satu per satu pakai insertFirst. Karena tiap node masuk dari depan, urutannya jadi kebalik, yaitu 9, 12, 8, 0, 2, dan itu sama dengan output di soal.

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

### a. singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include<iostream>
using namespace std;

typedef int infotype; 

typedef struct ElmList *address; 

struct ElmList { 
    infotype info;
    address next;
};

struct List { 
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address Prev);
int nbList(List L);
void deleteList(List &L);

#endif
```

### b. singlylist.cpp
```C++
#include "singlylist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P -> info = x;
    P -> next = Nil;
    return P;
}

void dealokasi(address &P) {
    P -> next = Nil;
    delete P;
    P = Nil;
}

void printInfo(List L) {
    if (L.First == Nil) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = L.First;
        while (nodeBantu != Nil) {
            cout << nodeBantu -> info << " ";
            nodeBantu = nodeBantu -> next;
        }
        cout << endl;
    }
}

void insertFirst(List &L, address P) {
    P -> next = L.First;
    L.First = P;
}

void deleteFirst(List &L) {
    address nodeHapus;
    if (L.First != Nil) {
        nodeHapus = L.First;
        L.First = L.First -> next;
        nodeHapus -> next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void deleteLast(List &L) {
    address nodeHapus, nodePrev;
    if (L.First != Nil) {
        nodeHapus = L.First;
        if (nodeHapus -> next == Nil) { 
            L.First = Nil;
            dealokasi(nodeHapus);
        } else {
            while (nodeHapus -> next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus -> next;
            }
            nodePrev -> next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

void deleteAfter(List &L, address Prev) {
    address nodeHapus;
    if (L.First == Nil) {
        cout << "List kosong!" << endl;
    } else { 
        if (Prev != Nil && Prev -> next != Nil) {
            nodeHapus = Prev -> next;
            Prev -> next = nodeHapus -> next;
            nodeHapus -> next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

int nbList(List L) {
    int count = 0;
    address nodeBantu = L.First;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu -> next;
    }
    return count;
}

void deleteList(List &L) {
    address nodeBantu, nodeHapus;
    nodeBantu = L.First;
    while (nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu -> next;
        dealokasi(nodeHapus);
    }
    L.First = Nil;
    cout << "- List Berhasil Terhapus -" << endl;
}
```

### c. main.cpp
```C++
#include "singlylist.h"

#include<iostream>
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    deleteFirst(L);     
    deleteLast(L);       
    deleteAfter(L, P4);  

    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    deleteList(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output 
![Screenshot Output Unguided 2_1](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%204/Unguided/Unguided%20-%202/Screenshot%202026-10-21%20102425.png?raw=true)

Setelah lima kali insertFirst, isi list jadi 9, 12, 8, 0, 2. Lalu deleteFirst menghapus 9 dan deleteLast menghapus 2. Untuk deleteAfter(L, P4), node yang dihapus adalah node setelah 12, yaitu 8, jadi sisa list 12 dan 0. Hasil printInfo adalah 12 0 dengan jumlah node 2, dan setelah deleteList jumlahnya jadi 0. Outputnya sama dengan yang diminta soal.

## Kesimpulan
Dari praktikum Modul 4, saya jadi paham bahwa singly linked list adalah struktur data yang tiap elemennya (node) menyimpan data dan satu pointer next ke elemen berikutnya, dengan pointer First sebagai penanda awal list. Dibanding array, ukurannya fleksibel karena memori dialokasikan saat dibutuhkan lewat new dan dikembalikan lewat delete. Operasi dasarnya, yaitu insert (insertFirst, insertAfter, insertLast), delete (deleteFirst, deleteLast, deleteAfter), serta printInfo, nbList, dan deleteList, semuanya bekerja dengan menelusuri dan mengatur ulang pointer next. Urutan langkah saat mengubah pointer sangat berpengaruh, karena kalau salah urutan, sebagian list bisa terputus dan hilang. Dengan memisahkan kode ke .h, .cpp, dan main.cpp, program juga jadi lebih rapi dan mudah dipakai ulang. Hasil praktikum pun sesuai dengan output yang diminta soal, yaitu 9 12 8 0 2 untuk latihan pertama dan 12 0 dengan jumlah node 2, lalu 0 setelah list dihapus, untuk latihan kedua.

## Referensi
[1] Indahyanti, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma dan Pemrograman dalam Bahasa C++. Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4. 
<br>[2] Fakultas Informatika, Telkom University. (n.d.). Modul 4: Singly Linked List (Bagian Pertama), Praktikum Struktur Data. Bandung: Telkom University.