#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct {
    int itemNumber;
    float price;
    char description[50];
} Item;

void displayItem(Item item);
void inputItem(Item *item);

int main()
{
    Item items[MAX_ITEMS];
    int i;

    // Initialize the first item with the given values
    items[0].itemNumber = 1111;
    items[0].price = 215.20;
    strcpy(items[0].description, "local sugar");

    // Input the remaining items
    for (i = 1; i < MAX_ITEMS; i++) {
        inputItem(&items[i]);
        if (items[i].itemNumber == 0) {
            // User has indicated that they do not have any more items to input
            break;
        }
    }

    // Display the list of items
    printf("\nList of items:\n");
    for (i = 0; i < MAX_ITEMS && items[i].itemNumber != 0; i++) {
        displayItem(items[i]);
    }

    return 0;
}

void inputItem(Item *item)
{
    printf("\nEnter item number: ");
    scanf("%d", &item->itemNumber);
    if (item->itemNumber == 0) {
        // User has indicated that they do not have any more items to input
        return;
    }

    printf("Enter item description: ");
    scanf("%s", item->description);

    printf("Enter item price: ");
    scanf("%f", &item->price);
}

void displayItem(Item item)
{
    printf("\nItem number: %d", item.itemNumber);
    printf("\nItem description: %s", item.description);
    printf("\nItem price: %.2f", item.price);
}