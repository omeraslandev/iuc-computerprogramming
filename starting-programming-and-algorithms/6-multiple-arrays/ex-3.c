#include <stdio.h>
#define TRIANGLE_SIZE 10

int main(){

    for (int i = 0; i < 10; i++){

        int current_line_length = TRIANGLE_SIZE - i;

        for(int j = 0; j < current_line_length; j++){

            printf("*");

        }

        printf("\n");

    }


    return 0;
}