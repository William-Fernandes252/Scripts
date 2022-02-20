#include <stdio.h>
#include "inventory.h"
#include "update.h"

extern part inventory[MAX_PARTS];
extern int num_parts;

void update() {

    int number, i, change;

    printf("Enter part number: ");
    scanf("%d", &number);
    i = find_part(number);

    if(i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        inventory[i].on_hand += change;
    }
    else {
        printf("The item %d was not found in the database.\n", number);
    }

}