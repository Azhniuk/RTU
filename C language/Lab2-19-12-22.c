/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>



int main()
{
    for (int i =1; i>0;){
    int x, a, b, y;

    printf("Enter an integer: ");
    scanf("%d", &x);  
    
    a = x * x * x + abs(x);
    b = 7*x + 5;
    printf("Number a = %d\n", a);
    printf("Number b = %d\n", b);
    
    if (a <= b){
        //𝑎(2𝑎 − 𝑏**2)
        y = a * (2*a - b*b);
        printf("y = %d\n", y);
        
    }
    else{
        //2𝑎 − (2/b)
        if (b == 0) {
            printf("Error calculating");
        }
        else{
            y = 2*a - 2/b;
            printf("y = %d\n", y);
        }
        
    }
    printf("1 0\n");
    scanf("%d", &i);
    }
    
}
