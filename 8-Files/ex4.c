#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *fsource;
    FILE *ftarget;
    int character;

    // Kaynak dosyayi acma
    if ( (fsource = fopen("sourcefile.txt", "r")) == NULL ){
        fprintf( stderr, "Error: sourcefile.txt can not be opened.\n");
        // "stderr" nedir?

        // C dilinde üç temel veri yolu vardir:
        // 1) stdin "std-in": Klavye girisi.
        // 2) stdout "std-out": Normal ekran ciktilari. (printf buraya yazar)
        // 3) stderr "std-err": Hata mesajlarinin gonderildigi ozel yol.

        // Neden "printf" degil de "fprintf(stderr, ...) kullandik?"
        // Cunku bir kullanici programin ciktilarini
        // bir dosyaya yonlendirirse ( program > output.txt  gibi),
        // normal ciktilar dosyaya gider ama hata mesajlari ( stderr )
        // hala ekranda gorunmeye devam eder.
        // Boylece kullanici bir seylerin ters gittigini aninda fark eder.
        // Hatalari aninda yakalamak da elbette bizim istedigimiz bir durum.

        
        exit(EXIT_FAILURE);
        // Bu komut, programı o anda aniden durdurur
        // ve isletim sistemine "Bu program,
        // normal bir sekilde bitmedi, bir hata olustu!"
        // mesajini gonderir.
    }

    // Hedef dosyayi acma.
    if ( (ftarget = fopen("targetfile.txt", "w")) == NULL ){
        fprintf(stderr, "Error: targetfile.txt can not be created.\n");
        // bkz: 13. satır

        fclose(fsource);
        exit(EXIT_FAILURE);
    }


    // Karakter karakter kopyalama
    while ( (character = fgetc(fsource)) != EOF ){
        fputc(character, ftarget);
    }

    // Dosyalari guvenli bir sekilde kapatma
    fclose(fsource);
    fclose(ftarget);

    printf("Dosya basariyla kopyalandi.\n");
    return 0;

}