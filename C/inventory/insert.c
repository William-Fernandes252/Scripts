#include <stdio.h>
#include <ctype.h>
#include "inventory.h"
#include "insert.h"

extern part inventory[MAX_PARTS];
extern int num_parts;

int read_line(char str[], int n) {

    int ch, i = 0;

    while(isspace(ch = getchar()))
        ;
    while(ch != '\n' && ch != EOF) {
        if(i < n) str[i++] = ch;
        ch = getchar();
    }

    str[i] = '\0';

    return i;

}

void insert() {

    if(num_parts == MAX_PARTS) {
        printf("Operation denied due to insufficient space in the inventory.\n");
        return;
    }

    int number;

    printf("Enter part number: ");
    scanf("%d", &number);
    
    if(find_part(number) >= 0) {
        printf("The item %d is already in the inventory.\n", number);
        return;
    }

    inventory[num_parts].number = number;
    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LENGTH);
    printf("Enter quantity on hand: ");
    scanf("%d", &inventory[num_parts].on_hand);
    num_parts++;

}