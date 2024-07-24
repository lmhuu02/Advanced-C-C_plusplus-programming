/*
17/8/2022 
power by le minh huu
con tro trong c
*/
#include <stdio.h>

/*truyen con tro - trong c khong co khai niem tham chieu (chi co trong c++)*/
void add(int *a, int *b){
    (*a)++;
    *b = *b + 2;
}

/*truyen tham tri*/
int add1(int a, int b){
    a++;
    b++;
    return a;
}

int main(){
    int a = 4,  b = 12;
    printf("so a: %d, b: %d\n", a, b);
    printf("so goi ham tham tri\n");
    add1(a,b);
    printf("so a: %d, b: %d\n", a, b);
    printf("so goi ham con tro");
    add(&a,&b);
    printf("so a: %d, b: %d\n", a, b);

    return 0;
}