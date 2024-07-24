/*
power by le minh huu 22/11/2022 @LeHuu02 @copyright
yeu cau:
 đọc ghi dữ liệu vào file.txt
        - đọc mảng 1 chiều từ file.txt
        - thực hiện tính tổng mảng vừa đọc
        - thực hiện các phép toán trong mảng 1 chiều: số nt, cp, hh, xắp sếp, min max,...
        - ghi kết quả vừa thực hiện được vào file_kq.txt
    nhung lenh va ham lien quan: 
        FILE *f: tao con tro file
        f = fpen("ten file", "wt/rt")
        fclose(f): dong con tro file
        fscanf(f,"%d", &n): ghi du lieu tu vi tri con tro f trong file vao bien n
        fprintf("f,"noi dung"): ghi du lieu vao file
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void tongmang(int arr[], int n){
    int tong = 0;
    for(int i = 0; i < n; i++){
        tong += arr[i];
    }
    printf("\ntong cac phan tu trong mang la: %d", tong);
}
void sapxeptang(int arr[], int n){
    int temp;
    for(int i = 0; i < n -1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int minmax(int arr[], int n){
    int min = arr[0];
    for(int i = 1; i < n; i++){
        if(min > arr[i]){
            min = arr[i];
        }
    }
    printf("\n min: %d", min);
    return min;
}
void socp(int arr[], int n, int temp1[], int &t1){
    int dem = 0;
    printf("\nso chinh phuong trong mang la: ");
    for(int i = 0; i < n; i++){
        if((float)sqrt(arr[i]) - (int)sqrt(arr[i]) == 0){
            temp1[dem] = arr[i];
            printf("%d\t", arr[i]);
            dem++;
            t1 = dem;
        }
    }
}
void sohh(int arr[], int n, int temp2[], int &t2){
    int tonguoc = 0, dem = 0, tang = 0;
    printf("\nso hoan hao trong mang la: ");
    for(int i = 0; i < n; i++){
        tonguoc = 0;
        for(int j = 1; j < arr[i]; j++){
            if(arr[i] % j == 0){
                tonguoc += j;
            }
        }
        if(tonguoc == arr[i]){
            temp2[tang] = arr[i];
            printf("%d\t", arr[i]);            
            tang++;
            t2 = tang;
        }
    }
}
void sont(int arr[], int n, int temp3[], int &t3){
    int dem, tang = 0;
    printf("\nso nguyen to trong mang la: ");
    for(int i = 0; i < n; i++){
        dem = 0;
        for(int j = 1; j <= arr[i]; j++){
            if(arr[i] % j == 0){
                dem++;
            }
        }
        if(dem == 2){
            temp3[tang] = arr[i];
            printf("%d\t", arr[i]);        
            tang++;
            t3 = tang;
        }
    }
}
int main(){
    FILE *f = fopen("c1_file_arr1.txt", "rt");
    int n, arr[100];
    int temp1[100], temp2[100], temp3[100];
    int t1, t2, t3;
    fscanf(f,"%d", &n);
    for(int i = 0; i < n; i++){
        fscanf(f,"%d", &arr[i]);        
    }
    fclose(f);
    tongmang(arr, n);
    sapxeptang(arr, n);
    minmax(arr, n);
    socp(arr, n, temp1, t1);
    sohh(arr, n, temp2, t2);
    sont(arr, n, temp3, t3);
    f = fopen("c1_file_arr1_kq.txt", "wt");
    fprintf(f,"\nmang sau khi sap xep tang la: ");
    for(int i = 0; i < n; i++){
        fprintf(f,"%d\t",arr[i] );
    }
    fprintf(f,"\ngia tri min trong mang la: %d", minmax(arr,n));
    fprintf(f,"\nso chinh phuong trong mang la: ");
    for(int i = 0; i < t1; i++){
        fprintf(f,"%d\t", temp1[i]);
    }
    fprintf(f,"\nso hoan hao trong mang la: ");
    for(int i = 0; i < t2; i++){
        fprintf(f,"%d\t", temp2[i]);
    }
    fprintf(f,"\nso nguyen to trong mang la: ");
    for(int i = 0; i < t3; i++){
        fprintf(f,"%d\t", temp3[i]);
    }
    fclose(f);

    return 0;
}