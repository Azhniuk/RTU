// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int a, b, S, x, k;
    x = 21;
    k = 0;
    
    printf("Enter two numbers: \n");
    scanf("%d %d", &a, &b);
    
    S = a + b;
    if (S < 20){
        if(S%2 == 0){
            S = S/2;
        }
        else{
            S =(S - 1) /2;
        }
        printf("%d odd numbers", S);
    }
    
    else{
        while (x<=S){
            x+=7;
            k+=1;
        }
        printf("%d numbers", k);
    }

    return 0;
}
