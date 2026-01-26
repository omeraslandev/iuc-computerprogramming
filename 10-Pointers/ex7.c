#include <stdio.h>

#define LENGTH 10

int main(){

    int k;

    int number[LENGTH];

    for(k = 0; k < 10; k++){

        *(number + k) = k;

        printf("%d\n", number[k]);
    }

    return 0;
}