#include <stdio.h>
int main()
{
    char alphabet[26] = {0};
    for (char i = 0; i < 26; i++)
    {
        alphabet[i] = i + 'A';
    }
    char *ptr = alphabet;
    printf("The Alphabets Are:\n");
    for (char i = 0; i < 26; i++)
    {
        printf("\t%c", *ptr);
        ptr++;
    }
}