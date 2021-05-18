#include "stdio.h"
#include "stdlib.h"
#include "login.h"



void lookupPasien(){
    fflush(stdin);
    char tmp[700], data1[700], data2[700];
    bool found;
    printf("Masukkan Data Pasien yang ingin di lookup: \n");
    printf("Nama                     : ");
    scanf("%[^\n]s",&nama); //variable nama sudah ada pada login.c sebagai global variable
    lower(nama);
    fflush(stdin);
    
    printf("Tanggal Lahir(DD/MM/YYYY): ");
    scanf("%[^\n]s",&ttl); //variable nama sudah ada pada login.c sebagai global variable
    fflush(stdin);

    FILE *fp;
    fp = fopen("databasePasien.txt","r");
    while(fgets(tmp, 700, fp) != NULL){
        sscanf(tmp,"%[^\n]s\n",data1);
        if(strcmp(data1, nama) == 0){
            fgets(tmp, 700, fp);
            sscanf(tmp,"%[^\n]s\n",data2);
            if(strcmp(data2, ttl) == 0){
                printf("Nama              : %s\n",data1);
                printf("Tanggal Lahir     : %s\n",ttl);

                fgets(tmp, 700, fp);
                sscanf(tmp,"%[^\n]s\n",data2);
                fflush(stdin);
                printf("Tanggal Kunjungan : %s\n", data2);


                fgets(tmp, 4, fp);
                sscanf(tmp,"%[^\n]s\n",data2);
                fflush(stdin);
                printf("Umur              : %s\n", data2);


                fgets(tmp, 700, fp);
                sscanf(tmp,"%[^\n]s\n",data2);
                fflush(stdin);
                printf("Gejala            : %s\n", data2);


                fgets(tmp, 700, fp);
                sscanf(tmp,"%[^\n]s\n",data2);
                fflush(stdin);
                printf("Penyakit          : %s\n", data2);


                fgets(tmp, 700, fp);
                sscanf(tmp,"%[^\n]s\n",data2);
                fflush(stdin);
                printf("Obat              : %s\n", data2);


                fgets(tmp, 700, fp);
                sscanf(tmp,"%[^\n]s\n",data2);
                fflush(stdin);
                printf("Tanggal Kontrol   : %s\n", data2);


                found = 1;
                break;
            }
        }
        found = 0;
    }
    if(found == 0) printf("Data Pasien yang dicari tidak ditemukan!\n");
    fclose(fp);
}