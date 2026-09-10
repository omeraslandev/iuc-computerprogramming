#include <stdio.h>

int main(){
    char *cp;
    char ch;

    printf(">> Siradan bir char degiskenin bellekte kapladigi alan %zu byte'dir.\n", sizeof(ch));

    printf(">> Pointer bir char degiskenin bellekte kapladigi alan %zu byte'dir.\n", sizeof(cp));
    printf(">> 'char *' veri tipinin       bellekte kapladigi alan %zu byte'dir.\n\n", sizeof(char *));
    // "sizeof(char *)" ile "sizeof(cp)"nin ne farki var?
    // "cp" elimdeki spesifik bir degiskendir. Bu degiskenin (kutunun) bellekte ne kadar yer kapladigini sorguladim.
    // "char *" ise bir veri tipidir. Bu veri tipinin (kalıbın) bu mimaride standart olarak ne kadar yer kapladigini sorguladim.

    int *ip;
    int i;

    printf(">> Siradan bir int degiskenin bellekte kapladigi alan %zu byte'dir.\n", sizeof(i));

    printf(">> Pointer bir int degiskenin bellekte kapladigi alan %zu byte'dir.\n", sizeof(ip));
    printf(">> 'int *' veri tipinin       bellekte kapladigi alan %zu byte'dir.\n\n", sizeof(int *));
    // "sizeof(int *) ile "sizeof(ip)"nin ne farki var?
    // Yukaridaki ile ayni mantik. "ip" bir degiskendir, "int *" ise bir veri tipidir.
    // Birinde bellekte ne kadar yer kapladigini sorgulariz, digerinde bu mimarideki yer kaplama standardını.

    double *dp;
    double d;

    printf(">> Siradan bir double degiskenin bellekte kapladigi alan %zu byte'dir.\n", sizeof(d));

    printf(">> Pointer bir double degiskenin bellekte kapladigi alan %zu byte'dir.\n", sizeof(dp));
    printf(">> 'double *' veri tipinin       bellekte kapladigi alan %zu byte'dir.\n\n", sizeof(double *));
    // Tekrar uzerinden gecelim.
    // "sizeof(dp)" derken 'bu spesifik kutunun boyutu ne?' diye soruyoruz.
    // "sizeof(double *)" derken ise 'bu tip kutularin standardi ne?' diye soruyoruz.

    return 0;
}

