#include <stdio.h>

int main(){

    switch (getchar()) {
        case '0': printf("Its zero!\n"); break;
        case '1': printf("Its one!\n"); break;
        case '2': printf("Its two!\n"); break;
        case '3': printf("Its three!\n"); break;
        case '4': printf("Its four!\n"); break;
        case '5': printf("Its five!\n"); break;
        default: printf("Please enter a number between 0-5\n");
    }

    return 0;
}