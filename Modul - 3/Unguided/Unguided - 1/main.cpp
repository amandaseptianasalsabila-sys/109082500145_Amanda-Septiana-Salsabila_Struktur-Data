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