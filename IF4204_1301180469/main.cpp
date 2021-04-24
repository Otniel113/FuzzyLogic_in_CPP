#include "header.h"

int main()
{
    double penghasilan[101];
    double pengeluaran[101];

    double tinggi[101];
    double menengah[101];
    double rendah[101];
    double boros[101];
    double sedang[101];
    double hemat[101];

    double terima[101];
    double dipertimbangkan[101];
    double tolak[101];

    double defuzz[101];

    tabelAkhir akhir[101];

    inPenghasilan(penghasilan);
    inPengeluaran(pengeluaran);

    inTinggi(tinggi,penghasilan);
    inMenengah(menengah,penghasilan);
    inRendah(rendah,penghasilan);
    inBoros(boros,pengeluaran);
    inSedang(sedang,pengeluaran);
    inHemat(hemat,pengeluaran);

    tblTerima(terima,menengah,rendah,boros,sedang);
    tblDipertimbangkan(dipertimbangkan,tinggi,menengah,rendah,boros,sedang,hemat);
    tblTolak(tolak,tinggi,menengah,sedang,hemat);

    defuzzSugeno(defuzz,terima,dipertimbangkan,tolak);

//    cetak(tinggi);
//    cetak(menengah);
//    cetak(rendah);
//    cetak(boros);
//    cetak(sedang);
//    cetak(hemat);
//    cetak(terima);
//    cetak(terima);
//    cetak(dipertimbangkan);
//    cetak(tolak);
//    cetak(defuzz);

    isiTabelAkhir(akhir,defuzz,penghasilan,pengeluaran);
    selectionSort(akhir);
    cetakTop20(akhir);
    getch();

    return 0;
}
