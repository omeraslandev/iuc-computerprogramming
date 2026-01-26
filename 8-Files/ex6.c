#include <stdio.h>
#include <stdlib.h>

int main(){

    int identity;
    char name[30];
    double balance;

    FILE *database_file;

    if ( (database_file = fopen("customer.txt", "r")) == NULL)
    {
        printf("customer.txt file can not be opened.\n");
        exit(EXIT_FAILURE);
    }

    printf("%-10s %-13s %s \n", "ID........", "Name.........", "Balance");

    while (fscanf(database_file, "%d %s %lf", &identity, name, &balance) == 3)
    {
        printf("%-10d %-13s %.2f \n", identity, name, balance);
    }

    fclose(database_file);

    return 0;

}