#include <stdio.h>
#define PI 3.14
#define getArea(r) (PI * r * r)
int main()
{
    float radius, area;

    printf("Enter radius:\n");
    scanf("%f", &radius);
    printf("Area is: %.2f\n", getArea(radius));

    return 0;
}