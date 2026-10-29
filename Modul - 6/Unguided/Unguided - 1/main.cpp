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