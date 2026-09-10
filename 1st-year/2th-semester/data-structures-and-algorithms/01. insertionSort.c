#include <stdio.h>

void eklemeSiralamasi(int arr[], int size);
void listeyiYazdir(int arr[], int size);

int main(){
    int sayiListesi[8] = {7, 2, 5, 1, 9, 15, 91, 876};
    int listeBuyuklugu = sizeof(sayiListesi) / sizeof(sayiListesi[0]);

    printf("Siralama oncesi: ");
    listeyiYazdir(sayiListesi, listeBuyuklugu);

    eklemeSiralamasi(sayiListesi, listeBuyuklugu);

    printf("Siralama sonrasi: ");
    listeyiYazdir(sayiListesi, listeBuyuklugu);
}

void eklemeSiralamasi(int sayiListesi[], int listeBuyuklugu){
    int mevcutEleman;
    int solAdim;

    for(int mevcutAdim = 1; mevcutAdim < listeBuyuklugu; mevcutAdim++){
        mevcutEleman = sayiListesi[mevcutAdim];
        solAdim = mevcutAdim - 1;

        while(solAdim >= 0 && sayiListesi[solAdim] > mevcutEleman){
            sayiListesi[solAdim + 1] = sayiListesi[solAdim]; // Gecici olarak bir adim saga kaydiriyoruz.
            solAdim--;
        }
        sayiListesi[solAdim + 1] = mevcutEleman;

        /*
            Küçük sayı (mevcutEleman) döngü boyunca aslında "havada" bekler.

            Büyük sayılar: Adım adım sağa kayar (1 birim, 1 birim...).

            Küçük sayı: En son boş kalan yere tek bir hamlede "ışınlanır".

            Yani aslında küçük sayı sola doğru "kaymaz", uygun yer bulunduğunda oraya "yerleşir" (insert).
        */
    }
}

void listeyiYazdir(int sayiListesi[], int listeBuyuklugu){
    for(int i = 0; i < listeBuyuklugu; i++) printf("%d ", sayiListesi[i]);
    printf("\n");
}
