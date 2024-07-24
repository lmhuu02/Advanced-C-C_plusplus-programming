#include <stdio.h>

bool test(int a){
    return(!!a);
}

int main(){
    int a = 0;
    printf("tra ve: %d ", test(a));

    int n = 309;
    for(int i = 0; i < 309; i++){
        printf("%d", i);
    }
}