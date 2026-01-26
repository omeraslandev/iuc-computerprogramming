/*

2) Dizi ve pointer aritmetiği

• int a[10] oluşturun. Diziyi yalnızca pointer aritmetiği ile doldurun: *(a + k) = ...
• Aynı diziyi iki yöntemle yazdırın: (i) a[k] ile, (ii) *(a + k) ile.
• void print_array(const int *p, int n) yazın: indis kullanmadan, pointer’ı ilerleterek yazdırsın.

*/

#include <stdio.h>
#define LIST_SIZE 10

void print_array(const int *p, int n){
    for(int i = 0; i < n; i++){
        printf("Deger: %d\n", *(p++));
    }
}

int main(){

    int numbers[LIST_SIZE];

    int *ptr = numbers; // ya da "int *ptr = &numbers[0];"

    for (int i = 0; i < LIST_SIZE; i++){
        *(ptr + i) = i;
    }

    for (int i = 0; i < LIST_SIZE; i++){
        printf(">> numbers[i] = %d\n", numbers[i]);
    }

    printf("\n");

    for (int i = 0; i < LIST_SIZE; i++){
        printf(">> *(numbers + i) = %d\n", *(numbers + i));
    }

    printf("\nprint_array() fonksiyonu ile:\n");
    
    print_array(ptr, LIST_SIZE);

    return 0;
}