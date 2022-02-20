/* Sum the collumns and the rows of a 2-dimensional array */

#include <stdio.h>
#include <stdlib.h>
#define ROWS 5
#define COLUMNS 5

int main() {

    int matrix[ROWS][COLUMNS];
    int row_total[ROWS] = {0};
    int collumn_total[COLUMNS] = {0};
    
    for(int i = 0; i < ROWS; i++) {
        printf("Enter row %d: ", i+1);
        scanf("%d%d%d%d%d", &matrix[i][0], &matrix[i][1], &matrix[i][2], &matrix[i][3], &matrix[i][4]);
    }
    
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            row_total[i] += matrix[i][j];
            collumn_total[j] += matrix[i][j];
        }
    }
    
    puts("Rows total: ");

    for(int i = 0; i < ROWS; i++) {
        printf("%d ", row_total[i]);
    }
    
    printf("\n");

    puts("Collums total: ");

    for(int j = 0; j < COLUMNS; j++) {
        printf("%d ", collumn_total[j]);
    }

    return EXIT_SUCCESS;
}