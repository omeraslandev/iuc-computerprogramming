#include <stdio.h>

void secmeSiralamasi(int sayiListesi[], int listeBuyuklugu);
void degerleriTakasla(int *adresA, int *adresB);
void listeyiYazdir(int sayiListesi[], int listeBuyuklugu);

int main() {
    int sayiListesi[] = {7, 2, 5, 1, 3};
    int listeBuyuklugu = sizeof(sayiListesi) / sizeof(sayiListesi[0]);

    printf("Siralama oncesi: ");
    listeyiYazdir(sayiListesi, listeBuyuklugu);

    // Algoritmayi baslat
    secmeSiralamasi(sayiListesi, listeBuyuklugu);

    printf("Siralama sonrasi: ");
    listeyiYazdir(sayiListesi, listeBuyuklugu);

    return 0;
}

// Iki bellek adresindeki degeri birbiriyle degistiren yardimci fonksiyon.
void degerleriTakasla(int *adresA, int *adresB) {
    int geciciHafiza = *adresA;
    *adresA = *adresB;
    *adresB = geciciHafiza;
}

// "En kucugu bul ve siranin basina cek" mantigiyla calisan siralama fonksiyonu.
void secmeSiralamasi(int sayiListesi[], int listeBuyuklugu) {

    /* * Bizim bir "mevcut sira imlecimiz" (i) olacak.
     * Bu imlec, listenin basindan sonuna kadar her bir yuvayi tek tek gezecek.
     * Amacimiz: Her adimda o anki yuva icin uygun olan en kucuk degeri bulup oraya yerlestirmek.
     */
    for (int mevcutSiraImleci = 0; mevcutSiraImleci < listeBuyuklugu - 1; mevcutSiraImleci++) {

        // Simdi bilgisayarin "hafizasinda" bir yer tutmasi gerekiyor.
        // Biz gozumuzle listeye bakinca "Aha en kucuk bu!" diyebiliyoruz.
        // Ama bilgisayar tarama yaparken "su ana kadar gordugum en kucuk buydu" diyebilmek icin
        // bu imleci (indeksi) saklamak zorunda.
        int enKucukElemanImleci = mevcutSiraImleci;

        /* * Ic dongu (taramaImleci): Mevcut siradan baslayip listenin sonuna kadar
         * "Daha kucuk bir sey var mi?" diye arama yapar.
         */
        for (int taramaImleci = mevcutSiraImleci + 1; taramaImleci < listeBuyuklugu; taramaImleci++) {

            // Eger tarama yaparken buldugumuz deger, "en kucuk" diye not ettigimizden daha kucukse...
            if (sayiListesi[taramaImleci] < sayiListesi[enKucukElemanImleci]) {

                // Bilgisayara diyoruz ki: "Notunu guncelle, yeni en kucuk burada!"
                enKucukElemanImleci = taramaImleci;
            }
        }

        /* * Tarama bitti. Elimizde bu turun "en kucugu"nun nerede oldugu bilgisi var.
         * * Eger buldugumuz en kucuk elemanin yeri (enKucukElemanImleci),
         * zaten su anki siramiz (mevcutSiraImleci) degilse; o zaman takas vaktidir.
         * * "Neden bu kontrolü yapiyoruz?"
         * Cunku eger o siradaki eleman zaten olmasi gereken en kucuk elemansa,
         * boş yere takas islemi (3 adimlik hafiza hareketi) yapip sistemi yormak istemeyiz.
         */
        if (enKucukElemanImleci != mevcutSiraImleci) {
            degerleriTakasla(&sayiListesi[mevcutSiraImleci], &sayiListesi[enKucukElemanImleci]);
        }

        // Artik mevcutSiraImleci'nin oldugu yer "kesin olarak" sirali.
        // Bir sonraki yuvaya gecebiliriz.
    }
}

void listeyiYazdir(int sayiListesi[], int listeBuyuklugu) {
    for (int i = 0; i < listeBuyuklugu; i++) {
        printf("%d ", sayiListesi[i]);
    }
    printf("\n");
}
