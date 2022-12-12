/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void output( int drow, int dcol, int arr[drow][dcol]) {
    for (int i = 0; i < drow; i++){
        for (int j = 0; j < dcol; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n"); 
    }
}

void min( int drow, int dcol, int arr[drow][dcol]) {
    int min = arr[0][0];
    for (int i = 0; i < drow; i++){
        for (int j = 0; j < dcol; j++) {
            if (min > arr[i][j]){
                min = arr[i][j];
            }
        }
    }
    min = abs(min);
    printf("Module of min: %d", min); 
}




int main()
{
    const int drow = 3, dcol = 3;
    int array [drow][dcol];
    int a = 4;
    
    for (int i = 0; i < drow; i++){
        for (int j = 0; j < dcol; j++) {
            array[i][j] = rand() % 16-10;
        }
    }

//functions
    output(drow, dcol, array);
    min(drow, dcol, array);
    
   
    return 0;
}


