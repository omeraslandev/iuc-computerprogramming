#include <stdio.h>

int reverseNumber(int n)
{
    int reverse_n = 0;
    while (n) {
        reverse_n = reverse_n * 10 + n % 10;
        n = n/10; //n /= 10;
    }

    return reverse_n;
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Reverse of %d number: %d \n", n, reverseNumber(n));
}