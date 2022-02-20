/*Calculates the volume of a sphere*/

#include <stdio.h>
#define SPHERE_VOLUME_FACTOR 4.0f/3.0f

int main(void)
{
    float v, r;

    printf("Enter the radius of the sphere: ");
    scanf("%f", &r);

    v = SPHERE_VOLUME_FACTOR * 3.14 * r * r * r;

    printf("The volume of the sphere is %.3fm^3\n", v);

    return 0;
}
