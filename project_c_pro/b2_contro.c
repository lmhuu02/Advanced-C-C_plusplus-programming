/*
power by le minh huu 17/8/2022
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    /*khai bao con tro*/
    int a = 5;
    int *ptr = NULL;
    
    /*cap phat dong*/
    ptr = (int*)malloc(sizeof(int));
    // ptr = &a;

    printf("\ndia chi cua bien a: %d", &a);
    printf("\ndia chi cua con tro ptr: %d", &ptr);
    printf("\ncon tro ptr tro den a co dia chi: %d ", ptr);
    printf("\ngia tri cua a la: %d", *ptr);
 
    /*nhap mang*/
    int i;
    for( i = 0; i < a; i++){
        printf("\nnhap phan tu %d: ", i+1);
        scanf("%d", ptr+i);
    }
    
    printf("\n");
    /*in mang*/
    for(i = 0; i < a; i++){
        printf("%d\t", *ptr+i);
    }

    /*in dia chi cua mang*/
    printf("\n");
    for(i = 0; i < a; i++){
        printf("%d\t", ptr+i);
    }
    return 0;
}