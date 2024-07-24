/*
le minh huu 6/9/2022
b1. nhap vao 2 so a,b hien thi tong thieu tich thuong
b2. doi gia tri cua 2 so nhap tu ban phim
b3. con tro voi mang 1 chieu
    - nhap mang
    -hien thi mang
    tinh tong phan tu mang
    sap xep lai mang theo chieu tang dan
*/

#include <stdio.h>
#include <stdlib.h>

void bai1(int *ptra, int *ptrb)
{
    int tong = 0, hieu = 0, tich = 0;
    float thuong = 0;
    tong = *ptra + *ptrb;
    hieu = *ptra - *ptrb;
    tich = (*ptra) * (*ptrb);
    if(*ptrb > 0)
    {
        thuong = (float)(*ptra)/(float)(*ptrb);
        printf("\nthuong: %f", thuong);
    }else{
        printf("\nerror\n");
    }

    printf("\ntong: %d", tong);
    printf("\nhieu: %d", hieu);
    printf("\ntich: %d", tich);
    
}

void bai2(int *ptra, int *ptrb)
{
    int temp = *ptra;
    *ptra = *ptrb;
    *ptrb = temp;

}

void nhap_mang(int *mang, int n)
{
    int i;
    printf("\nnhap mang\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", mang+i);
    }

}

void xuat_mang(int *mang, int n)
{
    printf("\nin ra mang vua nhap: \t");
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d\t", *(mang+i));
    }
}

void tong_mang(int *mang, int n)
{
    printf("\ntong cac phan tu trong mang vua nhap: \t");
    int i;
    int tong = 0;
    for(i = 0; i < n; i++)
    {
        tong = tong + *(mang+i);
    } 
    printf("%d\t", tong);
}

void sapxep_mang(int *mang, int n)
{
    int temp = mang[0];
    int i,j;
    for(i = 0; i < n - 1; i++)
    {
        for(j= i+1; j < n; j++)
        {
            if(*(mang + i) > *(mang +j))
            {
                temp = *(mang + i);
                *(mang + i) = *(mang + j);
                *(mang + j) = temp;
            }
        }
    }
}

int main()
{
    // int *ptra = NULL;
    // int *ptrb = NULL;

    // /*cap phat dong con tro a, b*/
    // ptra = (int*)malloc(sizeof(int));
    // ptrb = (int*)malloc(sizeof(int));
     
    // int a = 0, b = 0;
    // ptra = &a;
    // ptrb = &b;

    int mang[10];
    int n;
    printf("nhap so phan tu mang: ");
    scanf("%d", &n);

    nhap_mang(mang,n);
    xuat_mang(mang,n);
    tong_mang(mang,n);
    sapxep_mang(mang,n);
    printf("\nmang sau khi sap xep: \n");
    xuat_mang(mang,n);
    /*nhap vao hai so  a b*/
    // printf("nhap so a, b: ");
    // scanf("%d%d", ptra, ptrb);
    // printf("\nso a b nhap: %d,%d", *ptra,*ptrb);
    // bai1(ptra,ptrb);
    // bai2(ptra,ptrb);
    // printf("\nso a, b hoan doi: %d,%d", *ptra,*ptrb);


    return 0;
}