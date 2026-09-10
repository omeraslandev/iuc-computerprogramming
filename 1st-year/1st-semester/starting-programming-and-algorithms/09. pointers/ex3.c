#include <stdio.h>

int main()
{
    int x = 20;

    int *ptr;

    ptr = &x;
    // Yildizsiz pointer kullanimi,
    // adres yonlendirmesi icin kullanilir.
    // Kargocu gibi dusun. Yildizsiz pointer kullanirsan
    // ilgili degiskenin adresini tanitmis olursun. Boylece
    // ileride "*ptr = ..." diyerek adresini tanittigin
    // degiskenin degerini bile degistirmen mumkun olur.

    printf("alicinin degeri nedir? kargocu kiminle muhattap olacak?:\n>> %d\n\n", x);
    printf("alicinin adresi nedir? kargocu nereye gidecek?:\n>> %p\n\n", &x);

    printf("kargocu, alicinin adresini (&x) aldi. iste kargocunun ulasmak istedigi adres:\n>> %p\n\n", ptr);
    // "ptr" degiskeninin degeri, artik X degiskeninin adresi demektir.
    // "ptr"yi cagirdiginda, X'in adresini yazili olarak gorebilirsin.

    printf("kargocu elbette alicinin adresini bir kagida yazdi ve cebine koydu.\nkagit cebinde ve kagidin da ozel bir x-y-z koordinatlari var.\nyani kagidin da bir adresi var. iste kagidin adresi su:\n>> %p\n\n", &ptr);
    // Ancak "&ptr" yazarsan ptr degiskeninin bellekte hangi adreste
    // sormus olursun. Bunun sonucu X'in adresi asla degil.
    // Bunun sonucu direkt ptr degiskeninin kendi oz be oz adresidir.

    return 0;
}

/*
Kisaca ozetlemek gerekirse:

x: Kargocunun gidecegi evde iceride oturan kisi.
"ptr = &x" derken aslinda sunu demis oluyorsun:
"x, bir kargo siparis etti.
x'in yerini ve iceride kiminle muhattap olacagimi biliyorum.
x'in adresini ozel kagidima (ptr) yazdim ve cebime (&ptr'ye) koydum .
Sag cebime, belirli bir x-y-z koordinatlariyla koydum.
Kagidin koordinati &ptr'de yaziyor, alicinin adresi degil.
Eger iceride kiminle muhattap oldugumu unutursam *ptr degerine
bakmam yeterli. Kiminle muhattap olacagim *ptr'de yaziyor.
Eger istersem *ptr'yi yani muhattap olacagim kisiyi degistirebilirim.

int alici = 4380
int *pointer;

pointer = &alici;

*pointer = 4380 * 2 // artik "alici = (4380 * 2)"

pointer = &y // Bu su demek: Artik baska bir adrese gidiyorum.

&pointer // Bunu degistiremem, bu benim kagidimi koydugum cebim.
"


ptr: Elimdeki kagitta yazan adres (Kargocunun gidecegi ev)
&ptr: O kagidin (degiskenin) benim cebimdeki konumu. (Sag cebimde mi, x-y-z koordinatlari vs:D)
*ptr: O adrese gidip kapiyi caldiginda iceride bulacagim kisi. (Yani 20)

*/