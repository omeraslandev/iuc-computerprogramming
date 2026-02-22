#include <stdio.h>
#include <stdlib.h>

int main(){

    int numbers[5] = {5, 10, 15, 20, 25};

    int *ptr = numbers; // int *ptr = &numbers[0]; desen de olurdu.
    // ptr = &numbers[0] oldu artik.

    *ptr++ = 50;
    // Boylece sunu demis olduk:
    // 1) *ptr = 50 olsun. (yani numbers[0] = 50 olsun.)
    // 2) Ondan sonraki satirda (++... cunku) ptr'nin adresi kaysin.

    // "2. adimi anlamadim?"
    // Normal, cunku burada "++..." ile "...++" isleclerini karistirabiliyoruz.
    // Eger "*++ptr" deseydik, once ptr'nin adresi kayardi sonra da kayan adresteki icerige ulasirdik.
    // Ancak  "*ptr++" dedigimiz zaman, once ptr'nin mevcut adresindeki icerige ulasiriz,
    // islem bittikten sonra (yani bir sonraki satira gectigimizde) ptr'nin adresini arttir.

    // Guncel dizi elemanlarimiz su sekilde:
    // numbers[0] = 50 (Once 50 yaptik, bir sonraki satirda da
    //                  ptr adresi degisecek. Ama o birazdan
    //                  olacak, simdi degil :D)
    // numbers[1] = 10 (Bu ve sonrasi icin degisen birsey yok.)
    // numbers[2] = 15
    // numbers[3] = 20
    // numbers[4] = 25


    *ptr = 100;
    // Burada amacimiz artik "...++" isleciyle bir sonraki
    // satirda adresi kaydirip icerigi "100" olarak degistirmek.


    // Artik en sonki dizi elemanlarimiz su sekilde oldu:
    // numbers[0] = 50 (Bunu artik gectik.)
    // numbers[1] = 100 ( (...++) isleci ile bir sonraki adrese gecmistik
    //                          ve o gecmis oldugumuz adreste &numbers[1]
    //                          vardi. simdi de onun icerigini "100" yaptik.)
    // numbers[2] = 15 
    // numbers[3] = 20
    // numbers[4] = 25
 

    // Simdi ekrana bastiralim.
    for (int i = 0; i < 5; i++){
        printf("%d ", numbers[i]);
        // 50 100 15 20 25
    }

    return 0;
}