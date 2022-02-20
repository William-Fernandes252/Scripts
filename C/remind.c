#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_REMIND 50 /* Maximum number of reminders. */
#define MSG_LEN 60 /* Max length of. */

unsigned short read_line(char *, unsigned short);

int main(void) {
    char reminders[MAX_REMIND][MSG_LEN + 3];
    char day_str[3], msg_str[MSG_LEN + 1];
    int day, i, j, num_remind = 0;

    for(;;) {
        if(num_remind == MAX_REMIND) {
            puts("--- No space left ---");
            break;
        }

        printf("Enter day and reminder: ");
        scanf("%2d", &day);
        if(day == 0) {
            break;
        }
        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSG_LEN);

        for(i = 0; i < num_remind; i++) {
            if(strcmp(day_str, reminders[i]) < 0) {
                break;
            }
        }
        for(j = num_remind; j > i; j--) {
            strcpy(reminders[j], reminders[j-i]);
        }

        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nDay Reminder:\n");
    for(i = 0; i < num_remind; i++) {
        printf(" %s\n", reminders[i]);
    }

    return EXIT_SUCCESS;
}

unsigned short read_line(char *str, unsigned short n) {
    int ch; 
    unsigned short i = 0;
    
    while((ch = getchar()) != '\n') {
        if(i < n) {
            str[i++] = ch;
        }
    }

    str[i] = '\0';

    return i;
}