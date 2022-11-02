#include <stdio.h>
int main()
{
    int i;
    int len = 1000;
    char word[len];
    
    printf("Enter a word: ");
    fgets(word, len, stdin);
    
    for (i = 0; i <= len; i++){
        if (word[i] == ' '){
            word[i] = '_';
        }
    }
    
    printf( "%s", word);
    return 0;
}
