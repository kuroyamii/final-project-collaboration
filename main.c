#include "readPasien.h"
#include "stdio.h"
#include "stdlib.h"
#include "cekCovid.h"
#include "cekPasien.h"
#include "stdbool.h"

void clear();
void pause();
void title();


int main(){
    int pil,pil2,pil3;
    bool loop = true;
    do{
        title();
        printf("Pilih Menu:\n");
        printf("1. Pengunjung\n2. Sign In Admin\n3. Sign Up Admin\n4. Exit\nPilihan: ");
        scanf("%d",&pil);
        title();
        switch(pil){
            case 1:
            {
                if(cekCovid() == true)
                {
                    cekPasien();
                }else{
                    exit(1);
                }
                break;
            }
            case 2:
            {
                if(signin() == true){
                    while(1){
                        title();
                        printf("1. Tambah Admin\n2. Menu Pasien\n3. Log Out\nPilihan: ");
                        scanf("%d",&pil2);
                        title();
                        switch(pil2){
                            case 1:
                                addAdmin();
                                break;
                            case 2:
                            {
                                while(1){
                                    title();
                                    printf("1. Read Data Pasien\n2. Update Data Pasien\n3. Selesai\nPilihan: ");
                                    scanf("%d",&pil3);
                                    title();
                                    switch(pil3){
                                        case 1:
                                            printPasien();
                                            break;
                                        case 2:
                                            updatePasien();
                                            break;
                                        default:
                                            break;
                                    }
                                    if(pil3 == 3) break;
                                    if(pil3 == 1 || pil3 == 2) pause();
                                }
                            }break;
                            default:
                                break;
                        }
                        if(pil2 == 3) break;
                        if (pil2 == 1 || pil2 == 2) pause();
                    }
                }
                else printf("Access Denied!\n");
            }
                break;
            case 3:
                signup();
                break;
            case 4:
                loop = false;
                break;
            default:
                break;
        }
        if (pil == 1 || pil == 2 || pil == 3 ) pause();
    }while(loop == true);
}

void clear(){
    #ifdef _WIN32
        std : system("cls");
    #else
        std : system("clear");
    #endif
}

void pause(){
    char pil[2];
    while(1){
        printf("Apakah anda ingin melanjutkan program?(y/t)\nPilihan: ");
        scanf("%s",&pil);
        lower(pil);
        if(strcmp(pil,"t") == 0 || strcmp(pil,"T") == 0){
            exit(1);
            break;
        }else if(strcmp(pil,"y") == 0 || strcmp(pil,"Y") == 0) break;
    }
}

void title(){
    clear();
    printf("+----------------------------------------------------------+\n");
    printf("|          PROGRAM SIMULASI RUMAH SAKIT SPESIALIS          |\n");
    printf("+----------------------------------------------------------+\n");
}