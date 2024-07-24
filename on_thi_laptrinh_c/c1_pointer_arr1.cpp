
/*
power by le minh huu 22/11/2022 @LeHuu02 @copyright
yeu cau:
    con trỏ với mảng 1 chiều 
             - nhập n, nhập xuất mảng
             - tìm và tính tổng số nguyên tố, chinh phương, hoàn hảo. 
             - xắp sếp tăng dần giảm dần, tim min max. 
             - tổng các số chia hết cho 2 3 5,... số 2 số có đơn vị = 7,...
    NOTE:   
        * la gia tri
        & la dia chi
        phai cap phat bo nho dong cho bien con tro mang. khong se khong hoat dong
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sont(int *arr, int n){
    int dem = 0, tong = 0;
    printf("\nso nguyen to trong mang la: ");
    for(int i = 0; i < n; i++){
        dem = 0;
        for(int j = 1; j <= *(arr+i); j++){
            if(*(arr+i) % j == 0){
                dem++;
            }
        }
        if(dem == 2){
            printf("%d\t", *(arr+i));
            tong += *(arr + i);
        }
    }
    printf("\ntong so nguyen to trong mang la: %d", tong);
}
void sohh(int *arr, int n){
    int tong = 0, tonguoc = 0;
    printf("\nso hoan hao trong mang la: ");
    for(int i = 0; i < n; i++){
        tonguoc = 0;
        for(int j = 1; j < *(arr+i); j++){
            if(*(arr+i) % j == 0){
                tonguoc += j;
            }
        }
        if(tonguoc == *(arr+i)){
            printf("%d\t", *(arr+i));
            tong += *(arr+i);
        }
    }
    printf("\ntong cac so hoan hao trong mang la: %d", tong);
}
void socp(int *arr, int n){
    int tong = 0;
    printf("\nso chinh phuong trong mang la: ");
    for(int i = 0; i < n; i++){
        if((float)sqrt(*(arr+i)) - (int)sqrt(*(arr+i)) == 0){
            printf("%d\t", *(arr+i));
            tong += *(arr+i);
        }
    }
    printf("\ntong cac so chinh phuong trong mang la: %d", tong);
}
void minmax(int *arr, int n){
    int min = *(arr+0);
    for(int i = 1; i < n; i++){
        if(*(arr+i) < min){
            min = *(arr+i);
        }
    }
    printf("\nmin trong mang la: %d", min);
}
void sapxeptang(int *arr, int n){
    int temp;
    printf("\n mang sau khi sap xep tang: ");
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(*(arr+i) > *(arr+j)){
                temp = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = temp;
            }
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d\t", *(arr + i));
    }
}
void tong2sodv7(int *arr, int n){
    int tong = 0;
    for(int i = 0; i < n; i++){
        if(*(arr+i) < 99 && *(arr+i) > 10){
            if(*(arr+i) % 10 == 7){
                tong += *(arr+i);
            }
        }
    }
    printf("\ntong cac phan tu 2 ao don vi 7: %d", tong);
}
int main(){
    int *arr;
    int n, i;
    printf("\nnhap so phan tu mang: ");
    scanf("%d", &n);
    arr = (int*)malloc(n*sizeof(int));
    for(i = 0; i < n; i++){
        printf("\nphan tu %d: ", i+1);
        scanf("%d", (arr + i));
    }
    printf("\nin phan tu mang vua nhap: ");
    for(i = 0; i < n; i++){
        printf("%d\t", *(arr + i));
    }
    sont(arr, n);
    sohh(arr, n);
    socp(arr, n);
    minmax(arr, n);
    sapxeptang(arr, n);
    tong2sodv7(arr, n);
    return 0;
}