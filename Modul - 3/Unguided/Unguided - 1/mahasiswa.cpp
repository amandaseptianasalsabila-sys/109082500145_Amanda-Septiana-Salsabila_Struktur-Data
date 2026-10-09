#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "input nama = ";
    cin >> (m).nama;
    cout << "input nim = ";
    cin >> (m).nim;
    cout << "input uts = ";
    cin >> (m).uts;
    cout << "input uas = ";
    cin >> (m).uas;
    cout << "input tugas = ";
    cin >> (m).tugas;
    (m).nilaiAkhir = hitungNilaiAkhir(m);
}

float hitungNilaiAkhir(mahasiswa m) {
    return 0.3*m.uts + 0.4*m.uas + 0.3*m.tugas;
}

void tampilMhs(mahasiswa m) {
    cout << "nama = " << m.nama << endl;
    cout << "nim = " << m.nim << endl;
    cout << "uts = " << m.uts << endl;
    cout << "uas = " << m.uas << endl;
    cout << "tugas = " << m.tugas << endl;
    cout << "nilai akhir = " << m.nilaiAkhir << endl;
}