
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float a[50][50];
    float trans[50][50];
    printf("Enter Matrix rows:\n");
    int rows, cols;
    scanf("%d", &rows);
    printf("Enter Matrix columns:\n");
    scanf("%d", &cols);
    printf("Enter Matrix:\n");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter A[%d][%d]:\n", i, j);

            scanf("%f", &a[i][j]);
        }
    }

    for (char i = 0; i < rows; i++)
    {
        for (char j = 0; j < cols; j++)
        {
            printf("%.2f", a[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    for (char i = 0; i < rows; i++)
    {
        for (char j = 0; j < cols; j++)
        {
            trans[j][i] = a[i][j];
        }
    }
    printf("Transpose:\n");

    for (char i = 0; i < cols; i++)
    {
        for (char j = 0; j < rows; j++)
        {
            printf("%.2f", trans[i][j]);
            printf("\t");
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}
