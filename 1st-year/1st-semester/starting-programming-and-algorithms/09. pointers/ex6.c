#include <stdio.h>

void func(int *ptr){
    *ptr = 30;
}

int main(){

    int number = 10;

    func(&number);
    /*
    func() fonksiyonu sayesinde gerceklesen islemler sirasiyla:
    1) int *ptr;
    2) ptr = &number;
    3) *ptr = 20 (yani *&number = 20, yani number = 20) 
    */

    printf("Number = %d\n", number);
    // Cikti: "Number = 20"

    return 0;
}