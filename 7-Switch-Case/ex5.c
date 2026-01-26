#include <stdio.h>

void show_date(int day, int month, int year){

    printf("Girmis oldugunuz tarih: %d ", day);

     switch (month) {

        case 1: printf("January "); break;
        case 2: printf("February "); break;
        case 3: printf("March "); break;
        case 4: printf("April "); break;
        case 5: printf("May "); break;
        case 6: printf("June "); break;
        case 7: printf("July "); break;
        case 8: printf("August "); break;
        case 9: printf("September "); break;
        case 10: printf("October "); break;
        case 11: printf("November "); break;
        case 12: printf("December "); break;

    }

    printf("%d\n", year);


}

int main(){

    int day;
    int month;
    int year;

    printf("Bitisik bir sekilde bir gun/ay/tarih giriniz: ");
    scanf("%2d%2d%4d", &day, &month, &year); // eger "%d%d%d yapsaydim olmazdi. %2d&2d&4d diyerek aslinda uzunluk belirtmis oluyorum."

    show_date(day, month, year);
}