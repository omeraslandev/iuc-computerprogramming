#include<stdio.h>
#include<stdbool.h>

//A'dan Z'ye tüm harfleri yazdıran döngü.

int main()
{
    char x = 'A';

    while(x<='Z'){
        printf("x = %c \n", x);
        x++;
    }

    return 0;
}