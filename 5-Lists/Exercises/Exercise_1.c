#include <stdio.h>
#include <stdlib.h>
#include <time.h>
enum { VALUE = 100 };

int main()
{
    srand(time(NULL));

    while (1)
    {
        printf("%d\n", rand());
    }

    return 0;
}