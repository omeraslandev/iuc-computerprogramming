#include <stdio.h>

#define LIST_SIZE 5

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size) {
    // DIS DONGU: n-1 tur döner. (Çünkü n-1 eleman yerleşince sonuncusu mecbur doğrudur)
    for (int i = 0; i < size - 1; i++) {

        // IC DONGU: Her turda bir önceki turun en büyük elemanını eleriz (-i)
        // Ayrıca taşmayı engelleriz (-1)
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int list[LIST_SIZE] = {-100, -200, 100, 0, 200};

    bubbleSort(list, LIST_SIZE);

    for (int i = 0; i < LIST_SIZE; i++) printf("%d ", list[i]);
    printf("\n");

    return 0;
}
