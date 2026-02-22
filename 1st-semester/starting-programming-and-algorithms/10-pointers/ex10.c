#include <stdio.h>

int main(){

    int numbers[5] = {5, 10, 15, 20, 25};
    
    int *ptr = numbers; // int *ptr = &numbers[0]; desen de olurdu.

    *(++ptr) = 50;
    // Burada sair ne demek istiyor?
    // Sunu demek istiyor hocam:
    // Pointer aritmetigini biliyorsun.
    // numbers[5] dizisini ptr ile soyle ifade edebilirsin:

    // numbers[0] = *(ptr) [ptr henuz yerinden kipirdamamisken elbette]
    // numbers[1] = *(ptr+1)
    // numbers[2] = *(ptr+2)
    // numbers[3] = *(ptr+3)
    // numbers[4] = *(ptr+4)

    // Yani temsili olarak numbers[++0] demek, numbers[1] demekse,
    // *(++ptr) demek de, *(ptr + 1) yani bir sonraki dizinin indisi demektir.

    // Ancak, burada cok onemli bir ayrim var; DIKKAT!
    // *(ptr + 1) deseydin ptr'nin isaret ettigi adres hala &numbers[0]'in olurdu.
    // yani *(ptr + 1) deseydin, orijinal "ptr"nin isaret ettigi adres degismezdi.
    // ANCAK! *(++ptr) dedigin an iki seyi yapmis olursun:
    // 1) Eyvallah, ptr'nin ilk isaret ettigi adresten sonraki adresin icerigine erisirsin
    // 2) VE ARTIK, ptr'nin isaret ettigi adres, o ++ ile arttirdigin &numbers[1] olur.
    // yani ++ isleci, ptr'nin adresini oteler. Buna yan etki (side effect) denir. COK Onemlidir.

    // * (++ptr) = 50 diyerek aslinda sunu demis oluyoruz:
    // "ptr isaretcisi bir diziyi tutmus birakmiyor, onu anladik
    // ve suan muhtemelen ilk indisi tutuyor. ilk indisin adresine odaklanmis durumda.
    // bu adresi 1 arttiralim, bir sonraki adrese yani bir sonraki indise gecsin.
    // ve o indisin icerigini * (yildiz) isaretiyle degistirelim. Bunu yaparken
    // ayni zamanda ptr'nin isaret ettigi adres de bir sonraki indisin adresine kaysin.
    // Kisaca:
    // '* (++ptr) demek, ptr'nin odaklandigi adresten bir sonraki adresteki indiste bulunan
    // icerigi degistirmek ve ayni zamanda ptr'nin adresini de bir sonraki adresle degistirmek
    // demektir.'"

    // Dizimiz guncel olarak suan su sekilde:

    // numbers[0] = 5 (Degismedi, hala ayni. Onu alakadar eden bir durum yok cunku ++ ile bir sonraki adrese ulastik.)
    // numbers[1] = 50 ( *(++ptr) = 50 diyerek numbers[1] = 50 demis olmustuk. Boylece 2. eleman degisti.)
    // numbers[2] = 15 (Degismedi, hala ayni.)
    // numbers[3] = 20 (Degismedi.)
    // numbers[4] = 25 (Degismedi.)


    *ptr = 100;
    // ptr'nin isaret ettigi adresi artirmistik ve artik isaret edilen adres &numbers[1] idi.
    // Simdi burada da numbers[1] = 100 demis oluyoruz aslinda.

    // Sonuc olarak dizimiz su sekilde olur:

    // numbers[0] = 5 (Degismedi, bu saatten sonra bunu degistirmek icin *(--ptr) = ... yapmaliyiz.)
    // numbers[1] = 100 (++ isleci ile ptr'nin mevcut adresi degismisti ve &numbers[1] olmustu. *ptr = 100 diyerek de bu icerigi 100 yapmis olduk.)
    // numbers[2] = 15 (Degismedi, hala ayni.)
    // numbers[3] = 20 (Degismedi.)
    // numbers[4] = 25 (Degismedi.)

    for (int i = 0; i < 5; ++i){
        printf("%d ", numbers[i]);
    }

    return 0;
}