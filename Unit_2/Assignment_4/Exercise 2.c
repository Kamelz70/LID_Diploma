
#include <stdio.h>
#include <stdlib.h>
int factorial(int n)
{
    if (n > 0)
    {
        return n * factorial(n - 1);
    }
    else
    {
        return 1;
    }
}
int main(void)
{
    int num;
    printf("Enter a positive integer (factorial):\n");
    scanf("%d", &num);

    printf("result of fact(%d): %d\n", num, factorial(num));

    return EXIT_SUCCESS;
}
