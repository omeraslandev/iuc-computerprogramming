#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *f;

    if( (f = fopen("letter.txt", "r")) == NULL ){
        
        printf("The file can not be opened.\n");

        exit(EXIT_FAILURE);
    }

}