#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inputDatabasePasien(char namaPasien[], char ttl[], char tanggalKunjungan[], int umurPasien, char gejalaPenyakit[], char penyakitPasien[], char obatPasien[], char tanggalKontrol[])
{
    FILE *ptr;
    ptr = fopen("databasePasien.txt", "a");

    fprintf(ptr, "*****\n%s%s%s%d\n%s", namaPasien, ttl, tanggalKunjungan, umurPasien, gejalaPenyakit);
    fprintf(ptr, "%s\n%s\n%s\n\n", penyakitPasien, obatPasien, tanggalKontrol);
    fflush(stdin);
    fclose(ptr);
}