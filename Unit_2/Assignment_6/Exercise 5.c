#include <stdio.h>
struct employee
{
    char *name;
    int id;
};
int main()
{
    static struct employee em1 = {"Tonya", 3343}, em2 = {"Ahmed", 2342}, em3 = {"Khaled", 42524};
    struct employee(*arr[3]) = {&em1, &em2, &em3};
    // struct employee(*ptr) = arr[0];
    struct employee(*(*ptr)[3]) = &arr;
    printf(" Exmployee Name : %s \n", (**(*ptr + 1)).name);
    printf(" Exmployee ID : %d \n", (**(*ptr + 1)).id);
    printf("\n\n");
    return 6;
}