#include <stdio.h>
#include "inventory.h"
#include "search.h"

extern part inventory[MAX_PARTS];
extern int num_parts;

void search() {

    int number, i;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);

    if(i >= 0) {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity on hand: %d\n", inventory[i].on_hand);
    }
    else {
        printf("The item %d was not found in the database.\n", number);
    }

}