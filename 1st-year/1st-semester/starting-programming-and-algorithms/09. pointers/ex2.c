#include <stdio.h>

int main(){

    int x = 20;

    printf("Aslen integer olan x degiskenine su degeri atadik: \n>> %d\n\n", x);

    int *ptr = NULL;

    printf("Aslen pointer bir integer olan ptr degiskenini yeni tanimladik ve icini doldurmadik.\nIste yeni dogmus vahsi ptr'mizin urettigi 'garbage value': \n>> %p\n\n", (void*)ptr);

    ptr = &x;

    printf("Aslen integer olan x degiskeninin bellekteki GPS koordinatlari: \n>> %p\n\n", ptr);
}