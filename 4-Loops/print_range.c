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

/*
1'den 100'e tüm sayıları yazdıran döngü.

int main()
{
    int x;

    while(x<=100){
        printf("x = %d \n", x);
        x++
    }

    return 0;
}

*/