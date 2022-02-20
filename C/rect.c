#include<stdio.h>

struct rect_tag
{
    int left;
    int bottom;
    int right;
    int top;
};
typedef struct rect_tag rect_t;

int main(void)
{
    rect_t myRect;
    myRect.left = -4;
    myRect.bottom = 1;
    myRect.right = 8;
    myRect.top = 6;

    printf("Bottom left = (%d, %d)\n", myRect.left, myRect.bottom);
    printf("Top right = (%d, %d)\n", myRect.right, myRect.top);

    return 0;
}
