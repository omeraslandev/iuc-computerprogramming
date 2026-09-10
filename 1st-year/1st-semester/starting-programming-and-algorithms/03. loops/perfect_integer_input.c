#include <stdio.h>
#include <stdlib.h> // strtol fonksiyonu icin gerekli.
#include <ctype.h> // isspace fonksiyonu icin gerekli.
#include <errno.h> // Hata numaralari icin gerekli.
#include <limits.h> // LONG_MAX ve LONG_MIN icin gerekli.

const int BUFFER = 1000;

int getSecuredNumber(long *result) {
    char buffer[BUFFER]; // Girdiyi tutacagim gecici kova
    char *errorSign; // Hatanin nerede oldugunu gosterecek pointer.
    long number;

    printf("Sayiyi girin (Korkmayin, abanin): ");

    // 1. ADIM: Girdiyi guvenli bir sekilde metin olarak al.
    if ( fgets(buffer, sizeof(buffer), stdin) != NULL ) {

        // 2. ADIM: Hata sayacini sifirliyorum. (Temiz bir sayfa aciyorum).
        errno = 0;

        // 3. ADIM: Metni tamsayiya cevirmeyi deniyorum. (String to Long)
        // 10 tabaninda (decimal) ceviri yapiyorum.
        number = strtol(buffer, &errorSign, 10);

        // 4. ADIM: Hata kontrollerimi yapiyorum.

        // A) Tasma Kontrolu (Overflow / Underflow)
        // Sayi sinirlara carptiysa (ERANGE) erno degismistir.
        if (errno == ERANGE) {
            printf("HATA: Bu sayi cok buyuk! (Veya cok kucuk) :D.\n");
            printf("Sistem bu sayiyi su sinira sabitledi: %ld\n", number);
        }

        // B) Hicbir sey girilmediyse veya sayi bulamadiysa
        else if (errorSign == buffer) {
            printf("HATA: Girdiginiz veri bir sayi degil.\n");
        }

        // C) Sayidan sonra anlamsiz karakterler varsa (Opsiyonel katilik)
        // '\n' (Enter) ve '\0' (Bitis) haricinde bir sey kaldiysa
        else if (*errorSign != '\n' && *errorSign != '\0') {
            printf("HATA: Gecersiz karakterler var.\n");
        }

        // D) Her sey yolunda
        else {
            *result = number; // Buldugum sayiyi adrese postaliyorum.
            return 1; // Basarili!
        }
    }

    return 0; // Okuma hatasi (fgets null donerse)
}

int main() {

    long enteredNumber;

    printf("--- 9 CANLI PROGRAM BASLADI ---\n");

    // 9 kere sayi isteme dongusu
    for (int i = 0; i <= 9; i++) {
        printf("\nDeneme %d:\n", i + 1);

        // Fonksiyonu cagiriyorum. Bize 1 (true) donerse basardik demektir.
        // &enteredNumber -> Sayiyi korumasi icin adresini veriyorum.
        if (getSecuredNumber(&enteredNumber)) {
            printf(">> Tebrikler! Temiz sayi yakalandi: %ld\n", enteredNumber);
        }
        else {
            printf(">> Lutfen tekrar deneyin.\n");
        }
    }
    return 0; // Unutma!!
}

