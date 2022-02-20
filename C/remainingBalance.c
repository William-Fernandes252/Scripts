/*Calculates the remaining balance on a loan after the first, second ant third monthly payments*/

#include<stdio.h>

int main(void) {
    float loan, interest_rate, monthly_payment;
    int payments, n;

    printf("Enter the amount of loan: ");
    scanf("%f", &loan);
    printf("Enter the interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter the monthly payments: ");
    scanf("%f", &monthly_payment);
    printf("Enter the amount of payments: ");
    scanf("%d", &payments);

    for(n = 1; n <= payments; ++n){
        printf("Balance remaining after the payment %d: %.2f\n", n, loan - n * monthly_payment + loan * n * interest_rate / 100 / 12);
    }

    return 0;

}
