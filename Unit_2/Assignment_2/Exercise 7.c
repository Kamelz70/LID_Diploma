
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int c;
    int res = 1;
    puts("Enter an integer:");
    scanf("%d", &c);
    if (c < 0)
    {
        puts("Error, negative factorial doesn't exist");
        return;
    }
    while (c > 0)
    {
        res *= c;
        c--;
    }
    printf("Factorial:%d", res);

    return EXIT_SUCCESS;
}
