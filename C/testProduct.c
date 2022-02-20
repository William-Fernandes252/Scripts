/* Uses a macro to test which of the given parameters is greater. */

#include <stdio.h>
#include <stdlib.h>
#define TEST(x, y) ((x)*(y) > 100.0f ? 1.0 : 0.0f)

int main(int argc, char ** argv) {

    if(argc < 3) {
        fprintf(stderr, "Usage: %s x y", argv[0]);
        exit(1);
    }

    float x = atoi(argv[1]);
    float y = atoi(argv[2]);

    if((TEST(x, y)) == 1) {
        printf("%.1f * %.1f > 100.0", x, y);
    }
    else {
        printf("%.1f * %.1f <= 100.0", x, y);
    }

    return 0;

}