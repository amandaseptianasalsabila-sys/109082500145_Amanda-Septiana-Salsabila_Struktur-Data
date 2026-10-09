#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa{
    char nama[50];
    char nim[16];
    int uts, uas, tugas;
    float nilaiAkhir;
};

void inputMhs (mahasiswa &m) ;

float hitungNilaiAkhir (mahasiswa m) ;

void tampilMhs (mahasiswa m) ;

#endif 