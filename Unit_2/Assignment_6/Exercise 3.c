#include <stdio.h>
#include <string.h>
int main()
{
    char str[100], *ptr_str;
    char rev[100], *ptr_rev;
    ptr_rev = rev;
    printf("Input A String : ");
    scanf("%s", str);
    ptr_str = str + strlen(str) - 1;
    while (ptr_str != str)
    {
        *ptr_rev = *ptr_str;
        ptr_str--;
        ptr_rev++;
    }
    *ptr_rev = *ptr_str;
    *++ptr_rev = '\0';
    printf("\nReverse Of The String is : %s", rev);
}