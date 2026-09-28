#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Masukkan bilangan pertama : ";
    cin >> a;
    cout << "Masukkan bilangan kedua : ";
    cin >> b;

    cout << "\nHasil operasi : " << endl;
    cout << "Penjumlahan : " << a << " + " << b << " = " << a + b << endl;
    cout << "Pengurangan : " << a << " - " << b << " = " << a - b << endl;
    cout << "Perkalian : " << a << " * " << b << " = " << a * b << endl;

    if (b != 0) {
        cout << "Pembagian : " << a << " / " << b << " = " << a / b << endl;
    } else {
        cout << "Pembagian : Tidak dapat dibagi dengan nol!" << endl;
    }

    return 0;
}