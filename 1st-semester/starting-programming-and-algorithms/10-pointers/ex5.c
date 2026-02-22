#include <stdio.h>

int main(){

    /*
    Dizilerle ilgili bazi pointer ornekleri.
    */

    // --- 1) Ilk char karakter ornegi. ---
    char city[] = "Ankara";

    putchar(*city);
    /*
    Cikti: "A" seklinde olur.
    Bu amac icin 'putchar()'i kullaniriz.
    */ 



    
    // --- 2) Sayi dizisinin ilk elemani ornegi. ---
    int numbers[] = {1, 2, 3, 4, 5};

    printf("%d\n", *numbers);
    /*
    Cikti: "0" seklinde olur.
    "%d"ye dikkat et.
    */

    return 0;
}