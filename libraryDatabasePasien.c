#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inputDatabasePasien(char tanggalKunjungan[], char namaPasien[], int umurPasien, char gejalaPenyakit[], char penyakitPasien[], char obatPasien[], char tanggalKontrol[])
{
    FILE *ptr;
    ptr = fopen("databasePasien.txt", "a");

    fprintf(ptr, "Tanggal Kunjungan : %sNama Pasien: %sUmur Pasien: %d\nGejala Penyakit: %s", tanggalKunjungan, namaPasien, umurPasien, gejalaPenyakit);
    fprintf(ptr, "Penyakit Pasien: %s\nObat Untuk Pasien: %s\nTanggal Kontrol Selanjutnya: %s\n\n", penyakitPasien, obatPasien, tanggalKontrol);
    fflush(stdin);
    fclose(ptr);
}