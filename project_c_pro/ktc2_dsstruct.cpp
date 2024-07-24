/*
power by le minh huu @LeHuu02 @copyright 16/11/2022
nhap  va hien thi thong tin danh sach vat tu
    in thong tin vat tu cua nha cung cap thai nguyen
    tim kiem vat tu duoc nhap ngay 26/4/2019
*/
#include <stdio.h>
#include <string.h>

struct vattu{
    char mavt[100];
    char ten[100];
    char tencungcap[100];
    int soluong;
    int dongia; 
    char ngaynhap[100];
    char ngayxuat[100];
    // struct ngaynhap{
    //     int nngay;
    //     int nthang;
    //     int nnam;
    // };
    // struct ngayxuat{
    //     int xngay;
    //     int xthang;
    //     int xnam;
    // };
    // ngaynhap nhap;
    // ngayxuat xuat;
};

int main(){
    vattu vt[100];
    //nhap danh sach vat tu
    int n;
    printf("nhap vao so luong vat tu: ");
    scanf("%d",  &n);
    for(int i = 0; i < n; i++){
        printf("\nvat tu %d: ", (i+1));
        printf("\nnhap ma vat tu: ");
        fflush(stdin);
        gets(vt[i].mavt);
        printf("nhap vao ten vat tu: ");
        gets(vt[i].ten);
        printf("nhap ten cung cap: ");
        gets(vt[i].tencungcap);
        fflush(stdin);
        // printf("nhap ngay: ");
        //     scanf("%d", &vt[i].nhap.nngay);
        //     scanf("%d", &vt[i].nhap.nthang);
        //     scanf("%d", &vt[i].nhap.nnam);
        // printf("ngay xuat: ");
        //     scanf("%d", &vt[i].xuat.xngay);
        //     scanf("%d", &vt[i].xuat.xthang);
        //     scanf("%d", &vt[i].xuat.xnam);
        printf("nhap ngay: ");
        gets(vt[i].ngaynhap);
        printf("xuat ngay: ");
        gets(vt[i].ngayxuat);
        printf("nhap don gia: ");
        scanf("%d", &vt[i].dongia);
        printf("nhap so luong: ");
        scanf("%d", &vt[i].soluong);
        // scanf("%")
    }
    //xuat danh sach vat tu:
    printf("\nXUAT DANH SACH:   ");
    for(int i = 0; i < n; i++){
        printf("\nma vt: %s\tten vt: %s\tten nha cung cap: %s", vt[i].mavt, vt[i].ten, vt[i].tencungcap);
        printf("\nso luong: %d\tdon gia: %d\t ngay nhap: %s\t ngay ban: %s", vt[i].soluong, vt[i].dongia, vt[i].ngaynhap, vt[i].ngayxuat);
        // printf("\nso luong: %d\tdon gia: %d\t ngay nhap: %d/%d/%d\t ngay ban: %d/%d/%d", vt[i].soluong, 
        // vt[i].dongia), vt[i].nhap.nngay, vt[i].nhap.nthang, vt[i].nhap.nnam, vt[i].xuat.xngay, vt[i].xuat.xthang, vt[i].xuat.xnam;         
    }

    //in thong tin vat tu tu tai thai nguyen
    int dem = 0;
    printf("\n\nthong tin vat tu tu nha cung cap thai nguyen");
    for(int i = 0; i < n; i++){
        if(strcmp(vt[i].tencungcap , "thai nguyen") == 0){
            printf("\nma vt: %s\tten vt: %s\tten nha cung cap: %s", vt[i].mavt, vt[i].ten, vt[i].tencungcap);
            printf("\nso luong: %d\tdon gia: %d\t ngay nhap: %s\t ngay ban: %s", vt[i].soluong, vt[i].dongia, vt[i].ngaynhap, vt[i].ngayxuat);
            dem++;
        }
    }
    if(dem ==0){
        printf("\nkhong co nha cung cap vat tu nao tai thai nguyen:");
    }

    //tim kiem vat tu duoc nhap ngay 26/4/2019
    int demvt = 0;
    printf("\n\nthong tin vat tu nhap ngay 26 4 2019");
    for(int i = 0; i < n; i++){
        if(strcmp(vt[i].ngaynhap , "26 4 2019") == 0){
            printf("\nma vt: %s\tten vt: %s\tten nha cung cap: %s", vt[i].mavt, vt[i].ten, vt[i].tencungcap);
            printf("\nso luong: %d\tdon gia: %d\t ngay nhap: %s\t ngay ban: %s", vt[i].soluong, vt[i].dongia, vt[i].ngaynhap, vt[i].ngayxuat);
            demvt++;
        }
    }
    if(demvt ==0){
        printf("\nkhong co vat tu nao nhap ngay 26 4 2019:");
    }

    return 0;
}