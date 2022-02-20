#include<stdio.h>

int main(void) {
{
    int item_number, mm, dd, yyyy;
    float unit_price;

    printf("Enter the item number: ");
    scanf("%d", &item_number);
    printf("Enter the unit price: ");
    scanf("%f", &unit_price);
    printf("Enter the purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &mm, &dd, &yyyy);

    printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n%-d\t\tR$%.2f\t\t%-d/%d/%d\n", item_number, unit_price, mm, dd, yyyy);

    return 0;

}
