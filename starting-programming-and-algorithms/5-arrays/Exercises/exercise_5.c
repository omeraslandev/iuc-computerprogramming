#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
enum { LIST_SIZE = 10 };

int main() {
    srand( time(NULL) );

    int list[LIST_SIZE];

    for (int i = 0; i < LIST_SIZE; i++) {

        bool check; // Her turda sifirlanmali.
        int random_value;

        do {
            check = true;
            random_value = rand() % 10; // 0 ile 9 arasi.

            // Su an sadece onceden doldurdugum elemanlara bakiyorum. ( x < i )
            for (int x = 0; x < i; x++) {

                if ( list[x] ==  random_value ) {
                    check = false;
                    break; // Bulduysak digerlerine bakmaya gerek yok. Program yorulmasin.
                }

            }

        } while (check == false); // Eger sorun varsa donguden cikma, yeni sayi uretmeye devam et.

        list[i] = random_value;
        printf("\n>> Firindan yeni essiz sayi cikageldi! Iste o kral: %d !\n", list[i]);

    }

    return 0; // Gozunu seveyim unutma burayi.
}
