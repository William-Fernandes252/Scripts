/* Checks if a given sentence is a palindrome. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define N 50

int read_message(char a[], int n);
void print_message(char a[], int n);
bool is_palindrome(char a[], int n);

int main(void)
{
    char message[N];

    int length = read_message(message, N);
    printf("%sPalindrome\n", is_palindrome(message, length) ? "" : "Not a ");

    return EXIT_SUCCESS;
}

int read_message(char a[], int n)
{
    char ch;
    int i = 0;
    printf("Enter a message: ");
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (tolower(ch) >= 'a' && toupper(ch) <= 'z') {
            a[i] = tolower(ch);
            i++;
        }
    }

    return i;

}

bool is_palindrome(char a[], int n)
{

    char *ptr_start = a, *ptr_end = a + n - 1;
    while (ptr_start < ptr_end) {
        if (*ptr_start++ != *ptr_end--)
            return false;
    }

    return true;
    
}

