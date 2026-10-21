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