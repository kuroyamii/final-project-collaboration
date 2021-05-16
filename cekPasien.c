#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libraryDatabasePasien.h"

void cekPasien()
{
    char namaPasien[50], gejalaPenyakit[300], obatPasien[300], penyakitPasien[300], tanggalKontrol[70], tanggalKunjungan[50];
    char menunggu[] = "Mohon Menunggu Informasi Lebih Lanjut dari Dokter";
    int umurPasien;

    printf("Masukkan Tanggal Kunjungan: \n");
    fgets(tanggalKunjungan, 50, stdin);
    fflush(stdin);
    printf("Masukkan Nama Pasien: ");
    fflush(stdin);
    fgets(namaPasien, 50, stdin);
    printf("Masukkan Umur Pasien: ");
    scanf("%d", &umurPasien);
    printf("Masukkan Gejala yang Dirasakan Pasien: ");
    fflush(stdin);
    fgets(gejalaPenyakit, 300, stdin);
    strcpy(penyakitPasien, menunggu);
    printf("Penyakit Pasien:\n%s\n\n", penyakitPasien);
    strcpy(obatPasien, menunggu);
    printf("Obat yang Diberikan Kepada Pasien:\n%s\n\n", obatPasien);
    strcpy(tanggalKontrol, menunggu);
    printf("Tanggal Kontrol Selanjutnya:\n%s\n\n", tanggalKontrol);
    inputDatabase(tanggalKunjungan, namaPasien, umurPasien, gejalaPenyakit, penyakitPasien, obatPasien, tanggalKontrol);
}
