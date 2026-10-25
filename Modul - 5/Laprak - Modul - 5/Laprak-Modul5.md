# <h1 align="center">Laporan Praktikum Modul 5 - SINGLY LINKED LIST (BAGIAN KEDUA) </h1>
<p align="center">Amanda Septiana Salsabila - 109082500145</p>

## Dasar Teori
Linked list atau senarai berantai adalah salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas [1]. Linked list terdiri dari sejumlah node (simpul) yang dihubungkan secara linier dengan bantuan pointer [1]. Pada singly linked list, setiap node hanya memiliki satu pointer yang menunjuk ke node berikutnya, sehingga penelusuran hanya bisa dilakukan satu arah, dari node pertama sampai node terakhir. Struktur data ini memanfaatkan alokasi memori dinamis, sehingga ukurannya dapat bertambah atau berkurang saat program berjalan [2]. Pada praktikum ini, singly linked list dibuat sebagai ADT (Abstract Data Type) dengan bahasa C++, yang disimpan dalam file *.h untuk deklarasi dan file *.cpp untuk implementasi [3].

### A. Struktur ADT Singly Linked List<br/>
ADT singly linked list dibangun dari elemen (node) dan sebuah penanda awal list yang disebut first [3].
```
typedef int infotype;
typedef struct ElmList *address;
struct ElmList {
    infotype info;
    address next;
};
struct List {
    address first;
};
```
1. Node (elemen list) : Setiap node terdiri dari info untuk menyimpan data dan next berupa pointer yang menunjuk ke node berikutnya [1][3].
2. First : Pointer yang menunjuk ke elemen pertama list. List dinyatakan kosong jika L.first = Nil [3].
3. Akses elemen : Setiap elemen yang beralamat P diakses dengan operator panah, yaitu P->info untuk data dan P->next untuk node selanjutnya [3]. Node terakhir memiliki next bernilai Nil sebagai penanda akhir list.

### B. Operasi Dasar Penambahan Elemen<br/>
Penambahan elemen dilakukan dengan menyambungkan node baru ke list melalui pengaturan pointer [3].
1. insertFirst : Menempatkan elemen P di awal list, yaitu P->next = L.first kemudian L.first = P. Urutan kedua langkah ini tidak boleh terbalik, karena sisa list akan hilang [3].
2. insertAfter : Menempatkan elemen P sesudah elemen Prec. Operasi ini membutuhkan alamat Prec, yang biasanya diperoleh dari hasil pencarian [3].
3. insertLast : Menempatkan elemen P di akhir list, dengan menelusuri list sampai node terakhir [3].

### C. Operasi Pencarian (Searching)
Searching adalah operasi dasar list yang mencari node tertentu dengan mengunjungi setiap node secara berurutan dan berhenti setelah node yang dicari ditemukan [3]. Operasi ini menjadi dasar bagi operasi insert after, delete after, dan update, karena semuanya memerlukan alamat node tertentu [3].
1. findElm : Mencari elemen dengan info = X. Fungsi mengembalikan alamat elemen jika ditemukan dan Nil jika tidak [3].
2. fFindElm : Memeriksa apakah elemen dengan alamat P ada di dalam list, dengan hasil true atau false [3].
3. findBefore : Mengembalikan alamat elemen sebelum P, dan Nil jika P berada di awal list [3].

Pola penelusuran (traversal) yang digunakan adalah :
```
address P = L.first;
while (P != Nil) {
    // proses node P
    P = P->next;
}
```

### D. Operasi Penghapusan Elemen
Penghapusan elemen dilakukan dengan memutus node dari rangkaian pointer, lalu mengembalikan memorinya ke sistem (dealokasi) [2][3].
1. delFirst : Menghapus elemen pertama. first yang baru adalah elemen setelah elemen pertama yang lama [3].
2. delLast : Menghapus elemen terakhir list [3].
3. delAfter : Menghapus elemen yang berada setelah Prec, yaitu Prec->next [3].

### E. Operasi Proses Seluruh Elemen
Operasi ini memproses list secara keseluruhan dengan teknik traversal [3].
1. printInfo : Menampilkan semua info pada list jika list tidak kosong [3].
2. nbList : Menghitung jumlah elemen pada list. Pola yang sama dapat dipakai untuk menjumlahkan seluruh info elemen [3].
3. delAll dan invertList : delAll menghapus dan mendealokasi semua elemen, sedangkan invertList membalik urutan elemen list [3].

## Guided 

### 1. List Buah
### a. listBuah.h
```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```

### b. listBuah.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - UPDATE -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - SEARCHING -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

