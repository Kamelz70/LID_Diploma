
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char str[100];
    printf("enter String:");
    gets(str);
    int len = strlen(str);
    printf("\n");

    char i = 0;
    while (i <= (len / 2))
    {
        char tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
        i++;
    }
    printf("Reversed String:");
    printf("%s", str);

    return EXIT_SUCCESS;
}
