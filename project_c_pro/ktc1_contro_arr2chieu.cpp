/*
power by le minh huu @LeHuu02 @copyright - 15/10/2022
ktra mang hai chieu dung CON TRO - POINTER
yeu cau:   
    nhap ptu mang, nhap xuat mang
    tim so chinh phuong
    tinh tong so 2 so va co hang dv = 7
    ERROR - ERROR - ERROR - ERROR - ERROR
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void nhapxuat(int *ptr, int n, int m);
void insocp(int *ptr, int n, int m);
void tinhtong(int *ptr, int n, int m);

int main(){
    int n, m;
    int arr[m][n];
    printf("nhap m x n phan tu mang: ");
    scanf("%d", &m);
    scanf("%d", &n);
    int *ptr = &arr[0][0];
    ptr = (int*)malloc(m*n*sizeof(int));
    nhapxuat(ptr, n, m);
    insocp(ptr, n, m);
    tinhtong(ptr, n, m);
    return 0;
}

//ham nhap xuat mang hai chieu
void nhapxuat(int *ptr, int n, int m){
    int i, j;
    //nhap mang
    printf("\nnhap phan tu mang: \n");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("arr[%d][%d]: ", i, j);
            scanf("%d", ((ptr + i*n)+j));
        }
    }
    //xuat mang
    printf("\nphan tu mang vua nhap la: \n");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("%d\t", *((ptr+i*n)+j));                        
        }
        printf("\n");
    }

}

//ham in so chinh phuong
void insocp(int *ptr, int n, int m){
    //in so chinh phuong trong mang
    int i, j, dem = 0;
    float temp ;
    printf("\nso chinh phuong trong mang: ");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            temp = (float)sqrt(*(ptr+i*n+j)) - (int)sqrt(*(ptr+i*n+j));
            if(temp == 0){
                printf("%d\t", *(ptr+i*n+j));
                dem++;
            }
        }
    }
    if(dem == 0){
        printf("\nkhong co so chinh phuong trong mang: ");
    }
}

//ham tinh tong 
void tinhtong(int *ptr, int n, int m){
    int i, j, tong = 0;
    int dem = 0;
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            if(*(ptr+i*n+j) > 10 && *(ptr+i*n+j) < 99){
                tong += *(ptr+i*n+j);
                dem++;
            }
        }
    }
    if(dem == 0){
        printf("\nkhong co phan tu nao hai chu so va dv = 7 ");
    }else{
        printf("\ntong cac phan tu hai chu so, dv = 7 la: %d", tong);
    }

}



// //RUN OK
// /*
// power by le minh huu 16/11/2022 @LeHuu02 @copyright 
// CON TRO POINTER VOI MANG HAI CHIEU  
//     nhap xuat mang 2 chieu
//     in so chinh phuong: so co gia tri la binh phuong cua 1 so
//     tinh tong cac so 2 so co dv = 7
// */
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// 
// void test(int *a){
//     for(int i = 0; i < 3; i++){
//         for(int j = 0; j < 3; j++){
//             scanf("%d", a+i*3+j);
// 
//         }
//     }
//     for(int i = 0; i < 3; i++){
//         for(int j = 0; j < 3; j++){
//             printf("%d\t", *(a+i*3+j));            
//         }
//         printf("\n");
//     }
// }
// void socp(int*a){
//     int i, j, dem = 0;
//     float temp ;
//     printf("\nso chinh phuong trong mang: ");
//     for(i = 0; i < 3; i++){
//         for(j = 0; j < 3; j++){            
//             temp = (float)sqrt(*(a+i*3+j)) - (int)sqrt(*(a+i*3+j));
//             if(temp == 0){
//                 printf("%d\t", *(a+i*3+j));
//                 dem++;
//             }
//         }
//     }
//     if(dem == 0){
//         printf("\nkhong co so chinh phuong trong mang: ");
//     }
// }
// void tong(int *a){
//     int i, j, tong = 0;
//     for(i = 0; i < 3; i++){
//         for(j = 0; j < 3; j++){
//             if(*(a+i*3+j) < 99 && *(a+i*3+j) > 10){
//                 if(*(a+i*3+j) % 10 == 7){
//                     tong += *(a+i*3+j);
//                 }
//             }            
//         }
//     }
//     printf("\ntong phan tu mang hai chu so co hang don vi bang 7 la: %d ", tong);
// }
// 
// int main(){
//     int *a;
//     a = (int*)malloc(3*3*sizeof(int));
//     test(a);
//     socp(a);
//     tong(a);
// }
