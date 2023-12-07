#include <stdio.h>
#include <string.h>
int main()
{
    int arr[15], *ptr;
    char n;
    ptr = arr;
    printf("Input number of elements to store in the array (max 15) : ");
    scanf("%d", &n);

    for (char i = 0; i < n; i++)
    {
        printf("Element - %d: ", i + 1);
        scanf("%d", ptr);
        ptr++;
    }
    ptr--;

    printf("\nReverse Of The Array is : \n");
    for (char i = n; i > 0; i--)
    {
        printf("\nElement - %d: ", i);
        printf("%d", *ptr);
        ptr--;
    }
}