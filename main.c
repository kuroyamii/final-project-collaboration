#include "readPasien.h"
#include "stdio.h"
#include "stdbool.h"

void clear();
void pause();

int main(){
    int pil,pil2,pil3;
    bool loop = true;
    do{
        printf("Pilih Menu:\n");
        printf("1. Pengunjung\n2. Sign In Admin\n3. Sign Up Admin\n4. Exit\nPilihan: ");
        scanf("%d",&pil);
        switch(pil){
            case 1:
                break;
            case 2:
            {
                if(signin() == true){
                    while(1){
                        printf("1. Tambah Admin\n2. Menu Pasien\n3. Log Out\nPilihan: ");
                        scanf("%d",&pil2);
                        switch(pil2){
                            case 1:
                                addAdmin();
                                break;
                            case 2:
                            {
                                while(1){
                                    printf("1. Read Data Pasien\n2. Update Data Pasien\n3. Selesai\nPilihan: ");
                                    scanf("%d",&pil3);
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
                        if(pil2 == 3) break;
                        }
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
        if (pil == 1 || pil == 2 || pil == 3) pause();
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