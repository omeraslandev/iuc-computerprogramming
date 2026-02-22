#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE 5

int main(){

    FILE *f;

    int numbers[LIST_SIZE] = {5, 10, 15, 20, 25};
    
    int target_numbers[LIST_SIZE];

    if ( (f = fopen("data", "w+b")) == NULL){
        exit(EXIT_FAILURE);
    }

    fwrite(numbers, sizeof(int), LIST_SIZE, f);
    // Bu satirda aslinda sunu demis oluyoruz:
    // "Su adresteki (numbers) verileri al; her biri su boyutta (sizeof(int)) olsun;
    // bunlardan toplam su kadar (LIST_SIZE) tane paketle ve su dosyaya (f) bas."


    fseek(f, 0, SEEK_SET);
    // fwrite() yaptigimzi icin imlec (yani offset) suan dosyanin sonundadir.
    // fseek() ile biz diyoruz ki: "imleci 0 noktasina, dosyanin en basina gotur"
    // cunku birazdan fead() ile okuma yapacagiz. Butun dosyada okuma yapabilmemiz
    // icin imleci en basa sarmamiz gerekiyor

    fread(target_numbers, sizeof(int), LIST_SIZE, f);
    // Bu satirda da aslinda sunu demis oluyoruz:
    // "Su dosyaya (f) git; oradan her biri su boyutta (sizeof(int)) olan verileri bul;
    // toplam su kadar (LIST_SIZE) tane adet cek ve getirip suraya (target_numbers) bosalt."


    for (int i = 0; i < LIST_SIZE; i++){
        printf("%d\n", target_numbers[i]);
    }

    fclose(f);

    /*
    
    Kisaca tum durumumuz sudur:

    1) Yaz: Bellek → Dosya (fwrite) → Imlec sonda.

    2) Basa Don: Imleci 0. pozisyona cek (fseek).

    3) Oku: Dosya → Bellek (fread) → Imlec tekrar sonda.

    4) Kapat: Kaynaklari serbest birak (fclose).

    */

    return 0;
}