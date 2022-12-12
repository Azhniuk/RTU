/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


void output( int drow, int dcol, int arr[drow][dcol]) {
    for (int i = 0; i < drow; i++){
        for (int j = 0; j < dcol; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n"); 
    }
}


int min( int drow, int dcol, int arr[drow][dcol]) {
    int min = arr[0][0];
    for (int i = 0; i < drow; i++){
        for (int j = 0; j < dcol; j++) {
            if (min > arr[i][j]){
                min = arr[i][j];
            }
        }
    }
    return min;
}


int max( int drow, int dcol, int arr[drow][dcol]) {
    int max = arr[0][0];
    for (int i = 0; i < drow; i++){
        for (int j = 0; j < dcol; j++) {
            if (max < arr[i][j]){
                max = arr[i][j];
            }
        }
    }

    return max;
}




int main()
{
    const int drow = 3, dcol = 3;
    int array [drow][dcol], a, b, c;
    
    
    for (int i = 0; i < drow; i++){
        for (int j = 0; j < dcol; j++) {
            array[i][j] = rand() % 16-10;
        }
    }

//functions
    output(drow, dcol, array);
    a = min(drow, dcol, array);
    b = max(drow, dcol, array);
    c = abs(a - b) * (-1);
    
    
    
    
    printf("Module of minimum a : %d \n", abs(a));
    printf("Square root of maximum b : %f \n", sqrt((double)b));
    printf("Third formula c : %d \n", c);
    
    
   
    return 0;
}


