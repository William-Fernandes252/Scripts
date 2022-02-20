/* Split the time given in seconds into hours, minutes and seconds. */

#include <stdio.h>
#include <stdlib.h>
#define SECONDS_IN_A_DAY 86400
#define SECONDS_IN_A_HOUR 3600
#define SECONDS_IN_A_MIN 60

void split_time(unsigned int time, unsigned int *hr, unsigned int *min, unsigned int *sec);

int main(int argc, char **argv) {

    char usage[] = "Usage: ./split_time t where t is the time in seconds since midnight.";

    if(argc != 2) {
        fprintf(stderr, "%s", usage);
        return EXIT_FAILURE;
    }

    unsigned int time = atoi(argv[1]);
    unsigned int hr, min, sec;

    split_time(time, &hr, &min, &sec);

    printf("Splited time hh:mm:ss - %.2d:%.2d:%.2d\n", hr, min, sec);

    return EXIT_SUCCESS;

}

void split_time(unsigned int time, unsigned int *hr, unsigned int *min, unsigned int *sec) {

    *hr = time/SECONDS_IN_A_DAY;
    *min = (time % SECONDS_IN_A_DAY)/(SECONDS_IN_A_MIN);
    *sec = (time % SECONDS_IN_A_MIN);

}