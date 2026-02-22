#include <stdlib.h>
#include <stdio.h>

int main(){

    // Degiskenleri tanimlama
    FILE *f;

    int i;
    int character;

    // 0-9 arası sayilar data.txt dosyasina yazdirilir.
    if( (f = fopen("data.txt", "w")) == NULL ){
        printf("The file can not be opened.\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < 10; ++i){
        fprintf(f, "Number now is %d...\n", i);
        // 'fprintf(f, "...")' fonksiyonuyla 0-9 arasi sayilari
        // hedefledigimiz "data.txt" dosyasina yazdiriyoruz.
        // 'fprintf' ile 'printf' neredeyse aynı calisir:
        // tek farki ciktiyi konsola degil,
        // belirttigimiz dosya isaretcisine (f) gondermesidir.
    }

    fclose(f);

    // Dosyadaki karakterleri ekrana yazdirma
    if( (f = fopen("data.txt", "r")) == NULL ){
        printf("The file can not be opened...\n");
        exit(EXIT_FAILURE);
    }

    while( (character = fgetc(f)) != EOF ){
        printf("%c", character);
    }

    fclose(f);

    return 0;

}