#include <stdio.h>
int main()
{
    int *ab;
    int m;
    m = 29;
    printf("Address of m : 0x%p\n", &m);
    printf("Value of m : %d\n\n\n", m);
    ab = &m;
    printf("Now ab is assigned the address of m.\n");
    printf("Address of pointer ab : 0x%p\n", ab);
    printf("Content of pointer ab : %d\n\n", *ab);
    m = 34;
    printf("The value of m assigned to 34\n");
    printf("Address of pointer ab : 0x%p\n", ab);
    printf("Content of pointer ab : %d\n\n", *ab);
    *ab = 7;
    printf("The pointer ab is assigned 7 now\n");
    printf("Address of m : 0x%p\n", &m); // as ab contain the address of m
    // so *ab changed the value of m and now
    printf("Value of m : %d", m);
    return 0;
}