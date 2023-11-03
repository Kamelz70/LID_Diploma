
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char c;
    puts("Enter a character:");
    scanf("%c", &c);
    if ((c > 'a' && c < 'z') || (c > 'A' && c < 'Z'))
    {
        printf("%c is an Alphabet", c);
    }
    else
    {
        printf("%c is Not an Alphabet", c);
    }
    return EXIT_SUCCESS;
}
