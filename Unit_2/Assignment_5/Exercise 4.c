#include <stdio.h>
struct Student
{
    char name[50];
    unsigned int rollNum;
    float mark;
};
int main()
{
    struct Student s[5];
    int i;
    printf("Enter information of students:\n");
    for (i = 0; i < 5; ++i)
    {
        s[i].rollNum = i + 1;
        printf("\nEnter  roll number %d info. \n", s[i].rollNum);
        printf("Enter name: ");
        scanf("%s", s[i].name);
        printf("Enter mark: ");
        scanf("%f", &s[i].mark);
        printf("\n");
    }
    printf("Displaying students:\n");
    for (i = 0; i < 5; ++i)
    {
        printf("\nInfo. for roll number %d:\n", i + 1);
        printf("Name:");
        puts(s[i].name);
        printf("Mark:%.1f", s[i].mark);
    }
    return 0;
}