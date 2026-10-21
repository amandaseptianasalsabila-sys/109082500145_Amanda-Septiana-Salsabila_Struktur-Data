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