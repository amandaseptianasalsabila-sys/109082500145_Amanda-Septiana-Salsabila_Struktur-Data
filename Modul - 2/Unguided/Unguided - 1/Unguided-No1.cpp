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