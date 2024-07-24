/*
power by le minh huu 16/11/2022
doc file.txt mang mot chieu,
tinh tong ptru mang, in ds cac so chinh phuong roi ghi ket qua vao filekq.txt
*/
#include <stdio.h>
#include <math.h>

int main(){
    FILE *f;
    int n, arr[10];
    f = fopen("ktc1_docghifile.txt","rt");
    fscanf(f,"%d",&n);
    for(int i = 0; i < n; i++){
        fscanf(f,"%d", &arr[i]);
    }
    fclose(f);
    int tong = 0;
    for(int i = 0; i < n; i++){
        tong += arr[i];
    }
    int temp[10], t = 0;
    for(int i = 0; i < n; i++){
        if((float)sqrt(arr[i]) - (int)sqrt(arr[i]) == 0){
            temp[t] = arr[i]; 
            t++;
        }
    }
    f = fopen("ktc1_docghifile_kq.txt", "wt");
    fprintf(f,"\ntong cac phan tu mang la: %d", tong);
    fprintf(f,"\ndanh sach so chinh phuong la: ");
    for(int i = 0; i < t; i++){
        fprintf(f,"%d\t", temp[i]);
    }
    fclose(f);
}
