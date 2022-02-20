#include <stdio.h>
#include <stdlib.h>
#define STUDENTS 5
#define TESTS 5

int main(void) {

    int grades[STUDENTS][TESTS];
    int student_total[STUDENTS] = {0};
    int tests_total[TESTS] = {0};

    for(int i = 0; i < STUDENTS; i++) {
        grades[i][0] = i+1;
    }

    for(int i = 0; i < TESTS; i++) {
        grades[0][i] = i+1;
    }
    
    printf("Enter the grades.\n");
    for(int i = 1; i < STUDENTS; i++) {
        printf("Student %d:\n", i);
        for(int j = 1; j < TESTS; j++) {
            printf("Test %d: ", j);
            scanf("%d", &grades[i][j]);
        }
    }
    
    for(int i = 1; i < STUDENTS; i++) {
        for(int j = 1; j < TESTS; j++) {
            student_total[i] += grades[i][j];
            tests_total[j] += grades[i][j];
        }
    }
    
    printf("\nStudents scores\n----------\n");

    printf("\nSum os all scores:\n");
    for(int i = 1; i < STUDENTS; i++) {
        printf("Student %d: %d\n", i, student_total[i]);
    }

    printf("\nAverage of the students:\n");
    for(int i = 1; i < STUDENTS; i++) {
        printf("Student %d: %d\n", i, student_total[i]/(STUDENTS-1));
    }

    printf("\nTests\n----------\n\n");

    int high_score = 0;
    int low_score = 100;
    int average = 0;

    for(int i = 1; i < TESTS; i++) {
        for(int j = 1; j < TESTS; j++) {
            if(grades[i][j] > high_score) {
                high_score = grades[i][j];
            }
            if(grades[i][j] < low_score) {
                low_score = grades[i][j];
            }
            average += grades[i][j];
        }
        printf("Highest score of the test %d: %d\n", i,  high_score);
        printf("Lowest score of the test %d: %d\n", i, low_score);
        printf("Average of the test %d: %d\n\n", i, average/(TESTS-1));
    }

    return EXIT_SUCCESS;
}