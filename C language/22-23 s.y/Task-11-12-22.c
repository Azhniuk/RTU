#include <stdio.h>

void get_min_med_max(int array[15])
{
    int i, j, temp, len;
    int min, med, max;
    
    printf("How many numbers: ");
    scanf("%d", &len);
    printf("Your numbers: ");
    for (i = 0; i < len; i++)
        scanf("%d", &array[i]);
    
    for (i = 0; i < len; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    min = array[0];
    med = array[len/2];
    max = array[len-1];
    
    printf("The smallest number is %d ", min);
    printf("\nThe median number is %d ", med);
    printf("\nThe largest number is %d ", max);
}

int main()
{
    int array[15];
    get_min_med_max(array);
    return 0;
}
