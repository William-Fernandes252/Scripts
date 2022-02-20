/* Manage an inventory. */

#include <stdio.h>
#include "inventory.h"
#include "insert.h"
#include "search.h"
#include "update.h"
#include "print.h"

part inventory[MAX_PARTS];
int num_parts = 0;

/*
    main:   Prompts the user to enter an operation code, 
            then calls the function that performs the 
            requested action. Repeats until the user enter 
            the code 'e'. Prints an error message if the 
            operation code entered is invalid.
*/

int main(void) {

    printf("\nOperations:\n----------\n\n"
    "\t'i': Inserts an item into the inventory.\n"
    "\t's': Search for an item in the inventory.\n"
    "\t'u': Update the quantity of an item in the inventory.\n"
    "\t'p': Prints a table of the contents of the inventory.\n"
    "\t'e': Exit the program.\n\n");

    char code;
    for(;;) {

        printf("Enter operation code: ");
        scanf(" %c", &code);
        while(getchar() != '\n') { /* skip to the end of the line. */
            ;
        }

        switch(code) {
            case 'i': insert(); break;
            case 's': search(); break;
            case 'u': update(); break;
            case 'p': print(); break;
            case 'e': return 0; break;
            default: printf("Not a available operation\n"); break;
        }

        printf("\n");

    }

}

int find_part(int part_number) {

    int i = 0;

    for (i = 0; i < num_parts; i++) {
        if(inventory[i].number == part_number) return i;
    }

    return -1;

}