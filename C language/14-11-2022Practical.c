
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main()

{
    int size, SUM = 0, max;
   

    printf("What is the size of an array?\n");
    scanf("%d", &size);
    int  myArray[size];
    srand ( time(NULL) ); //for numbers to be random every time
    
    
    for(int i = 0; i < size; i++){
        myArray[i] = rand() % 13 -6;
        SUM += myArray[i];
        printf(" %d ", myArray[i] );
    }
    
    printf("\nThe average is:  %d ", SUM/size);
    
    max = myArray[0];
    
    for(int i = 0; i < size; i++){
        if (myArray[i] > max){
            max = myArray[i];
        }
    }
    
    printf("\nMaximum is:  %d ", max);
    
    return 0;
}