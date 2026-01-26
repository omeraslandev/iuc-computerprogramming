#include <stdio.h>
#include <stdlib.h>

#define LENGTH 100

int main(){

    char buffer[LENGTH];

    FILE *filesource;
    FILE *filetarget;

    if ( (filesource = fopen("source.txt", "r")) == NULL ){
        printf("source.txt file can not be opened.\n");
        exit(EXIT_FAILURE);
    }

    if ( (filetarget = fopen("target.txt", "w")) == NULL){
        printf("target.txt file can not be created.\n");
        exit(EXIT_FAILURE);
    }

    while ( fgets(buffer, LENGTH, filesource) ){
        fputs(buffer, filetarget);
    }

    fclose(filesource);
    fclose(filetarget);

    return 0;
}