#include <stdio.h>
enum { LIST_SIZE = 10 };

int main()
{
    int LIST[LIST_SIZE];

    for (int i = 0; i < LIST_SIZE; ++i)
    {
        LIST[i] = 0;
        printf("Listemizin %d. elemanı 0 olarak atanmıştır!\n", i);
    }

    return 0;
}