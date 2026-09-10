#include<stdio.h>
#include<stdbool.h>

int main()
{
    int x = 15;
    float y = 3.14;
    double z = 99.99999;
    bool t = true;
    double m;
    m = 3.14159; // <-- Değer ataması yapıldı!
    char k = 's';


    double yas[10] = {13.5,24,8,56,9,45,18,73,23,34};

    printf("X'in degeri: %d \n", x);
    printf("%f \n", y);
    printf("%lf \n", z);
    printf("%d \n", t);
    printf("%lf \n", m);
    printf("%c \n", k);
    

    printf("%.2f \n", yas[0]);
    printf("%f \n", yas[1]);
    printf("%f \n", yas[2]);
    printf("%f \n", yas[3]);
    printf("%f \n", yas[4]);
    printf("%f \n", yas[5]);
    printf("%f \n", yas[6]);
    printf("%f \n", yas[7]);
    printf("%f \n", yas[8]);
    printf("%f \n", yas[9]);


    return 0;
}