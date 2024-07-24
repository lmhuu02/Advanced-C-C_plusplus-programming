/*
ERROR ERROR: STRUCT NOT RUN IN FILE.C BUT IT RUN IN FILE .CPP
power by le minh huu 6/9/2022
struct cong nhan
*/    
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct nguoi{
    char name[49];
    int old;
    char address[59];
    char job[59];
};

/*function nhap thong tin 1 nguoi*/
void nhap1cn(nguoi &congnhan1)
{
    printf("nhap thong tin nguoi: \n");
    printf("ten: ");
    gets(congnhan1.name);
    printf("tuoi: ");
    scanf("%d", &congnhan1.old);
    printf("dia chi: ");
    fflush(stdin);
    gets(congnhan1.address);
    printf("cong viec: ");
    gets(congnhan1.job);
}

/*function xuat thong tin 1 nguoi*/
void xuat1cn(nguoi congnhan1)
{
    printf("\n---------------- THONG TIN ------------------\n");
    printf("ten: %s\t\t", congnhan1.name);
    printf("dia chi: %s\t\t", congnhan1.address);
    printf("\ntuoi: %d\t\t", congnhan1.old);
    printf("cong viec: %s\t\t", congnhan1.job);
}

/*function nhap thong tin n nguoi*/
void nhap(nguoi cn[], int n)
{
    int i;
    /*nhap n nguoi cn*/
    for(i = 0; i < n; i++)
    {
        printf("----------thong tin nguoi: %d ------------\n", i+1);
        printf("nhap thong tin nguoi: \n");
        printf("ten: ");
        fflush(stdin);
        gets(cn[i].name);
        printf("tuoi: ");
        scanf("%d", &cn[i].old);
        printf("dia chi: ");
        fflush(stdin);
        gets(cn[i].address);
        printf("cong viec: ");
        gets(cn[i].job);    
    }

}

/*function xuat thong tin n nguoi*/
void xuat(nguoi cn[], int n)
{
    int i;
    /*in n nguoi cn*/
    for(i = 0; i < n; i++)
    {
        printf("\n---------------- THONG TIN ------------------\n");
        printf("ten: %s\t\t", cn[i].name);
        printf("dia chi: %s\t\t", cn[i].address);
        printf("\ntuoi: %d\t\t", cn[i].old);
        printf("cong viec: %s\t\t", cn[i].job);

    }
    
}

int main()
{
    /*nhap xuat thong tin struct cho 1 nguoi*/
    // nguoi congnhan1;
    // nhap1cn(congnhan1);
    // xuat1cn(congnhan1);

    /*nhap xuat thong tin cho n nguoi*/
    int n,i;
    printf("nhap so nguoi: ");
    scanf("%d", &n);
    nguoi cn[n];
    
    /*call funtion nhap xuat*/
    nhap(cn, n);
    xuat(cn, n);

    return 0;
}
