
#include <stdio.h>
#include <stdlib.h>
struct Distance
{
    unsigned int feet;
    float inch;
};

int main(void)
{
    struct Distance d1, d2, sum;
    printf("Enter 1st distance:\n");
    printf("Enter feet:");
    scanf("%d", &d1.feet);
    printf("\n");
    printf("Enter inch:");
    scanf("%f", &d1.inch);
    printf("\n");

    printf("Enter 2ndt distance:\n");
    printf("Enter feet:");
    scanf("%d", &d2.feet);
    printf("\n");
    printf("Enter inch:");
    scanf("%f", &d2.inch);
    printf("\n");

    sum.inch = d1.inch + d2.inch;
    sum.feet = d1.feet + d2.feet;
    while (sum.inch > 12)
    {
        sum.feet++;
        sum.inch -= 12;
    }

    printf("Sum of distances: %d' - %.2f\"\n", sum.feet, sum.inch);

    return EXIT_SUCCESS;
}
