/*
power by le minh huu @LeHuu02 @copyright - 15/11/2022
thao tac voi file trong c
doc mang mot chieu ghi vao file.txt 
thuc hien
    tim phan tu nho nhat va tim so chinh phuong
    ghi cac gia tri vua tim duoc vao file
*/
#include <stdio.h>
#include <math.h>

int main(){
    FILE *f;

    //doc du lieu tu file .txt
    int i, n, tong = 0, arr[10];
    f = fopen("ontap_file.txt", "rt");  //cho con tro file f tro den file ontap_file.txt
    fscanf(f, "%d", &n);    //doc phan tu dau tien trong file. vi tri con tro f va ghi vao bien n
    printf("so phan tu mang la: n = %d", n);
    
    //doc n gia tri tiep theo trong file
    for(i = 0; i < n; i++){
        fscanf(f,"%d",&arr[i]); //doc gia tri trong file roi ghi vao mang arr
    }
    fclose(f);  //doc xong file thi dong file lai
    
    //lay gia tri trong mang vua luu tinh tong
    printf("\nmang vua nhap la: ");
    for(i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
    
    //tinh tong mang
    for(i = 0; i < n; i++){
        tong += arr[i];
    }

    //tim min trong mang ghi vao file    
    int min = arr[0];
    for(i = 1; i < n; i++){
        if(min > arr[i]){
            min = arr[i];
        }
    }
    
    //tim cac so chinh phuong trong mang ghi vao file. so chinh phuong la binh phuong cua mot so
    int acp[100], dem = 0;
    fprintf(f, "\nso chinh phuong trong mang la: ");
    for(i = 0; i < n; i++){
        //kiem tra so chinh phuong
        if((float)sqrt(arr[i]) - (int)sqrt(arr[i]) == 0){
            acp[dem] = arr[i];
            dem++;                                                                                                                                                                                                                                                                                                                                                                                 
            // fprintf(f," %d \t", arr[i]);    //ghi lan luot so chinh phuong vao file
        }
    }

    //sap xep lai mang tang dan va giam dan roi ghi vao file 
    int temp ;
    for(i = 0; i < n-1; i++){ //sap xep tang dan
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[i] ){   //neu so sau nho hon so truoc
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

    }

    // ghi gia tri tong vua tinh vao file .txt
    f = fopen("ontap_file_kq.txt", "wt");
    fprintf(f, "tong = %d", tong);
    fprintf(f, "\nxin chao cac ban");
    
    //mang sau khi da sap xep tang dan
    fprintf(f,"\nmang sau khi sap xep tang: ");
    for(i = 0; i < n; i++){
        fprintf(f," %d\t", arr[i]);
    }
    
    //ghi gia tri min vao file kq.txt
    fprintf(f, "\ngia tri min: %d ", min);
    fprintf(f, "\ncac so chinh phuong trong mang la: ");
    for(i = 0; i < dem; i++){
            fprintf(f," %d \t", acp[i]);    //ghi lan luot so chinh phuong vao file
    }
    fclose(f);
    return 0;
}