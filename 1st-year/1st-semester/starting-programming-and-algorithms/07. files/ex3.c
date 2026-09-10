#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *f;
    int character;

    if( (f=fopen("letter.txt", "r")) == NULL){
        printf("The file can not be opened.\n");
        exit(EXIT_FAILURE);
        // Bu kisim kodun sigortasidir.
        // "fopen" fonksiyonu dosyayi bulamazsa veya
        // yetki hatasi alirsa "NULL" doner.
        // Eger "NULL" donerse, program kullaniciyi bilgilendirip
        // calismayi durdurur.
    }

    // Eger program bu satira kadar gelebildiyse (exit atmadiysa),
    // dosya basariyla acildi demektir.

    while( ( character = fgetc(f) ) != EOF ){

        // Bu while sartinda bir kafa karisikligi yasamak normaldir.
        // "Biz dosyadaki karakterleri okumaya calisiyoruz,
        // bu karakterler 'char' degil mi? Ama 'fgetc()' char degil
        // 'integer' deger donduruyor. Sonra 'character' degiskenimiz
        // de integer tanimli. Ne is bu? Biz karakter kullaniyoruz
        // ama integer degerler havada ucuyor ne is bu?"
        // diye dusunmus olabiliriz.

        // Soyle ki: Bilgisayar "A" harfini "A" olarak bilmez.
        // Bilgisayar icin her sey elektriktir, yani "sayidir".
        // Ben klavyeden "A" tusuna bastigimda
        // aslinda bilgisayarin hafizasina "65" sayisi yazilir.
        // Neden? Cunku "A" harfinin ASCII karsiligi "65"tir.

        // "char" tipi aslinda 1 byte'lik kucuk bir integer'dir.
        // Eger 'printf("%c", 65)' dersek ekrana 'A' yazar.
        // Eger 'printf("%d", A)' dersek ekrana '65' yazar.
        // Yani "char" ve "int" arasindaki fark sadece
        // "kapladiklari yer" ve "bizim onlara nasil baktigimizdir".

        // "Madem ikisi de bilgisayar icin ayni, neden 'int' kullandik da
        // char kullanmadik? Kafamizi karistirmaya ne gerek vardi?"
        // diye bir soru da sorabiliriz. Ancak iste
        // zurnanin zirt dedigi yer tam olarak burasi.
        // Bir dosyada 256 farkli karakter olabilir (standart ASCII).
        // Dosya bittiginde, sistem bana "Hacim, dosya bitti, daha okuma!"
        // demesi lazim. Bunu diyemezse sonsuza kadar okumaya calisacak.
        // İste bu "dur" mesajina "EOF" (End of File) denir!

        // "EOF" degeri genellikle '-1' olarak tanimlidir.
        // Eger "character" degiskenini 'char' (1 byte) yapsaydik,
        // dosya icinde gercek bir veriyle "dosya bitti" sinyalini (EOF)
        // birbirine karistirirdik. İste bu noktada cozumumuz sudur:

        // "fgetc" fonksiyonu bir "int" dondursun. Bu sayede 256 tane
        // karakterin hepsini basariyla temsil edelim, ustune bir de
        // "dosya bitti" anlamina gelen o ozel "-1" degerini (EOF)
        // bunlardan ayri tutacak kadar genis bir alani (genelde 32 bit) olsun.
        // Boylece diger karakterlerle karistirmadan, kendine ozgu bir yapisi
        // olan EOF degerini arayarak, dosyanin sonuna geldigimizi
        // guvenli bir sekilde tespit etmis oluruz.

        printf("%c", character);

        // 'printf("%c", character)' dedigimizde aslinda sunu demis oluyoruz:
        // "Elimde bir sayi var (mesela 65), sen bunu git
        // karakter tablosundan (ASCII) bak ve
        // "%c" dedigim icin bana harf olarak (char) goster."

        // "printf" fonksiyonumuz cok esnektir. Biz ona "%c" dersek,
        // elimizdeki degisken ister char olsun ister int,
        // o sadece o sayinin karakter karsiligini ekrana basar.

        // Yani eger dosyamizda 'A' yaziyorsa,
        // "%c" demek direkt ekrana 'A' yazdirir.
        // Ama bir cilginlik yapip "%d" deseydik,
        // Ekrana A'nin ASCII karsiligi olan "65"i yazdirmis olurduk.
        // Denemek ister misiniz?

        // --- Fun Fact ---
        // 'A' harfinin kucugunun ASCII karsiligini bulmak istersek,
        // 'A' harfinin ASCII karsiligina "32" eklememiz gerekir.
        // Yani 'A' = 65 ise,
        //      'a' = 65 + 32
        //      'a' = 97'dir.
    }

    fclose(f);
    // Eger bircok farkli dosyayi kapatmak isteseydim
    // "int fcloseall()" derdim. Ama tek dosya acmisim,
    // tek dosyayi kapatiyorum. Bu yuzden fclose(stream); yeterli.

    // Sunu da belirtmeliyim ki "int fcloseall()" fonksiyonu
    // standart C kutuphanesinin bir parcasi degildir.
    // Genellikle bazi derleyicilere (GNU/GCC gibi) ozgu bir uzantidir.
    // Tasinabilir bir kod icin her dosyayi kendi isaretcisiyle
    // "fclose(f)" seklinde kapatmak en dogru yoldur.

    return 0;   
}