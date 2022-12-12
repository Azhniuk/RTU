#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int drow = 3, dcol = 3;
    int array [9];
    for (int i = 0; i < drow; i++){
        for (int j = 0; j < dcol; j++) {
            array[i, j] = rand() % 16-10;
            printf("%d ", array[i, j]);
        }
        printf("\n"); 
    }
   
    return 0;
}
