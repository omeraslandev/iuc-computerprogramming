#include <stdio.h>

// Fonksiyon prototipleri
void hizliSiralama(int sayiListesi[], int solIndeks, int sagIndeks);
int parcalaraAyir(int sayiListesi[], int solIndeks, int sagIndeks);
void yerDegistir(int* a, int* b);
void listeyiYazdir(int sayiListesi[], int listeBuyuklugu);

int main() {
    int sayiListesi[8] = {7, 2, 5, 1, 9, 15, 91, 876};
    int listeBuyuklugu = sizeof(sayiListesi) / sizeof(sayiListesi[0]);

    printf("Siralama oncesi: ");
    listeyiYazdir(sayiListesi, listeBuyuklugu);

    // Başlangıç ve bitiş indeksleri verilerek işlem başlatılır
    hizliSiralama(sayiListesi, 0, listeBuyuklugu - 1);

    printf("Siralama sonrasi: ");
    listeyiYazdir(sayiListesi, listeBuyuklugu);

    return 0;
}

void hizliSiralama(int sayiListesi[], int solIndeks, int sagIndeks) {
    if (solIndeks < sagIndeks) {
        // Pivot elemanının doğru konumunu bulup listeyi ikiye ayırıyoruz
        int parcalamaIndeksi = parcalaraAyir(sayiListesi, solIndeks, sagIndeks);

        // Pivotun solunda ve sağında kalan parçaları kendi içinde sıralıyoruz
        hizliSiralama(sayiListesi, solIndeks, parcalamaIndeksi - 1); // Sol parça
        hizliSiralama(sayiListesi, parcalamaIndeksi + 1, sagIndeks); // Sağ parça
    }
}

int parcalaraAyir(int sayiListesi[], int solIndeks, int sagIndeks) {
    // Genellikle son eleman pivot (mil) olarak seçilir
    int pivot = sayiListesi[sagIndeks]; 
    int i = (solIndeks - 1); // Küçük olan elemanların sınırını belirleyen imleç

    for (int j = solIndeks; j < sagIndeks; j++) {
        // Eğer mevcut eleman pivottan küçük veya eşitse
        if (sayiListesi[j] <= pivot) {
            i++; // Küçük elemanlar bölgesini genişlet
            yerDegistir(&sayiListesi[i], &sayiListesi[j]);
        }
    }
    
    // Pivotu, kendisinden küçüklerin hemen sağına (doğru konuma) yerleştiriyoruz
    yerDegistir(&sayiListesi[i + 1], &sayiListesi[sagIndeks]);
    return (i + 1);
}

// Elemanların yerini değiştirmek için yardımcı fonksiyon
void yerDegistir(int* a, int* b) {
    int gecici = *a;
    *a = *b;
    *b = gecici;
}

void listeyiYazdir(int sayiListesi[], int listeBuyuklugu) {
    for (int i = 0; i < listeBuyuklugu; i++) printf("%d ", sayiListesi[i]);
    printf("\n");
}