#include <stdio.h>

int main(){

    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    switch (number) {
        case 1: printf("You entered 'One'\n"); break;
        case ((1+9)/5): printf("You entered 'Two'\n"); break;
        case 3: printf("You entered 'Three'\n"); break;
        case 4: printf("You entered 'Four'\n"); break;
        default: printf("switch>> You didn't entered a number between 1 and 4.\n");
    }

    //
    //
    // Mesela bu switch blogunun yaptigi islemin aynisini else-if deyimleriyle de yapabiliriz.
    if (number == 1){
        printf("You entered 'One'\n");
    }
    else if(number == 2){
        printf("You entered 'Two'\n");
    }
    else if(number == 3){
        printf("You entered 'Three'\n");
    }
    else if(number == 4){
        printf("You entered 'Four'\n");
    }
    else{
        printf("if-else>> You didn't entered a number between 1 and 4.\n");
    }
    

    return 0;
}