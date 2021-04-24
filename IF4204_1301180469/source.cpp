#include "header.h"

/**============================Function menghitung nilai Fuzzification Penghasilan============================*/

double penghasilanTinggi(double nilai_penghasilan){
    double hasil;
    if (nilai_penghasilan>=16){
        hasil = 1;
    }else if ((nilai_penghasilan>=13) && (nilai_penghasilan<16)){
        hasil = (nilai_penghasilan-13)/3;
    }else{
        hasil = 0;
    }
    return hasil;
}

double penghasilanMenengah(double nilai_penghasilan){
    double hasil;
    if ((nilai_penghasilan>=13) && (nilai_penghasilan<16)){
        hasil = (16-nilai_penghasilan)/3;
    }else if ((nilai_penghasilan>=11) && (nilai_penghasilan<13)){
        hasil = 1;
    }else if ((nilai_penghasilan>=8) && (nilai_penghasilan<11)){
        hasil = (nilai_penghasilan-8)/3;
    }else{
        hasil = 0;
    }
    return hasil;
}

double penghasilanRendah(double nilai_penghasilan){
    double hasil;
    if (nilai_penghasilan<8){
        hasil = 1;
    }else if ((nilai_penghasilan>=8) && (nilai_penghasilan<11)){
        hasil = (11-nilai_penghasilan)/3;
    }else{
        hasil = 0;
    }
    return hasil;
}

/**============================Function menghitung nilai Fuzzification Pengeluaran============================*/
double pengeluaranBoros(double nilai_pengeluaran){
    double hasil;
    if (nilai_pengeluaran >=10){
        hasil = 1;
    }else if ((nilai_pengeluaran>=8) && (nilai_pengeluaran<10)){
        hasil = (nilai_pengeluaran-8)/2;
    }else{
        hasil = 0;
    }
    return hasil;
}

double pengeluaranSedang(double nilai_pengeluaran){
    double hasil;
    if ((nilai_pengeluaran>=8) && (nilai_pengeluaran<10)){
        hasil = (10-nilai_pengeluaran)/2;
    }else if ((nilai_pengeluaran>=7) && (nilai_pengeluaran<8)){
        hasil = 1;
    }else if ((nilai_pengeluaran>=5) && (nilai_pengeluaran<7)){
        hasil = (nilai_pengeluaran-5)/2;
    }else{
        hasil = 0;
    }
    return hasil;
}

double pengeluaranHemat(double nilai_pengeluaran){
    double hasil;
    if (nilai_pengeluaran<5){
        hasil = 1;
    }else if ((nilai_pengeluaran>=5) && (nilai_pengeluaran<7)){
        hasil = (7-nilai_pengeluaran)/2;
    }else{
        hasil = 0;
    }
    return hasil;
}

/**============================Tabel menampung hasil Fuzzification============================*/
void inTinggi(double tinggi[], double penghasilan[]){
    double hasil;
    tinggi[0] = 0;
    for (int i=1;i<=100;i++){
        hasil = penghasilan[i];
        tinggi[i] = penghasilanTinggi(hasil);
    }
}

void inMenengah(double menengah[], double penghasilan[]){
    double hasil;
    menengah[0] = 0;
    for (int i=1;i<=100;i++){
        hasil = penghasilan[i];
        menengah[i] = penghasilanMenengah(hasil);
    }
}

void inRendah(double rendah[], double penghasilan[]){
    double hasil;
    rendah[0] = 0;
    for (int i=1;i<=100;i++){
        hasil = penghasilan[i];
        rendah[i] = penghasilanRendah(hasil);
    }
}

void inBoros(double boros[], double pengeluaran[]){
    double hasil;
    boros[0] = 0;
    for (int i=1;i<=100;i++){
        hasil = pengeluaran[i];
        boros[i] = pengeluaranBoros(hasil);
    }
}

void inSedang(double sedang[], double pengeluaran[]){
    double hasil;
    sedang[0] = 0;
    for (int i=1;i<=100;i++){
        hasil = pengeluaran[i];
        sedang[i] = pengeluaranSedang(hasil);
    }
}

