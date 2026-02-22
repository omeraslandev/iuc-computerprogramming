#include <stdio.h>

int main(){

    int numbers[5] = {1, 2, 3, 4, 5};
    /*
    numbers[0] = 1
    numbers[1] = 2
    numbers[2] = 3
    numbers[3] = 4
    numbers[4] = 5
    */


    int *ptr = numbers + 2; // int *ptr = &numbers[2]; desen de olurdu
    /*
    " int *ptr = numbers + 2 " demek,
    " int *ptr = numbers[2]  " demektir.

    ptr[-2] = 1
    ptr[-1] = 2
    ptr[0] = 3
    ptr[1] = 4
    ptr[2] = 5
    
    */

    printf("[*-1] %d\n", (*ptr - 1) );
    // 'ptr - 1' dersen adresi cikarmaya calisirsin, yanlis olur!
    // 0xF1 - 1 demek ne kadar mantikli sence?
    // ancak '*ptr - 1' dersen ptr'nin isaret ettigi degerin 1 eksigini alirsin.
    // Yani ptr'nin mevcut indisinden bir onceki indisi
    printf("[-1] %d\n\n", ptr[-1]);
    // Bu aslinda yukaridaki (*ptr - 1) koduyla aslinda ayni seyi diyor.

    printf("[*] %d\n", (*ptr) );
    printf("[0] %d\n\n", ptr[0]);
    // Bu ikisi de ayni sey demektir.

    printf("[*+1] %d\n", (*ptr + 1) );
    printf("[1] %d\n\n", ptr[1]);
    // Bu ikisi de yine ayni sey :D

    return 0;
}