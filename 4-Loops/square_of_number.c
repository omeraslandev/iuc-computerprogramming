#include <stdio.h>

int main(){

    int x;

    while(1){
        printf("Enter a number: ");
        scanf("%d", &x);
        if (x <= 0)
            break;
        x = x*x;
        printf("Square Root: %d \n", x);
    }
    printf("The while loop has been exited.");
    return 0;
}