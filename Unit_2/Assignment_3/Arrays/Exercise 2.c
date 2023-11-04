
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float a[50];
    char num;
    printf("Enter No. of elements:\n");
    scanf("%d", &num);

    for (char i = 0; i < num; i++)
    {

        printf("Enter Element %d\n", i);
        scanf("%f", &a[i]);
    }
    float sum = 0;
    for (char i = 0; i < num; i++)
    {
        sum += a[i];
    }
    printf("Average: %.2f\n", sum / num);
    return EXIT_SUCCESS;
}
