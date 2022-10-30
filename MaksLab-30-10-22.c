#include <stdio.h>
int main()
{
    int i;
    char word[10];
    
    printf("Enter name: ");
    scanf("%s", word);
    
    for (i = 0; i <= 10; i++){
        if (word[i] == ' '){
            word[i] = '_';
        }
        printf("%c", word[i]);
    }
    
    printf( "%s", word);
    return 0;
}
