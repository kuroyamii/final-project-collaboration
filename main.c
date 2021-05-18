#include "readPasien.h"
#include "stdio.h"
#include "stdbool.h"

void clear();


int main(){
    int pil,pil2;
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
                        printf("1. Read Data Pasien\n2. Update Data Pasien\n3. Selesai\nPilihan: ");
                        scanf("%d",&pil2);
                        switch(pil2){
                            case 1:
                                printPasien();
                                break;
                            case 2:
                                updatePasien();
                                break;
                            case 3:
                                break;
                            default:
                                break;
                        }
                        if(pil2 == 3) break;
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
    }while(loop == true);
}

void clear(){
    #ifdef _WIN32
        std : system("cls");
    #else
        std : system("clear");
    #endif
}