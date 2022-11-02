
#include <stdio.h>

int main()
{

    int temp;
    
    printf("What is your temperature?\n");
    scanf("%d", &temp);
    
    if (temp > 37){
        printf("Too hot");
    }
    else if(temp < 35)
    {
        printf("Too cold");
    }
    else{
        printf("Everything looks good");
    }

    return 0;
}
