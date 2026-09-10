#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // srand() fonksiyonunu dongunun disarisina tanimlamak cok onemli.

    const int listSize = (rand() % 10) + 1; // 0 gelmesini onlemis oldum. 0 gelseydi dongu 0 kez donecekti, o zaman ne anlamı vardi ki programin?

    int list[listSize]; // Rastgele degerde bir dizi tanimladim.
    int listTotal = 0; // Dizinin elemanlarini toplayacagim degiskeni tanimladim.

    printf(">> Kral, dongumuz %d kere takılacak haberin olsun.\n\n", listSize);

    for (int i = 0; i< listSize; ++i) {
        list[i] = rand() % 100;
        listTotal += list[i];

        printf(">> Kral, listenin %d. elemanı %d olmustur haberin olsun.\nBir de listedeki elemanlarin toplami artik %d!\n", i, list[i], listTotal);
    }

    printf("\n>> Kral dongu bitti gecmis olsun. Son elemanimiz %d olmustu, nihai listedeki elemanlarin toplami %d olarak tamam oldu, imzami kasemi bastim.", list[listSize - 1], listTotal);

    return 0;
}

/* Ayrica, degisken isimlerinin kucuk `variable_name` veya kucuk-buyuk `variableName` seklinde yazmanin daha "clean" oldugunu ogrendim.
 * Normalde degiskenlerimi buyuk `VARIABLE_NAME` yaziyordum ancak geleneksel olarak makrolarin bu sekilde buyuk yazildigini ogrendim.
 * Ileride kodumu okuyacak gelistiriciler icin bu kafa karisikligini olusturmamaliyim, simdiden aliskanliklarimi dogru kurmaliyim.
 */