#include <stdio.h>

int main(){


    /*
    Programimin mantigi su sekilde isliyor:

    	*		    star=1	   	n-16	|	space=8		k+8     |   star+space=9
       ***		    star=3	   	n-14	|	space=7		k+7     |   star+space=10
      *****		    star=5		n-12	|	space=6		k+6     |   star+space=11
     *******		star=7		n-10	|	space=5		k+5     |   star+space=12
    *********		star=9		n-8	    |	space=4		k+4     |   star+space=13
   ***********		star=11		n-6	    |	space=3		k+3     |   star+space=14
  *************		star=13		n-4	    |	space=2		k+2     |   star+space=15
 ***************	star=15		n-2	    |	space=1		k+1     |   star+space=16
*****************	star=17		n	    |	space=0		k       |   star+space=17
 ***************	star=15		n-2	    |	space=1		k+1     |   star+space=16
  *************		star=13		n-4	    |	space=2		k+2     |   star+space=15
   ***********		star=11		n-6	    |	space=3		k+3     |   star+space=14
    *********		star=9		n-8	    |	space=4		k+4     |   star+space=13
     *******		star=7		n-10	|	space=5		k+5     |   star+space=12
      *****		    star=5		n-12	|	space=6		k+6     |   star+space=11
       ***		    star=3		n-14	|	space=7		k+7     |   star+space=10
        *		    star=1		n-16	|	space=8		k+8     |   star+space=9

    Karmasik gorunen bu program, aslinda her bir satirda belirli bir sayida "space"
    ve "star" karakterlerinden olusturan bir ekrana yazdirma algoritmasidir.

    1) Ilk satirda program ilk once 8 tane bosluk birakir, sonra 1 tane yildiz ekler.
    2) Ikinci satirda program 7 tane bosluk birakir, sonra 3 tane yildiz ekler.
    3) 6 bosluk, 5 yildiz
    4) 5 bosluk, 7 yildiz
    5)...

    Ve program 8 kere calistiktan sonra, artik eskenar ucgenin kosegenini gosteren cizgi ve
    eskenar ucgenin altta kalan yarisini cizmeliyiz.

    1) Ilk satirda program bu sefer bosluk birakmaz, 17 tane yildiz ekler. Cunku kosegeni ciziyoruz.
    2) Ikınci satirda program 1 tane bosluk birakir, 15 tane yildiz ekler.
    3) 2 bosluk, 13 yildiz
    4) 3 bosluk, 11 yildiz
    5)...

    Ikıncı operasyonumuzda program 9 defa calisir (kosegen + 8 = 9, ikinci while dongusunde
    "n != -1" yazmamizin sebebi programi 1 kez daha calistirabilmekti.)

    Boylece program sona erer.
    */

    int n = 1;

    int k = 8;


    while(n != 17){

        for(int i = k; i > 0; i--){

            printf(" ");

        }

        for(int i = 0; i < n; i++){

            printf("*");

        }

        n += 2;

        k -= 1;

        printf("\n");

    }



    n = 17;

    k = 0;

    while(n != -1){ // n != -1 yazdim cunku ikinci operasyonda birinci operasyonda yaptigimiz
                    // seklin simetrisini almamizin yaninda eskenar ucgenin kosegenini de cizmis
                    // olmamiz gerekiyordu. Bu yuzden programi bir kez daha calismaya zorladik.
                    // n != 1 deseydim, eskenar ucgenin kosegeni yazilacakti ancak
                    // bu sefer de son satirdaki tek yildiz isaretli satir elimine edilmis olacakti.

        for(int i = 0; i < k; i++){

            printf(" ");

        }

        for(int i = 0; i < n; i++){

            printf("*");

        }

        n -= 2;

        k += 1;

        printf("\n");

    }

    return 0;
}

/*

    DIPNOT:

    Kodun esnek olmadiginin, "Dont Repeat Yourself" mantigina aykiri oldugunun ve tek dongu yerine iki dongu
    kullanmanin mantiksizliginin farkindayim.

    Suan icin elimden gelenin en iyisi bu.

    Gelecek kodlarımda, "Ben bunu degistirmek istesem ne kadar ugrasirim?" sorusunu sormaya ve olabildigince
    esnek, evrensel ve okunabilir kodlar yazmaya gayret edecegim.

*/