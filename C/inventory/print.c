#include <stdio.h>
#include "inventory.h"
#include "print.h"

extern part inventory[MAX_PARTS];
extern int num_parts;

void print() {

    int i = 0;
    printf("Part Number    Part Name                Quantity on Hand\n");
    for(; i < num_parts; i++) {
        printf("%7d        %-25s%10d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
    }

}