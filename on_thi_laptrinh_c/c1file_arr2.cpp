/*
power by le minh huu 23/11/2022 @LeHuu02 @copyright
yeu cau: 
        - doc mang 2 chieu tu file
        - tinh tong duong cheo chinh va duong cheo phu 
        - ghi ket qua vao file
    
    NOTE: FILE *f
            f = fopen("ten file", "rt/wt");
            fclose(f);
            fscanf(f,"%d", &n);
            fprintf(f,"noi dung");
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    /*doc du lieu mang tu file*/
    FILE *f;
    f = fopen("c1file_arr2.txt", "rt");
    int m, n, arr[10][10];
    fscanf(f,"%d", &n);
    fscanf(f,"%d", &m);
    for(int i = 0; i <n; i++){
        for(int j = 0; j < m; j++){
            fscanf(f,"%d", &arr[i][j]);
        }
    }
    fclose(f);
    /*tinh tong cheo chinh cheo phu*/
    int tongchinh =0, tongphu = 0;
    for(int i = 0; i <n; i++){
        for(int j = 0; j < m; j++){
            if(i == j){
                tongchinh += arr[i][j];
            }
            if(j + i == n-1){
                tongphu += arr[i][j];
            }
        }
    }
    /*ghi du lieu vao file*/
    f = fopen("c1file_arr2kq.txt", "wt");
    fprintf(f,"\ntong cheo chinh la: %d", tongchinh);
    fprintf(f,"\ntong cheo phu la: %d", tongphu);
    fclose(f);
    return 0;
}
