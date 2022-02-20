#ifndef INSERT_H
#define INSERT_H

/*
    read_line:  Skips leading white-space characters, then 
                reads the remainder of the input line and 
                stores it in str. Truncates the line if its 
                length exceeds n. Returns the numbers of 
                caracters stored.
*/
int read_line(char str[], int n);

/*
    insert: Inserts an item in the inventory. Prints an 
            error message if the item already exists or 
            the database is full.
*/
void insert();

#endif