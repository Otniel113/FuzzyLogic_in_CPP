#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <conio.h>


using namespace std;

struct tabelAkhir{
    int indeks;
    double defuzz;
    double penghasilan;
    double pengeluaran;
};

/**Di file penghasilan.cpp dan pengeluaran.cpp*/
void inPenghasilan(double penghasilan[]);
void inPengeluaran(double pengeluaran[]);

/**Function menghitung nilai Fuzzification Penghasilan*/
double penghasilanTinggi(double nilai_penghasilan);
double penghasilanMenengah(double nilai_penghasilan);
double penghasilanRendah(double nilai_penghasilan);

/**Function menghitung nilai Fuzzification Pengeluaran*/
double pengeluaranBoros(double nilai_pengeluaran);
double pengeluaranSedang(double nilai_pengeluaran);
double pengeluaranHemat(double nilai_pengeluaran);

/**Tabel menampung hasil Fuzzification*/
void inTinggi(double tinggi[], double penghasilan[]);
void inMenengah(double menengah[], double penghasilan[]);
void inRendah(double rendah[], double penghasilan[]);
void inBoros(double boros[], double pengeluaran[]);
void inSedang(double sedang[], double pengeluaran[]);
void inHemat(double hemat[], double pengeluaran[]);

/**Inference*/
void tblTerima(double terima[], double menengah[], double rendah[], double boros[], double sedang[]);
void tblDipertimbangkan(double dipertimbangkan[], double tinggi[], double menengah[], double rendah[], double boros[], double sedang[], double hemat[]);
void tblTolak(double tolak[], double tinggi[], double menengah[], double sedang[], double hemat[]);

/**Defuzzification*/
void defuzzSugeno(double defuzz[], double terima[], double dipertimbangkan[], double tolak[]);

/**Cetak tabel (membantu tracing)*/
void cetak(double tabel[]);

/**Tabel akhir berisi top 20 berdasarkan Defuzz*/
void isiTabelAkhir(tabelAkhir akhir[], double defuzz[], double penghasilan[], double pengeluaran[]);
void selectionSort(tabelAkhir akhir[]);
void cetakTop20(tabelAkhir akhir[]);


#endif // HEADER_H_INCLUDED
