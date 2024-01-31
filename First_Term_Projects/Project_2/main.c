/*************************************************************************/
// Author        : Marina Safwat Barsoum Gerges
// Project       : Student_Information_Management_System_Project
// File          : main.c
// Date          : Dec 22, 2023
// GitHub        : https://github.com/Marina-Safwat
/*************************************************************************/

#include "Students.h"
#include "FIFO.h"

// create queue and struct for it's information

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    // init fifo, studentsFIFO & DB_Buffer & BUFFER_LENGTH are declared as extern in Students.h
    FIFO_init(&studentsFIFO, DB_Buffer, BUFFER_LENGTH);
    while (1)
    {
        printf("Choose One Of The Following Options\n");
        printf("1: Add Student(Manually)\n");
        printf("2: Add Student(Text File)\n");
        printf("3: Print All Students\n");
        printf("4: Print Student(By ID)\n");
        printf("5: Print Student(By First Name)\n");
        printf("6: Print All Students Enrolled In A Course(Course ID)\n");
        printf("7: Delete Student(By ID)\n");
        printf("8: Update Student(By ID)\n");
        printf("9: Get Total Number Of Students\n");
        printf("10: Exit The Program\n");

        int choice;
        scanf("%d", &choice);
        printf("=============================================\n");

        // important declaration
        // int n;

        switch (choice)
        {
        case 1:
            addManually(&studentsFIFO);
            break;
        case 2:
            addFromFile(&studentsFIFO);
            break;
        case 3:
            printAll(&studentsFIFO);
            break;
        case 4:
            printStudentByID(&studentsFIFO);
            break;
        case 5:
            printByFirstName(&studentsFIFO);
            break;
        case 6:
            printCourseStudents(&studentsFIFO);
            break;
        case 7:
            deleteByID(&studentsFIFO);
            break;
        case 8:
            updateByID(&studentsFIFO);
            break;
        case 9:
            countStudents(&studentsFIFO);
            break;
        case 10:
            break;
        default:
            printf("invalid choice======\n");
            break;
        }
        // if option = 14 break the loop to exit the program
        if (choice == 10)
        {
            printf("============Exiting======================\n");
            printf("=============================================\n");
            break;
        }
    }

    return 0;
}
