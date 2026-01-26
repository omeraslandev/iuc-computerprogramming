int main(){

    int x = 10;
    int *ptr;

    *&x = 20;
    // Bu ifade kulagini tersten tutmak gibidir.
    // '*&x = 20' ifadesi ile 'x = 20' ifadesi arasında bir fark yoktur.

    ptr = &x;
    // Artik "ptr" isimli pointerimiz (kargocumuz) x'in adresini
    // ve o adreste onu nasil bir veri bekledigini ogrendi.

    *ptr = 30;
    // ptr'nin tanimis oldugu adresteki (x'in adresini) veriyi
    // "30" olarak degistir demektir. Yani x = 30 demektir.

    // yalin bir sekilde "ptr" demek, aslinda "x'in adresi" demektir.
    // ancak &ptr demek, dogrudan ptr isimli pointer degiskenimizin adresi demektir.

    return 0;
}