#include <stdio.h>
#include <stdbool.h>

int main()
{
    int x = 5, y, z, t = 8, result = 0;

    if(t>0 && t<5)
        printf("The number between 0 and 5 !\n");
    else if(t>5 && t<10)
        printf("The number between 5 and 10 !\n");
    else if(t>10 && t<15)
        printf("The number between 10 and 15 \n");
    else
        printf("The number greater than +15 or smaller than 0! \n");
}