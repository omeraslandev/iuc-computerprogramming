#include <stdio.h>

int main(){

    int numbers[5] = {5,10,15,20,25};

    int *ptr = numbers; // int *ptr = &numbers[0]; desen de olurdu.

    ++*ptr;
    // Hocam geldik dananin zart dedigi yere.
    // ++ * ptr
    // Hocam "*ptr" neydi? Ptr'ye bir adres vermistin, ptr o adresin icerigini biliyordu.
    // Ptr'ye gosterdigin adreste bulunan icerigi de "*ptr" olarak temsil ediyorduk.
    // Burada ptr'ye, numbers[] dizisini tanittik. Bir diziyi bir pointera tanittiginda
    // o pointerin dogrudan muhattap oldugu adres dizinin ilk indisinin bellekteki adresiydi.
    
    // yani numbers[5] dizisinin bellekteki adresleri sirasiyla soyle olsun:
    // &numbers[0] = 0x7fffffffe070 = ptr
    // &numbers[1] = 0x7fffffffe071
    // &numbers[2] = 0x7fffffffe072
    // &numbers[3] = 0x7fffffffe073
    // &numbers[4] = 0x7fffffffe074
    // ptr = &numbers[0] = 0x7fffffffe070 demek.
    // *ptr = numbers[0] = 5 demek.

    // Tamam simdi kisa bir tanitimimizi yaptiktan sonra olaya girelim.
    // *ptr ne demekti? numbers[0] yani 5.
    // yani ++(*ptr) demek, ++(numbers[0]) demektir.
    // Yani aslinda ++(5) demektir.
    // Yani aslinda 5+1 = 6 demektir :D

    // "++ (*ptr)" demek, "ptr'ye tanittigin adresteki icerigi 1 arttir" demektir.
    // Boylece guncel dizi ne oldu?
    // numbers[0] = 6 (5+1 = 6 oldu.)
    // numbers[1] = 10 (degismedi.)
    // numbers[2] = 15 (degismedi.)
    // numbers[3] = 20 (degismedi.)
    // numbers[4] = 25 (degismedi.)

    // Simdi hepsini teker teker yazdiralim.

    for (int i = 0; i < 5; ++i){
        printf("%d ", numbers[i]);
    }

    return 0;
}