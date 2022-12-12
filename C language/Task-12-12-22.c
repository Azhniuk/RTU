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
    int array [drow][dcol], a, b;
    
    
    for (int i = 0; i < drow; i++){
        for (int j = 0; j < dcol; j++) {
            array[i][j] = rand() % 16-10;
        }
    }

//functions
    output(drow, dcol, array);
    a = min(drow, dcol, array);
    b = max(drow, dcol, array);
    
    
    
    
    printf("Module of minimum: %d \n", abs(a));
    printf("Square root of maximum: %f \n", sqrt((double)b));
    
   
    return 0;
}


