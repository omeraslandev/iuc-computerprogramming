/*

1) Adres ve boyut gözlemi

• 1) char, int, double türlerinden birer değişken tanımlayın; her biri için uygun pointer tanımlayın.
• 2) Her değişken için sizeof(değişken) ve sizeof(pointer) değerlerini yazdırın.
• 3) &x;, ptr ve &ptr; adreslerini %p ile yazdırın. (Not: adresler çalıştırmaya göre değişebilir.)

*/

#include <stdio.h>

int main(){

    // 1. Adim
    char c = 'A';
    char *cp = &c;

    int i = 1;
    int *ip = &i;

    double d = 3.14;
    double *dp = &d;

    // 2. Adim
    printf(">>\nc isimli siradan char degiskenin bellekteki boyutu %zu bye'dir.\n", sizeof(c));
    printf("cp isimli pointer char degiskenin bellekteki boyutu %zu byte'dir.\n\n", sizeof(cp));

    printf(">>\ni isimli siradan integer degiskenin bellekteki boyutu %zu byte'dir.\n", sizeof(i));
    printf("ip isimli pointer integer degiskenin bellekteki boyutu %zu byte'dir.\n\n", sizeof(ip));

    printf(">>\nd isimli siradan double degiskenin bellekteki boyutu %zu byte'dir.\n", sizeof(d));
    printf("dp isimli pointer double degiskenin bellekteki boyutu %zu byte'dir.\n\n", sizeof(dp));

    // 3. Adim
    printf("--- Adres Bilgileri ---\n");

    printf("DegiskenAdresi: (&c): %p, Pointer (cp): %p, PtrAdresi (&cp): %p\n", &c, cp, &cp);
    printf("DegiskenAdresi: (&i): %p, Pointer (ip): %p, PtrAdresi (&ip): %p\n", &i, ip, &ip);
    printf("DegiskenAdresi: (&d): %p, Pointer (dp): %p, PtrAdresi (&dp): %p\n", &d, dp, &dp);


    return 0;
}