#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *f;

    if( (f = fopen("letter.txt", "w")) == NULL ){
        
        printf("letter.txt file can not be created.\n");
        exit(EXIT_FAILURE);

    }

    fclose(f);
    // Eger birden fazla dosya acilmissa,,
    // "int fcloseall();" fonksiyonu ile
    // acilmis tum dosyalari kapatabilirdik.

    printf("letter.txt file closed.\n");

    return 0;
}