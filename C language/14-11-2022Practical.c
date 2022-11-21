
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main()

{
    
    int size, myArray[size];

    printf("What is the size of an array?\n");
    scanf("%d", &size);
    
    
    for(int i=0; i<size; i++){
        myArray[i] = rand()%13-6;
        
        printf("%5d", myArray[i]);
    }
    
    return 0;
}
