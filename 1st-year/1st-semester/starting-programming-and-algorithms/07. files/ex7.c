#include <stdio.h>
#include <stdlib.h>

#define LENGTH 100

int main(){

    FILE *f;
    char line[LENGTH];

    if( (f = fopen("file.txt", "r")) == NULL ){
        printf("The file can not be opened.");
        exit(EXIT_FAILURE);
    }

    while( fgets(line, LENGTH, f) != NULL ){
        printf("%s", line);
    }

    fclose(f);

    return 0;

}