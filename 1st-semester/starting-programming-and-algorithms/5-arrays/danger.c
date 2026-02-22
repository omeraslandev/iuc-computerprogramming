#include <stdio.h>


/*
Değişik, tehlikeli bir kod örneğini inceliyorum...
*/
int main()
{
    
    int k = 10;
    int i = 5;
    int liste[20];

    liste[k++] = 100;
    // `liste[10] = 100` işlemi yapıldı.
    // Hafızada `k = 11` oldu.

    printf("Listenin %d. indisi %d", k++, liste[k++]);
    
    /*
    Terminalde şunu yazdı: "Listenin 12. indisi 32765"

    Bu çıktı, C'de Undefined Behavior denilen hatanın canlı kanıtı.

    "12" yazmasının sebebi tamamen benim derleyicimin kodu okuma yönüyle alakalı.
    GCC derleyicisi kullanıyorum ve derleyicim parametreleri sağdan sola doğru okudu.

    Sırayla şu işlemler gerçekleşti:

    1) Derleyici önce sağdaki `liste[k++]` ifadesini çalıştırdı.
        a) `k = 11` kullanıldı.
        b) YAN ETKİ olarak hafızada `k = 12` oldu.
    2) Sonra derleyicim soldaki `k++` ifadesine geçti. 
        a) Artık `k = 12` olduğu için ekrana 12 yazdırdı.
        b) YAN ETKİ olarak hafızada `k = 13` oldu.

    Eğer kodu Visual Studio veya Clang gibi başka bir derleyicide çalıştırsaydım
    muhtemelen ekranda "11" görecektim. Bu kod tam anlamıyla bir mühendislik hatasıdır.

    -

    "3265" yazmasının sebebi de liste[11]'in tanımsız olmasından kaynaklıydı.

    1) Belleğin "o" hücresinde bilgisayarın daha önceki bir işleminden kalan rastgele bir
        elektrik yükü (bit yığını) vardı.
    2) O bit yığınının onluk tabandaki karşılığı şans eseri "32765" di.
        funfact: { 32765 sayısının ikilik sistemdeki karşılığını bulmak için çok güzel bir yöntem var.
        16 bitlik bir signed integer 'a sığabilecek en büyük sayı "32767" yani  "111 1111 1111 1111" dır.
        Yani, karşımıza çıkan sayı 32767'den 2 eksik. 10'luk sistemdeki 2 ise 2'lik sistemde "10" demektir.
        111 1111 1111 1111 (32767) - 10 (2) = 111 1111 1111 1101 (32765)
        }
    3) Her neyse, bugün "32765" çıktı ama yarın "-67421" çıkabiir.
        Sonuç olarak aynı satırda birden fazla Post-increment kullanılmamalı.

    */
    

    return 0;
}