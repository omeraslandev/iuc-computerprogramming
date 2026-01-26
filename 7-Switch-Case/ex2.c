#include <stdio.h>
#include <stdlib.h>

int find_season(int month){

    switch(month){
        case 12:
        case 1:
        case 2: printf("\n>> Its winter.\n"); break;
        case 3:
        case 4:
        case 5: printf("\n>> Its spring.\n"); break;
        case 6:
        case 7:
        case 8: printf("\n>> Its summer.\n"); break;
        case 9:
        case 10:
        case 11: printf("\n>> Its autumn.\n"); break;
    }

}

int main(){

    int month;

    printf("Enter the month that wanna know his month: ");
    scanf("%d", &month);

    find_season(month);

    return 0;
}