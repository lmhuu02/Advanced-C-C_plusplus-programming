/*
power by le minh huu @LeHuu02 @copyright 16/11/2022
su dung con tro voi mang hai chieu
    nhap ptu mang, nhap xuat mang
    tim so nguyen to
        tinh tong cheo chinh
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void nhapxuat(int *arr, int m, int n){
    printf("nhap mang: \n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("arr[%d][%d]: ", i, j);
            scanf("%d", (arr +i*m +j));
        }
    }
    printf("\nxuat mang: \n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d\t",*(arr +i*m +j));            
        }
        printf("\n");
    }
}

void sont(int *arr, int m, int n){
    printf("\nin so nguyen to trong mang: \n");
    int dem = 0, demsnt;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
           demsnt = 0;
            for(int x = 1; x <= *(arr +i*m +j); x++ ){
                if(*(arr +i*m +j) % x == 0){
                    demsnt++;
                }
            }
            if(demsnt == 2){
                printf("%d\t", *(arr +i*m +j));
                dem++;
            }
        }
    }
    if(dem == 0){
        printf("\nkhong co so nguyen to trong mang");
    }
}

void tongcheochinh(int *arr, int m, int n){    
   int tongcheochinh = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                tongcheochinh += *(arr +i*m +j);
            }                  
        }
    }
    printf("\ntong cheo chinh trong mang la: %d", tongcheochinh);
}

int main(){
    int m, n;
    printf("nhap vao so phan tu mang m x n: ");
    scanf("%d%d", &m,&n);
    int *arr;
    arr = (int*)malloc(m*n*sizeof(int));
    nhapxuat(arr, m, n);
    sont(arr, m, n);
    tongcheochinh(arr, m, n);
    return 0;
}