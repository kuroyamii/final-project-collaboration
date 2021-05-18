#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


void cekCovid(){
    
    int y,i,a,b,c;
    float GejalaT1, GejalaT2, GejalaT3, sum;
    char persen = '%';
    char sym1[100][255] = {"1.  Suhu diatas 37 derajat", "2.  Batuk kering", "3.  Kelelahan"};
    char sym2[100][255] = {"4.  Rasa tidak nyaman & nyeri", "5.  Nyeri Tenggorokan", "6.  Diare", "7.  Mata merah", "8.  Sakit kepala", "9.  Hilang indra perasa atau penciuman", "10. Perubahan warna pada jari"};
    char sym3[100][255] = {"11. Sesak nafas", "12. Nyeri dada", "13. Hilangnya kemampuan berbicara atau bergerak"};

    printf("KETERANGAN\n");
    printf(">>Masukkan 1 Apabila pernah atau sedang mengalami gejala berikut ");
    printf("\n>>Masukkan 0 Apabila tidak pernah atau tidak sedang mengalami gejala berikut\n\n");
    printf("GEJALA COVID\n");

    y=0;
    for(i=0;i<3;i++)
    {
        printf("%s = ", sym1[i]);
        scanf("%d", &a);
        if(a==1) y++;
    }
    GejalaT1 = (100/3)*y*0.2;

    y=0;
    for(i=0;i<7;i++)
    {
        printf("%s = ", sym2[i]);
        scanf("%d", &b);
        if(b==1) y++;
    }
    GejalaT2 = (100/7)*y*0.3;

    y=0;
    for(i=0;i<3;i++)
    {
        printf("%s = ", sym3[i]);
        scanf("%d", &c);
        if(c==1) y++;
    }
    GejalaT3 = (100/3)*y*0.5;

    sum = GejalaT1 + GejalaT2 + GejalaT3;

    getch();
    system("cls");

    printf("HASIL CEK GEJALA COVID\n");
    printf(">>Persentase terindikasi covid adalah %.2f %c\n", sum, persen);

    if(sum<=10)
    {
        printf(">>Tidak terindikasi covid/Sehat.\n");
        printf(">>Akses masuk diterima!\n");
        printf("\nSilahkan lanjut ke tahap berikutnya.\n");
    }

    else if(sum<=30)
    {
        printf(">>Terindikasi gejala ringan!\n");
        printf(">>Harap melakukan isolasi dan perawatan mandiri di rumah!\n");
        printf(">>Akses masuk diterima!\n");
        printf("\nSilahkan lanjut ke tahap berikutnya.\n");
    }

    else if(sum<=60)
    {
        printf(">>Terindikasi gejala sedang!\n");
        printf(">>Harap segera melakukan pemeriksaan!\n");
        printf(">>Akses masuk ditolak!\n");
        printf("\nSilahkan lanjut ke tahap berikutnya.\n");
    }
    
    else
    {
        printf(">>Terindikasi gejala serius!\n");
        printf(">>Anda memiliki potensi terkena covid!\n>>Harap segera melakukan pemeriksaan!\n");
        printf(">>Akses masuk ditolak!\n");
        printf("\nSilahkan lanjut ke tahap berikutnya.\n");
    }

    getch();
    system("cls");
}