void inHemat(double hemat[], double pengeluaran[]){
    double hasil;
    hemat[0] = 0;
    for (int i=1;i<=100;i++){
        hasil = pengeluaran[i];
        hemat[i] = pengeluaranHemat(hasil);
    }
}

/**============================Inference============================*/
void tblTerima(double terima[], double menengah[], double rendah[], double boros[], double sedang[]){
    terima[0] = 0;

    for (int i=1;i<=100;i++){
        terima[i] = max(max(min(menengah[i],boros[i]), min(rendah[i],boros[i])), min(rendah[i],sedang[i]));
    }
}

void tblDipertimbangkan(double dipertimbangkan[], double tinggi[], double menengah[], double rendah[], double boros[], double sedang[], double hemat[]){
    dipertimbangkan[0] = 0;

    for (int i=1; i<=100; i++){
        dipertimbangkan[i] = max(max(min(tinggi[i], boros[i]), min(menengah[i], sedang[i])), min(rendah[i], hemat[i]));
    }
}

void tblTolak(double tolak[], double tinggi[], double menengah[], double sedang[], double hemat[]){
    tolak[0] = 0;

    for (int i=1; i<=100; i++){
        tolak[i] = max(max(min(tinggi[i], sedang[i]), min(tinggi[i], hemat[i])), min(menengah[i], hemat[i]));
    }
}

/**============================Defuzzification============================*/
void defuzzSugeno(double defuzz[], double terima[], double dipertimbangkan[], double tolak[]){
    defuzz[0] = 0;

    for (int i=1; i<=100; i++){
        defuzz[i] = (terima[i]*100 + dipertimbangkan[i]*70 + tolak[i]*50)/(terima[i] + dipertimbangkan[i] + tolak[i]);
    }
}

/**============================Cetak tabel (membantu tracing)============================*/
void cetak(double tabel[]){
    cout << endl;
    for (int i=1;i<=100;i++){
        cout << "Data ke-" << i << " = " << tabel[i] << endl;
    }
}

/**============================Tabel akhir berisi top 20 berdasarkan Defuzz============================*/
void isiTabelAkhir(tabelAkhir akhir[], double defuzz[], double penghasilan[], double pengeluaran[]){
    for (int i = 1; i<=100; i++){
        akhir[i].indeks = i;
        akhir[i].defuzz = defuzz[i];
        akhir[i].penghasilan = penghasilan[i];
        akhir[i].pengeluaran = pengeluaran[i];
    }
}

void selectionSort(tabelAkhir akhir[]){
    int i,j, maks, temp1;
    double temp2, temp3, temp4;
    for (i=1; i<=100; i++){
        maks = i;
        for (j = i+1; j<101; j++){
            if (akhir[j].defuzz >= akhir[maks].defuzz){
                maks = j;
            }
            temp1 = akhir[i].indeks;
            akhir[i].indeks = akhir[maks].indeks;
            akhir[maks].indeks = temp1;

            temp2 = akhir[i].defuzz;
            akhir[i].defuzz = akhir[maks].defuzz;
            akhir[maks].defuzz = temp2;

            temp3 = akhir[i].penghasilan;
            akhir[i].penghasilan = akhir[maks].penghasilan;
            akhir[maks].penghasilan = temp3;

            temp4 = akhir[i].pengeluaran;
            akhir[i].pengeluaran = akhir[maks].pengeluaran;
            akhir[maks].pengeluaran = temp4;
        }
    }
}

void cetakTop20(tabelAkhir akhir[]){
    cout << "\n20 Orang yang layak mendapat beasiswa adalah : " << endl;
    for (int i=1; i<=20; i++){
        cout << "Orang ke-" << akhir[i].indeks << " dengan penghasilan " << akhir[i].penghasilan << " juta dan ";
        cout << "pengeluaran " << akhir[i].pengeluaran << " juta dan nilai defuzz " << akhir[i].defuzz << endl;
    }
}


