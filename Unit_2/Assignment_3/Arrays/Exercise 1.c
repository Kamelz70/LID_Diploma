
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float a[2][2], b[2][2];
    printf("Enter First Matrix:\n");
    for (char i = 0; i < 2; i++)
    {
        for (char j = 0; j < 2; j++)
        {
            printf("Enter A[%d][%d]:\n", i, j);

            scanf("%f", &a[i][j]);
        }
    }
    printf("Enter Second Matrix:\n");
    for (char i = 0; i < 2; i++)
    {
        for (char j = 0; j < 2; j++)
        {
            printf("Enter B[%d][%d]:\n", i, j);

            scanf("%f", &b[i][j]);
        }
    }
    printf("Sum::\n");
    for (char i = 0; i < 2; i++)
    {
        for (char j = 0; j < 2; j++)
        {
            printf("%.2f", a[i][j] + b[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}
