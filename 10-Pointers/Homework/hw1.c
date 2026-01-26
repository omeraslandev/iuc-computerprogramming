/*

1) Adres ve boyut gözlemi

• char, int, double türlerinden birer değişken tanımlayın; her biri için uygun pointer tanımlayın.
• Her değişken için sizeof(değişken) ve sizeof(pointer) değerlerini yazdırın.
• &x;, ptr ve &ptr; adreslerini %p ile yazdırın. (Not: adresler çalıştırmaya göre değişebilir.)

*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    char c;
    char *cp;

    int i;
    int *ip;

    double d;
    double *dp;

    printf(">>\nc isimli siradan char degiskenin bellekteki boyutu %zu bye'dir.\n", sizeof(c));
    printf("cp isimli pointer char degiskenin bellekteki boyutu %zu byte'dir.\n\n", sizeof(cp));

    printf(">>\ni isimli siradan integer degiskenin bellekteki boyutu %zu byte'dir.\n", sizeof(i));
    printf("ip isimli pointer integer degiskenin bellekteki boyutu %zu byte'dir.\n\n", sizeof(ip));

    printf(">>\nd isimli siradan double degiskenin bellekteki boyutu %zu byte'dir.\n", sizeof(d));
    printf("dp isimli pointer double degiskenin bellekteki boyutu %zu byte'dir.\n\n", sizeof(dp));



    return 0;
}