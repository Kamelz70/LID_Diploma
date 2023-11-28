
#include <stdio.h>
#include <stdlib.h>
void reverseSen()
{
    char c;
    scanf("%c", &c);
    if (c != '\n')
    {
        reverseSen();
        printf("%c", c);
    }
}
int main(void)
{
    printf("Enter a sentence:\n");
    reverseSen();

    return EXIT_SUCCESS;
}
