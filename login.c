#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"

char nama[101],email[51],ttl[11],ktp[21];

char* lower(char str[]){
   int i;
   for(i=0;i<=strlen(str);i++){
      if(str[i]>=65&&str[i]<=90)
         str[i]=str[i]+32;
   }
    return str;
}
char* upper(char str[]){
    int i;
    for (i = 0; str[i]!='\0'; i++) {
      if(str[i] >= 'a' && str[i] <= 'z') {
         str[i] = str[i] - 32;
      }
   }
    return str;
}

bool eligible(){
    FILE *fp;
    char tmp[101],data[101]; 
    fp = fopen("./databases/dataAdmin.txt","r");
    fflush(stdin);
    printf("Nama                     : ");
    scanf("%[^\n]s",nama);
    lower(nama);
    fflush(stdin);

    printf("Email                    : ");
    scanf("%[^\n]s",email);
    lower(email);
    fflush(stdin);

    printf("Tanggal Lahir(DD/MM/YYYY): ");
    scanf("%[^\n]s",ttl);
    fflush(stdin);

    printf("No. KTP                  : ");
    scanf("%[^\n]s",ktp);
    lower(ktp);
    fflush(stdin);

    while(fgets(tmp,101,fp)!= NULL){
        if(strcmp(tmp,"*****\n") == 0){
            fgets(tmp,101,fp);
            sscanf(tmp,"%101[^\n]\n", &tmp);
            fflush(stdin);
            if(strcmp(tmp,nama) == 0){
                fgets(tmp,51,fp);
                sscanf(tmp,"%51[^\n]\n", &tmp);
                fflush(stdin);
                if(strcmp(tmp,email) == 0){
                    fgets(tmp,11,fp);
                    sscanf(tmp,"%11[^\n]\n", &tmp);
                    fflush(stdin);
                    if(strcmp(tmp,ttl) == 0){
                        fgets(tmp,21,fp);
                        fflush(stdin);
                        fgets(tmp,21,fp);
                        sscanf(tmp,"%21[^\n]\n", &tmp);
                        fflush(stdin);
                        if(strcmp(tmp,ktp) == 0){
                            fclose(fp);
                            return true;
                        }
                    }
                }
            }
        }
    }
    fclose(fp);
    return false;
}


void signup(){
    FILE *fp;
    char username[101],password[101],tmp[101],tmp2[101];
    bool loop = true;
    fp = fopen("./databases/admin.txt","a+");
    printf("Masukkan data untuk memeriksa eligibility:\n");

    if(eligible() == true){
        printf("Masukkan data yang ingin didaftarkan:\n");
        printf("Username: ");
        while(loop == true){
            fflush(stdin);
            scanf("%100[^\n]s",username);
            fflush(stdin);
            while(fgets(tmp,101,fp)!=NULL){
                sscanf(tmp,"%[^\n]\n",tmp2);
                if(strcmp(tmp,tmp2) == 0){
                    break;
                }else{
                    loop = false;
                }
            }

            if(loop == true){
                printf("Username telah terpakai!\n");
            }
        }
        fflush(stdin);
        printf("Password: ");
        scanf("%100[^\n]s",password);
        fflush(stdin);
        fprintf(fp,"*****\n%s\n%s\n",username,password);
    } else{
        printf("Maaf anda belum memenuhi kriteria untuk memiliki akun administrator!\n");
    }
}


bool read(char username[51], char password[51]){
    FILE *fptr;
    char tmp[60], uname[60], pass[60];
    fptr = fopen("./databases/admin.txt","r");
    while(fgets(tmp,60,fptr)!= NULL){
        if(strcmp(tmp,"*****\n") == 0){
            fgets(tmp,60,fptr);
            sscanf(tmp,"%60[^\n]\n", &uname);
            fgets(tmp,60,fptr);
            sscanf(tmp,"%60[^\n]\n", &pass);
            fflush(stdin);
            if(strcmp(uname,username) == 0 && strcmp(pass,password) == 0) {
                fclose(fptr);
                return true;
            }
        }
    }
    fclose(fptr);
    return false;
}

bool signin()
{
    char username[51];
    char password[51];
    FILE *fptr;
    printf("Admin Login\n");
    fflush(stdin);
    printf("Username: ");
    scanf("%[^\n]s",&username);
    fflush(stdin);
    printf("Password: ");
    scanf("%[^\n]s",&password);
    return read(username,password);
}

void addAdmin(){
    printf("Masukkan data admin yang akan ditambah pada database:\n");
    FILE *fptr;
    fptr = fopen("./databases/dataAdmin.txt","a");
    if(eligible() == false){
        fprintf(fptr,"*****\n%s\n%s\n%s\n%s\n",nama,email,ttl,ktp);
    }
    fclose(fptr);
}
