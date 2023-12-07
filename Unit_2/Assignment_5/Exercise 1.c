
#include <stdio.h>
#include <stdlib.h>
struct Student
{
    char name[50];
    unsigned int rollNum;
    unsigned int mark;
};

struct but
{
    char name : 1;
    char name1 : 8;
    char name2 : 8;
    char name3 : 8;
    char name4 : 8;
    int cc : 2;
} but;

int main(void)
{
    struct Student s1;
    printf("Enter name:\n");
    scanf("%s", &s1.name);

    printf("Enter roll number:\n");
    scanf("%d", &s1.rollNum);

    printf("Enter mark:\n");
    scanf("%d", &s1.mark);

    printf("Displaying information:\n");

    printf("Name: %s\n", s1.name);
    printf("RollNum: %d\n", s1.rollNum);
    printf("Mark: %d\n", s1.mark);
    printf("size: %d\n", sizeof(but));

    return EXIT_SUCCESS;
}
