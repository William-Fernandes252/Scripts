#include<stdio.h>

int main(void)
{
    int gsi_prefix, group_identifier, publisher_code, item_number, check_digit;

    printf("Enter ISBN (with hyphens): ");
    scanf("%d-%d-%d-%d-%d", &gsi_prefix, &group_identifier, &publisher_code, &item_number, &check_digit);

    printf("\nGSI prefix: %d\n", gsi_prefix);
    printf("Group identifier: %d\n", group_identifier);
    printf("Publisher code: %d\n", publisher_code);
    printf("Item number: %d\n", item_number);
    printf("Check digit: %d\n\n", check_digit);

    return 0;
}
