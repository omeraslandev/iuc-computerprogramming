#include<stdio.h>

int main(){
    int x;

    while(1){
        printf("Please enter a value: \n");
        scanf("%d", &x);

        if(x<=0)
            break;
        else if(x >= 5)
            continue;
        
        x = x * x;
        printf("Square of the number: %d \n", x);
    }
}