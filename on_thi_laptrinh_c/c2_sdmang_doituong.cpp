/*
power by le minh huu 21/11/2022 @LeHuu02 @copyright
yeu cau:
    - tao mot ds mang doi sinh vien: ma sv, ten sv, dia chi, diem
    - nhap xuat ds sinh vien, in thong tin sv diem < 5, tim sv co dia chi tai thai nguyen 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sinhvien{
    char ten[100];
    char masv[100];
    char diachi[100];
    float diem;
};
void nhap(sinhvien sv[], int n){
    
    printf("\nnhap thong tin sinh vien");
    for(int i = 0; i < n; i++){
        printf("\nsinh vien thu: %d", i+1);
        fflush(stdin);
        printf("\nnhap ma sinh vien: ");
        gets(sv[i].masv);
        printf("nhap ten sinh vien: ");
        gets(sv[i].ten);
        printf("nhap dia chi: ");
        gets(sv[i].diachi);
        printf("nhap diam sinh vien: ");
        fflush(stdin);
        scanf("%f", &sv[i].diem);
    }
}
void xuat(sinhvien sv[], int n){
    printf("\nin thong tin sinh vien vua nhap: ");
    printf("\n============================\n");
    for(int i = 0; i < n; i ++){
        printf("\nten:  %s\tma sv: %s\tdia chi: %s\tdiem: %.2f", sv[i].ten, sv[i].masv, sv[i].diachi, sv[i].diem);
    }
}
void insv(sinhvien sv[], int n){
    for(int i = 0; i < n; i++){
        if(sv[i].diem < 5){
            printf("\nten:  %s\tma sv: %s\tdia chi: %s\tdiem: %.2f", sv[i].ten, sv[i].masv, sv[i].diachi, sv[i].diem);
        }
    }
}
void svthainguyen(sinhvien sv[], int n){
    for(int i = 0; i < n; i++){
        if(strcmp(sv[i].diachi, "thai nguyen") == 0){
            printf("\nten:  %s\tma sv: %s\tdia chi: %s\tdiem: %.2f", sv[i].ten, sv[i].masv, sv[i].diachi, sv[i].diem);
        }
    }
}
void xoasv2(sinhvien sv[], int *n){  //xoa sinh vien thu 2

    for(int i = 1; i < *n; i ++){
        sv[i] = sv[i+1];
    }
    *n -=1;
}
int main(){
    int n = 0;
    printf("\nnhap so sinh vien: ");
    scanf("%d", &n);
    sinhvien sv[n];
    nhap(sv, n);
    xuat(sv, n);
    printf("\nin sinh vien co diem nho hon 5");
    insv(sv, n);
    printf("\nin thong tin sinh vien song tai thai nguyen: ");
    svthainguyen(sv, n);
    xoasv2(sv, &n);
    printf("\ndanh sach sau khi da xoa sinh vien thu 2: %d ", n);
    xuat(sv, n);
    return 0;
}
