#include "stdio.h"
#include "stdlib.h"
#include "login.h"

char data1[700], data2[700], data3[700], data4[4], data5[700],data6[700],data7[700],data8[700];
char tmp[700];


bool lookupPasien(){
    fflush(stdin);
    char tmp[700];
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

                fgets(tmp, 700, fp);
                sscanf(tmp,"%[^\n]s\n",data3);
                fflush(stdin);


                fgets(tmp, 4, fp);
                sscanf(tmp,"%[^\n]s\n",data4);
                fflush(stdin);


                fgets(tmp, 700, fp);
                sscanf(tmp,"%[^\n]s\n",data5);
                fflush(stdin);


                fgets(tmp, 700, fp);
                sscanf(tmp,"%[^\n]s\n",data6);
                fflush(stdin);


                fgets(tmp, 700, fp);
                sscanf(tmp,"%[^\n]s\n",data7);
                fflush(stdin);


                fgets(tmp, 700, fp);
                sscanf(tmp,"%[^\n]s\n",data8);
                fflush(stdin);


                return true;
            }
        }
    }
    fclose(fp);
    return false;
}

void printPasien(){
    if(lookupPasien() == true){
        printf("Nama              : %s\n", data1);
        printf("Tanggal Lahir     : %s\n", data2);
        printf("Tanggal Kunjungan : %s\n", data3);
        printf("Umur              : %s\n", data4);
        printf("Gejala            : %s\n", data5);
        printf("Penyakit          : %s\n", data6);
        printf("Obat              : %s\n", data7);
        printf("Tanggal Kontrol   : %s\n", data8);
    }else printf("Maaf, data pasien yang anda cari tidak ditemukan!\n");
}

void updatePasien(){
    int pil;
    if(lookupPasien() == true){
        printf("Nama              : %s\n", data1);
        printf("Tanggal Lahir     : %s\n", data2);
        printf("Tanggal Kunjungan : %s\n", data3);
        printf("Umur              : %s\n", data4);
        printf("Gejala            : %s\n", data5);
        printf("Penyakit          : %s\n", data6);
        printf("Obat              : %s\n", data7);
        printf("Tanggal Kontrol   : %s\n", data8);
        do{
            printf("Apakah anda ingin memperbaharui data ini?\n1. Ya\n2. Tidak\nPilihan: ");
            scanf("%d",&pil);
            switch(pil){
                case 1:
                {
                    FILE *fp;
                    FILE *fptr;
                    fp = fopen("databasePasien.txt","r");
                    fptr = fopen("databases/tmp.txt","w");

                    fflush(stdin);
                    printf("Update data: \n");
                    printf("Penyakit          : ");
                    scanf("%[^\n]s",&data6);
                    fflush(stdin);
                    printf("Obat              : ");
                    scanf("%[^\n]s",&data7);
                    fflush(stdin);
                    printf("Tanggal Kontrol   : ");
                    scanf("%[^\n]s",&data8);
                    fflush(stdin);


                    while(fgets(tmp, 500, fp) != NULL){
                        sscanf(tmp,"%[^\n]s\n",tmp);
                        if(strcmp(tmp, data1) == 0){
                            fprintf(fptr,"%s\n",data1);
                            fflush(stdin);
                            fgets(tmp, 500, fp);
                            sscanf(tmp,"%[^\n]s\n",tmp);
                            if(strcmp(tmp,data2) == 0){
                                fprintf(fptr,"%s\n",data2);
                                fflush(stdin);
                                fgets(tmp, 500, fp);
                                fprintf(fptr,"%s\n",data3);
                                fflush(stdin);
                                fgets(tmp, 500, fp);
                                fprintf(fptr,"%s\n",data4);
                                fflush(stdin);
                                fgets(tmp, 500, fp);
                                fprintf(fptr,"%s\n",data5);
                                fflush(stdin);
                                fgets(tmp, 500, fp);
                                fprintf(fptr,"%s\n",data6);
                                fflush(stdin);
                                fgets(tmp, 500, fp);
                                fprintf(fptr,"%s\n",data7);
                                fflush(stdin);
                                fgets(tmp, 500, fp);
                                fprintf(fptr,"%s\n",data8);
                                fflush(stdin);
                            }
                        }else fprintf(fptr, "%s\n", tmp);
                    }
                    fclose(fp);
                    fclose(fptr);

                    fp = fopen("databasePasien.txt","w");
                    fptr = fopen("databases/tmp.txt","r");

                    while(fgets(tmp,500,fptr) != NULL){
                        fprintf(fp,"%s",tmp);
                        fflush(stdin);
                    }             
                    fclose(fp);
                    fclose(fptr);
                }
            }
        }while(pil>2 || pil<1 );
    }
}