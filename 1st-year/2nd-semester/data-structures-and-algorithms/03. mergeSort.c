#include <stdio.h>

void birlestirmeliSiralama(int sayiListesi[], int solIndeks, int sagIndeks);
void listeleriBirlestir(int sayiListesi[], int solIndeks, int ortaIndeks, int sagIndeks);
void listeyiYazdir(int sayiListesi[], int listeBuyuklugu);

int main(){
    int sayiListesi[] = {92, 2, 9, 15, 91, 93, 5, 1};
    int listeBuyuklugu = sizeof(sayiListesi) / sizeof(sayiListesi[0]);

    printf("Siralama oncesi: ");
    listeyiYazdir(sayiListesi, listeBuyuklugu);

    // Algoritmayi baslat
    birlestirmeliSiralama(sayiListesi, 0, listeBuyuklugu - 1);

    printf("Siralama sonrasi: ");
    listeyiYazdir(sayiListesi, listeBuyuklugu);

    return 0;
}

// Bol ve Yonet (Divide and Conquer) mantigini isleten rekursif fonksiyon
void birlestirmeliSiralama(int sayiListesi[], int solIndeks, int sagIndeks){
    if(solIndeks < sagIndeks){
        int ortaIndeks = solIndeks + (sagIndeks - solIndeks) / 2;

        // Rekursif parcalama
        birlestirmeliSiralama(sayiListesi, solIndeks, ortaIndeks);
        birlestirmeliSiralama(sayiListesi, ortaIndeks + 1, sagIndeks);

        // Birlestirme islemi
        listeleriBirlestir(sayiListesi, solIndeks, ortaIndeks, sagIndeks);
    }
}

