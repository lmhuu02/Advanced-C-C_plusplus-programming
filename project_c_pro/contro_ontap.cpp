/*
power by le minh huu @LeHuu02 @copyright - 15/11/2022 
cau 1 xay dung chuong trinh mang mot chieu su dung con tro
nhap so phan tu mang, nhap xuat mang, tim so duong nho naht
dem co bao nhieu so hoan hao
*/
#include <stdio.h>
#include <math.h>

void sont(int *ptr, int n);
void tongsont(int *ptr, int n);
void sohh(int *ptr, int n);
void socp(int *ptr, int n);
void sapxep(int *ptr, int n);

int main(){
    int n;
    printf("nhap so phan tu mang: ");
    scanf("%d", &n);
    int mang[n];

    //nhap xuat mang
    int *ptr = &mang[0];    //con tro ptr tro den phan tu dau tien cua mang
    printf("nhap phan tu mang: \n");
    for(int i = 0; i < n; i++){
        printf("arr[%d]: ", (i+1));
        scanf("%d", &*(ptr) + i);   // nhap gia tri vao dia chi cua gia tri thu i ma con tro ptr tro den
    }

    //xuat mang
    printf("\nin phan tu mang: ");
    for(int i = 0; i < n; i++){
        printf(" %d\t", *(ptr+i));  //in gia tri thu i cua dia chi ma con tro ptr tro toi
    }

    //tim pahn tu duong nho nhat trong mang
    printf("\n tim phan tu duong nho nhat trong mang");
    int min = *(ptr+0); //gan gia tri min cho gia tri cua dia tri dau tien ma ptr tro den
    int dem = 0, t = 0;
    for(int i = 0; i < n; i++){ 
        if(*(ptr+i) > 0){            
            dem++;  
            //tim phan tu duong nho nhat trong mang
            if(t == 0){
                min = *(ptr+i);
            }
            if(min > *(ptr+i)){
                min = *(ptr+i);
            }   
            t++;         
        }      
    }
    if(dem == 0){
        printf("\nkhong tim thay phan tu duong min vi khong co phan tu duong nao trong mang \n");
    }else{
        printf("\nphan tu duong nho nhat la: %d", min);
    }

    //dem trong mang co bao nhieu so hoan hao la so co tong cac uoc bang chinh no
    int demshh = 0;
    int tonguoc;
    //duyet lan luot tu dau den cuoi mang
    for(int i = 0; i < n; i++){
        tonguoc = 0;
        //kiem tra xem phan tu co phai la so hoan hao hay khong
        for(int j = 1; j < *(ptr+i); j++){
            if(*(ptr+i) % j == 0){
                tonguoc +=j;
            }
        }
        //neu la so hoan hao thi tang bien demshh
        if(tonguoc == *(ptr+i)){
            demshh++;
        }
    }
    if(demshh == 0){
        printf("\nkhong co so hoan hao nao trong mang");
    }else{
        printf("\ntrong mang co tat ca so: %d hoan hao", demshh);
    }

    //tim va tinh tong so nguyen to trong 
    sont(ptr, n);
    tongsont(ptr, n);
    socp(ptr, n);
    sohh(ptr, n);
    sapxep(ptr, n);
    return 0;
}

//snt la so chi chia het cho 1 va chinh no
void sont(int *ptr, int n){
    int demsnt, dem = 0;
    //duyet lan luot mang
    printf("\nso nguyen to co trong mang la: ");
    for(int i = 0; i < n; i++){
        demsnt = 0;
        //kiem tra snt
        for(int j = 1; j <= *(ptr+i); j++){
            if(*(ptr+i) % j == 0){
                demsnt++;
            }
        }
        if(demsnt == 2){
            printf("%d\t", *(ptr+i));
            dem++;
        }
    }
    if(dem == 0){
        printf("\nkhong co so nguyen to trong mang");
    }
}

//tinh tong snt trong mang
void tongsont(int *ptr, int n){
    int demsnt, dem = 0, tong = 0;
    //duyet lan luot mang
    // printf("\nso nguyen to co trong mang la: ");
    for(int i = 0; i < n; i++){
        demsnt = 0;
        //kiem tra snt
        for(int j = 1; j <= *(ptr+i); j++){
            if(*(ptr+i) % j == 0){
                demsnt++;
            }
        }
        if(demsnt == 2){
            // printf("%d\t", *(ptr+i));
            dem++;
            tong += *(ptr+i);
        }
    }
    if(dem == 0){
        printf("\nkhong co so nguyen to trong mang");
    }else{
        printf("\ntong cac so nguyen to trong mang la: %d", tong);
    }
}

//so hoan hao: la so co tong cac uoc bang chinh no
void sohh(int *ptr, int n){
    int tonguoc, dem = 0;
    printf("\nso hoan hao trong mang la: ");
    for(int i = 0; i < n; i++){
        tonguoc = 0;
        for(int j = 1; j < *(ptr+i); j++){
            if(*(ptr+i) > 0 && *(ptr+i) % j == 0){
                tonguoc += j;
            }
        }
        if(tonguoc == *(ptr+i)){
            printf("%d\t", *(ptr+i));
            dem++;
        }
    }
    if(dem == 0){
        printf("\ntrong mang khong co so hoan hao");
    }
}

//so chinh phuong: la gia tri binh phuong cua mot so bat ky
void socp(int *ptr, int n){
    int dem = 0;
    printf("\nso chinh phuong trong mang la: ");
    for(int i = 0; i < n; i++){
        if(*(ptr+i) > 0 && (float)sqrt(*(ptr+i)) - (int)sqrt(*(ptr+i)) == 0){
            printf("%d\t", *(ptr+i));
            dem++;
        }
    }
    if(dem == 0){
        printf("\nkhong co so chinh phuong trong mang ");
    }
}

//sap xep mang tang dan
void sapxep(int *ptr, int n){
    int temp;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(*(ptr+i) > *(ptr+j)){
                temp = *(ptr+i);
                *(ptr+i) = *(ptr+j);
                *(ptr+j) = temp;
            }
        }
    }
    printf("\nmang sau khi sap xep tang: ");
    for(int i = 0; i < n; i++){
        printf("%d\t", *(ptr+i));
    }
}