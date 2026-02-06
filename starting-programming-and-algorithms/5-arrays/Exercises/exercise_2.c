#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ITERATIONS 10
#define LIST_SIZE 10

void randomList(int *list) {
    for (int i = 0; i < LIST_SIZE; i++) {
        list[i] = ( rand() % 50 ) + 1;
        printf("Dizinin %d indisli elemani %d\n", i, list[i]);
    }
}

int main() {
    srand( time(NULL) );

    int values[LIST_SIZE];
    randomList(values);

    int min = values[0];
    //Listenin elemanlarini karsilastiracagimiz referans noktasi.
    //Simdilik 0. indisi en kucuk olarak kabul ediyoruz.

    for (int i = 1; i < LIST_SIZE; i++) { // Donguyu 1. indisten baslattim cunku 0. indis zaten min'e esit. Gereksiz islem yuku olusturmasin.
        if ( values[i] < min) {
            min = values[i];
        }
    }

    printf("\n>>Listenin en kucuk elemani %d.", min);
}