// Iki sirali alt diziyi tek bir sirali dizi haline getiren yardimci fonksiyon.
void listeleriBirlestir(int sayiListesi[], int solIndeks, int ortaIndeks, int sagIndeks){
    // Sol destede ana listemizin ortasindan en soluna dogru, ve ortasindan en sagina dogru olmak uzere iki dizi olusturacagiz.
    // Bu iki diziyi olusturabilmemiz icin, once bu iki dizinin nasil bir buyuklukte oldugunu ana listeye bakarak tespit edelim.
    int solDesteBoyutu = ortaIndeks - solIndeks + 1;
    int sagDesteBoyutu = sagIndeks - ortaIndeks;

    // Sag ve sol deste olmak uzere iki farklı dizi olusturalim. Bunlari karsilastirip, birlestirecegiz.
    int solDeste[solDesteBoyutu];
    int sagDeste[sagDesteBoyutu];

    // Ana listemizdeki elemanlari sag ve sol deste olmak uzere dogru yerlere yerlestirelim.
    for(int i = 0; i < solDesteBoyutu; i++) solDeste[i] = sayiListesi[solIndeks + i];
    for(int j = 0; j < sagDesteBoyutu; j++) sagDeste[j] = sayiListesi[ortaIndeks + 1 + j];

    // Karsilastirma islemini yapabilmek icin "imlec"lere ihtiyacimiz var.
    // Bizim insan olarak gozlerimiz var, gozlerimizle karsilastirma yapabiliriz.
    // Ancak bilgisayarlarin maalesef boyle bir imkani yok.
    int solDesteImleci = 0;
    int sagDesteImleci = 0;
    int anaListeImleci = solIndeks;

    // solDesteImleci, solDesteBoyutu kadar ilerlemediyse
    // (yani solDeste'de karsilastirma yapabilecek eleman hala kaldiysa, destenin sonuna gelmediysek)
    //
    // &&
    //
    // sagDesteImleci, sagDesteBoyutu kadar ilermediyse
    // (yani sagDeste'de karsilastirma yapabilecek eleman hala kaldiysa, destenin sonuna gelmediysek)
    while(solDesteImleci < solDesteBoyutu && sagDesteImleci < sagDesteBoyutu){

        // solDeste[0] <= sagDeste[0] ?
        // -> yes (solDeste[0] daha kucuk)
        // sayiListesi[4] = solDeste[0]

        // solDeste [1] <= sagDeste[0] ?
        // -> no (sagDeste[0] daha kucuk)
        // sayiListesi[5] = sagDeste[0]

        // solDeste[1] <= sagDeste[1] ?
        // -> no (sagDeste[1] daha kucuk)
        // sayiListesi[6] = sagDeste[1]
        if(solDeste[solDesteImleci] <= sagDeste[sagDesteImleci]){
            sayiListesi[anaListeImleci] = solDeste[solDesteImleci];
            solDesteImleci++;
        }
        else{
            sayiListesi[anaListeImleci] = sagDeste[sagDesteImleci];
            sagDesteImleci++;
        }

        anaListeImleci++;
    }

    /*
     * Yukaridaki while dongusu, && islecini kullanmisti.
     * Dolayisiyla o bloguna girmek icin hem (solDesteImleci < solDesteBoyutu) sarti,
     * hem de (sagDesteImleci < sagDesteBoyutu) sarti saglanmak zorundaydi.
     * Oysa ki yukarida ornekte de gordugumuz uzere, solDesteImleci = 1'de kaldi.
     * Bu demek oluyor ki, solDeste[solDesteImleci] en sona kaldi yani aslinda en buyuk deger o.
     * Bizde o en buyuk degeri, asagidaki while kontrolleri sayesinde en sona atmayi basarabilecegiz.
     * anaListeImleci artik en son kacta kaldiysa,
     * sayiListesi[anaListeImleci] = solDeste[solDesteImleci]'ne esit olacak.
     *
     * "Nasil bu kadar emin olabiliyorsun
     * solDeste[solDesteImleci] degerinin bu iterasyondaki en buyuk deger olduguna?"
     * diye soracak olursaniz, %100 eminim!
     * Soyle aciklayayim:
     *
     * -----> [92] ve [9] degerlerini kiyasladik.
     * 92 <= 9 (?) --> yani solDeste[0] <= sagDeste[0] (?) --> 0 = solDesteImleci; 0 = sagDesteImleci
     * no (9 daha kucuk) --> yani solDeste[0] daha kucuk --> 0 = solDesteImleci; 0 = sagDesteImleci
     * sayiListesi[0] = 9 --> yani sayiListesi[0] = solDeste[0]
     * solDesteImleci++; --> Yani yukaridaki iterasyonda 0 olan solDesteImleci, artik "1" olacak.
     * sayiListesi suan = [9, .......... ] diye gidiyor.
     * "Hadi gecelim [92]'yi yerlestirmeye!!!"
     * Derken...
     * Carpariz while dongusune.
     * Sartimiz neydi?
     * solDesteImleci < solDesteBoyutu && sagDesteImleci < sagDesteBoyutu
     * solDesteImleci = 1, sagDesteBoyutu = 1! ([92] dizisi 1 elemanliydi]
     * while bloguna giremedik.
     * "E ama sagDeste'de 1 eleman kaldi acikta?"
     * Evet! İste tam bu yuzden asagidaki 2 while kontrolune ihtiyacımız var.
     * while(sagDesteImleci < sagDesteBoyutu) bloguna girip,
     * [92]'yi 9'un sagina yerlestiririz.
     * Yani artik ana listemiz soyle gozukur: [9, 92, .......................]
     * o "......................."lık yere suan aldirmayin.
     * [9, 92] ikilisinin yanindaki ikiliyi de bu sekilde kendi icerisinde siralayacagiz.
     * Sonra Bu dortlunun yanindaki dortluyu da ikiye ayirip her bir ikiliyi de kendi icerisinde siralayip,
     * Sonra olusan dortluleri de kendi icerisinde siralayacagiz.
     * Tum bu siralama islemlerinde destelerden illa ki birinde en az 1 eleman acikta kalacak.
     * Ve acikta eleman kaldiginda, asagidaki while kontrollerimiz:
     * "Kimmis acikta kalan/kalanlar? Onlari listenin en sagina paslayayim!" diyecek.
     */
    while(solDesteImleci < solDesteBoyutu){
        sayiListesi[anaListeImleci] = solDeste[solDesteImleci];

        anaListeImleci++;
        solDesteImleci++;
    }

    while(sagDesteImleci < sagDesteBoyutu){
        sayiListesi[anaListeImleci] = sagDeste[sagDesteImleci];

        anaListeImleci++;
        sagDesteImleci++;
    }
}

void listeyiYazdir(int sayiListesi[], int listeBuyuklugu){
    for(int i = 0; i < listeBuyuklugu; i++){
        printf("%d ", sayiListesi[i]);
    }

    printf("\n");
}
