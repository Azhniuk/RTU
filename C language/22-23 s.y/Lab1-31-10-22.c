
#include <stdio.h>

int main()
{
    char name[20];
    int age, b;
    
    printf("What is your username?\n");
    scanf("%s", name);
    
    printf("How old are you %s?\n", name);
    scanf("%d", &age);
    
    if (age >= 100){
        printf("You`re old");
    }
    else{
        b = 100 - age;
        printf("You will reach 100 years in %d years", b);
    }
    

    return 0;
}
