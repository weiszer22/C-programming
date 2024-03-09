#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    int number;
    float price;
    char description[100];
};

int main() {
    struct Item items[10];
    int i;

    for (i = 0; i < 10; i++) {
        printf("Enter details for item %d:\n", i+1);
        printf("Item number: ");
        scanf("%d", &items[i].number);
        printf("Item price: ");
        scanf("%f", &items[i].price);
        printf("Item description: ");
        scanf(" %[^\n]s", &items[i].description);
    }

    printf("\nList of items:\n");
    printf("%-10s %-20s %s\n", "Number", "Description", "Price");
    for (i = 0; i < 10; i++) {
        printf("%-10d %-20s $%.2f\n", items[i].number, items[i].description, items[i].price);
    }

    return 0;
}