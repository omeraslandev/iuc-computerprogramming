#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
enum { LIST_SIZE = 50 };

int main(){
    for(int i = 0; i <= LIST_SIZE; ++i)
        printf("Şuanki sayımız ise: %d'dir.\n",i);
    return 0;
}