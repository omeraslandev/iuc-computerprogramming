#include <stdio.h>

int main(int x){
    int i = 0;

    if(i == 0)  return 1;
    
    while(x){
        x = x / 10;
        i++;
    }

    printf("\n %d basamaklı bir sayıdır. \n",i);

    return 0;
}