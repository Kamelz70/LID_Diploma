
#include <stdio.h>
#include <stdlib.h>
int power(int base, int exponent)
{
    if (exponent)
    {
        return base * power(base, exponent - 1);
    }
    else
    {
        return 1;
    }
}
int main(void)
{
    int base = 0, exp = 0;
    printf("Enter Base:\n");
    scanf("%d", &base);
    printf("Enter Exponent:\n");
    scanf("%d", &exp);
    printf("%d ^ %d = %d\n", base, exp, power(base, exp));

    return EXIT_SUCCESS;
}
