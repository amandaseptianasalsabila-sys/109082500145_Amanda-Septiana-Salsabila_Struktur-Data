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