#include <stdio.h>
#include <stdlib.h> // 'malloc' ve 'free' fonksiyonlari icin gerekli.
#include <string.h> // 'strcmp' fonksiyonu icin gerekli.

// Kendi tanimladigimiz yapi (struct).
typedef struct community{
    char name[5];
    int age;

    struct community* next;
} linkedList;

// Fonksiyon prototipleri
void addElement(linkedList** first, linkedList** last);
void listElements(linkedList* first);
void searchElement(linkedList* first);
void deleteElement(linkedList** first, linkedList** last);

int main(){

    // Listenin basini ve sonunu gosteren pointerlar
    linkedList *first = NULL, *last = NULL;
    int job;

    // Kullanici cikis yapana kadar dongu devam edecek
    while(1) {
        printf("\n--- MENU ---\n");
        printf("1) Ekleme Islemi\n");
        printf("2) Listeleme Islemi\n");
        printf("3) Arama Islemi\n");
        printf("4) Silme Islemi\n");
        printf("5) Cikis\n");
        printf("===\nHangi islemi yapmak istiyorsunuz? : ");

        // Kullanicidan gecerli bir tamsayi alinip alinmadigini kontrol et
        if(scanf("%d", &job) != 1){
            printf("Gecersiz giris! Lutfen bir sayi girin.\n");

            // Girdiyi temizle
            while(getchar() != '\n');

            continue;
        }
        switch(job){
            case 1:
                addElement(&first, &last);
                break;
            case 2:
                listElements(first);
                break;
            case 3:
                searchElement(first);
                break;
            case 4:
                deleteElement(&first, &last);
                break;
            case 5:
                printf("Programdan cikiliyor...\n");

                // Bellekte ayrilan tum alani serbest birak
                linkedList* current = first;
                linkedList* nextNode;

                while (current != NULL){
                    nextNode = current -> next;
                    free(current);
                    current = nextNode;
                }

                return 0; // Programi sonlandir.
            default:
                printf("Gecersiz islem numarasi! Lutfen 1-5 arasinda bir secim yapin.\n");
                break;
        }
    }
}

// 1) Listeye yeni bir eleman ekler
void addElement(linkedList** first, linkedList** last){
    // Yeni eleman icin bellekten yer ayir
    linkedList* newNode = (linkedList*)malloc(sizeof(linkedList));

    if(newNode == NULL){
        printf("Bellekten tahsis edilemedi!\n");
        return;
    }

    printf("Eklemek istediginiz kisinin adiniz giriniz: ");
    scanf("%49s", newNode -> name); // Buffer overflow onlemi icin %49s
    printf("Eklemek istediginiz kisinin yasini giriniz: ");
    scanf("%d", &newNode -> age);

    newNode -> next = NULL;

    // Liste bossa, bu eleman hem ilk hem de son eleman olur
    if( *first == NULL ){
        *first = newNode;
        *last = newNode;
    } else {
        // Liste doluysa, elemani sona ekle
        (*last) -> next = newNode;
        *last = newNode;
    }

    printf("'%s' adli kisi listeye eklendi.\n", newNode -> name);
}


// 2) Listedeki tum elemanlari ekrana basar
void listElements(linkedList* first){
    if(first == NULL){
        printf("Liste bos.\n");
        return;
    }

    printf("\n--- Listedeki Kisiler ---\n");

    linkedList* current = first;

    int count = 1;

    while(current != NULL){
        printf("%d) Ad: %s, Yas: %d\n", count, current -> name, current -> age);
        current = current -> next;
        count++;
    }

    printf("---------------\n");
}

// 3) Listede isme gore arama yapar
void searchElement(linkedList* first){
    if (first == NULL){
        printf("Liste bos oldugu icin arama yapilamiyor.\n");
        return;
    }

    char searchName[50];
    printf("Aramak istediginiz kisinin adini giriniz: ");
    scanf("%49s", searchName);

    linkedList* current = first;
    int found = 0;

    while(current != NULL){

        // Iki string ayniysa strcmp 0 dondurur
        if( strcmp( current -> name, searchName ) == 0){
            printf("Bulundu -> Ad: %s, Yas: %d\n", current -> name, current -> age);

            found = 1;
            break; // Ilk eslesmeyi bulduktan sonra donguden cik.
        }

        current = current -> next;
    }

    if (!found) {
        printf("'%s' adli kisi listede bulunamadi.\n", searchName);
    }
}

// 4) Listeden isme gore eleman siler
void deleteElement(linkedList** first, linkedList** last){
    if (*first == NULL){
        printf("Liste bos oldugu icin silme islemi yapilamiyor.\n");

        return;
    }

    char deleteName[50];

}
