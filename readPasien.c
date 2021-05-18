#include "stdio.h"
#include "stdlib.h"
#include "login.h"



void lookupPasien(){
    printf("Masukkan Data Pasien yang ingin di lookup: \n");
    printf("Nama                     : ");
    scanf("%[^\n]s",&nama); //variable nama sudah ada pada login.c sebagai global variable
    lower(nama);
    fflush(stdin);
    
    printf("Tanggal Lahir(DD/MM/YYYY): ");
    scanf("%[^\n]s",&ttl); //variable nama sudah ada pada login.c sebagai global variable
    fflush(stdin);


}