#ifndef INVENTORY_H
#define INVENTORY_H
#define NAME_LENGTH 25
#define MAX_PARTS 100

typedef struct {
    int number;                 /* Identifier for the item in the database. */
    char name[NAME_LENGTH+1];   /* Name of the item in the database. */
    int on_hand;                /* Quantity of the item in the database. */
} part;

/*
    find_part:  Looks up a part number in the inventory array. 
                Returns the array index of the part is found 
                in the database. Otherwise, returns -1.
*/
int find_part(int part_number);

#endif