### c. main.cpp
```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    printList(List);
    updateLast(List);
    printList(List);
    updateAfter(List, nodeD);
    printList(List);
    
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;
    
    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);
    
    delFirst(List);
    printList(List);
    delLast(List);
    printList(List);
    delAfter(List, nodeD, nodeC);
    printList(List);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Pada guided 1 ini dibuat singly linked list untuk menyimpan data buah (nama, jumlah, dan harga) yang dipisah menjadi tiga file, yaitu listBuah.h untuk deklarasi, listBuah.cpp untuk implementasi fungsi, dan main.cpp untuk pengujian. Setiap node berisi data buah dan pointer next, sedangkan list hanya memiliki pointer first yang menunjuk ke node pertama dan dinyatakan kosong jika first == Nil. Operasi yang diimplementasikan meliputi insert, delete, update, dan searching berdasarkan nama, alamat node, serta range harga, yang dilakukan dengan menelusuri list dari node pertama hingga data ditemukan atau mencapai Nil. Pada main.cpp, lima node (Jeruk, Apel, Pir, Semangka, dan Durian) dimasukkan sehingga urutan list menjadi Jeruk, Pir, Semangka, Apel, lalu Durian, kemudian dilakukan pengujian update, searching, delete, dan penghapusan seluruh isi list.

## Unguided 

### 2. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”: 
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
### Kemudian buat implementasi ADT Singly Linked list pada file “Singlylist.cpp”. 
### Cobalah hasil implementasi ADT pada file "main.cpp"
```
int main() 
{ 
    List L; 
    address P1, P2, P3, P4, P5 = Nil; createList(L); 
    
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
### a. Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```
### b. Singlylist.cpp
```
#include "Singlylist.h"

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}
```
### c. main.cpp
```
#include "Singlylist.h"

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

    printInfo(L);
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_2](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%205/Unguided/Unguided%20-%202/Screenshot%202026-10-25%20223448.png?raw=true)

Setiap insertFirst menempatkan node baru di awal list, sehingga node yang dimasukkan paling akhir berada paling depan. Data dimasukkan dengan urutan 2, 0, 8, 12, 9, jadi hasil cetaknya terbalik menjadi 9, 12, 8, 0, 2. Fungsi alokasi membuat node baru dengan new lalu mengisi info dan mengatur next menjadi Nil. Pada insertFirst, pointer next node baru diarahkan ke L.first, kemudian L.first diarahkan ke node baru tersebut. Fungsi printInfo menelusuri list dari first sampai Nil sambil menampilkan info setiap node.

### 3. Carilah elemen dengan info 8 dengan membuat fungsi baru. 
### fungsi findElm( L : List, x : infotype ) : address 

### a. Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
address findElm(List L, infotype x);

#endif
```
### b. Singlylist.cpp
```
#include "Singlylist.h"

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}
```
### c. main.cpp
```
#include "Singlylist.h"

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

    if (findElm(L, 8) != Nil) {
        cout << "8 ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_3](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%205/Unguided/Unguided%20-%203/Screenshot%202026-10-25%20223308.png?raw=true)

Fungsi findElm menerima list L dan nilai x, lalu menelusuri list dari L.first memakai pointer bantu P. Pada setiap node, info dibandingkan dengan x. Jika sama, alamat node langsung dikembalikan, dan jika tidak maka P pindah ke node berikutnya. Kalau P sudah mencapai Nil tanpa ada yang cocok, fungsi mengembalikan Nil. Pada main.cpp, hasil findElm(L, 8) dibandingkan dengan Nil. Jika bukan Nil, program menampilkan “8 ditemukan dalam list”, dan jika Nil, cabang else yang dijalankan.

### 4. Hitunglah jumlah total info seluruh elemen (9+12+8+0+2=31). 

### a. Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
address findElm(List L, infotype x);
int sumInfo(List L);

#endif
```
### b. Singlylist.cpp
```
#include "Singlylist.h"

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

int sumInfo(List L) {
    int total = 0;
    address P = L.first;
    while (P != Nil) {
        total = total + P->info;
        P = P->next;
    }
    return total;
}
```
### c. main.cpp
```
#include "Singlylist.h"

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

    cout << "Total info dari kelima elemen adalah " << sumInfo(L) << endl;

    return 0;
}
```
### Output Unguided 4 :

##### Output 1
![Screenshot Output Unguided 4_4](https://github.com/amandaseptianasalsabila-sys/109082500145_Amanda-Septiana-Salsabila_Struktur-Data/blob/main/Modul%20-%205/Unguided/Unguided%20-%204/Screenshot%202026-10-25%20225157.png?raw=true)

Fungsi sumInfo membuat variabel total bernilai 0 dan pointer bantu P yang menunjuk ke L.first. Perulangan while (P != Nil) menelusuri list, dan pada setiap node P->info ditambahkan ke total sebelum P pindah ke node berikutnya. Setelah P mencapai Nil, total dikembalikan. Pada main.cpp, hasil sumInfo(L) langsung ditampilkan lewat cout bersama teks pada soal, yaitu 31.

## Kesimpulan
Praktikum ini menunjukkan bahwa singly linked list dapat dibuat sebagai ADT dalam C++ dengan memisahkan deklarasi, implementasi, dan pengujian ke dalam file header, file implementasi, dan file utama. Setiap node menyimpan data dan pointer next, sedangkan list hanya memegang pointer first yang menunjuk ke node pertama. Pada guided, list digunakan untuk menyimpan data buah dengan operasi insert, update, searching, dan delete yang dilakukan dengan mengatur ulang pointer atau menelusuri list dari node pertama hingga Nil. Hasilnya, kelima node berhasil disisipkan dengan urutan Jeruk, Pir, Semangka, Apel, lalu Durian, dan seluruh isi list dapat dihapus hingga jumlah node menjadi 0. Pada unguided, insertFirst menghasilkan urutan terbalik yaitu 9 12 8 0 2, findElm berhasil menemukan elemen 8, dan sumInfo menghasilkan total 31. Dengan penggunaan pointer, data dapat dikelola secara dinamis sehingga ukuran list dapat bertambah atau berkurang tanpa batas tetap.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). “BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++”. Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[3] Informatics Laboratory, Fakultas Informatika, Telkom University. (2026). Modul 5: Singly Linked List (Bagian Kedua). Modul Praktikum Struktur Data.