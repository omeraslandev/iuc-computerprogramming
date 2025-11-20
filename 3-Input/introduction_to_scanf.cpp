#include <stdio.h>
#include <stdbool.h>

int main()
{
    int x;

    printf("Please enter e number: ");
    scanf("%d", &x);

    if (x % 2 == 0)
        printf("The number is even.");
    else
        printf("The number is odd.");
}