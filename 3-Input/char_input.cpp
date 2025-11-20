#include <stdio.h>
#include <stdbool.h>

int main()
{
    char ch;
    
    printf("Enter a character: ");

    ch = getchar();

    if(ch>='a' && ch<='z')
        printf("The entered character is lowecase. \n");
    else
        printf("The entered character is uppercase. \n");
    return 0;
}