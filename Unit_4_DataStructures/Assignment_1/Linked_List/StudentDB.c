// Author:Mohamed Kamel
#include "linkedList.h"

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    char temp_text[40];
    while (1)
    {
        // Rcount = 0;
        printf("\n==================================================");
        printf("\n \t choose one of the following options \n ");
        printf("\n 1 : Add Student");
        printf("\n 2 : Delete Student");
        printf("\n 3 : View Students");
        printf("\n 4 : Delete all Students");
        printf("\n 5 : Get by index");
        printf("\n 6 : Number of students");
        printf("\n 7 : reverse linked list");
        printf("\n 8 : Get middle of the list");
        // printf("\n 7 : Get Nth from the end of list");
        // printf("\n 10 : NUmber of students (recursive way)");
        printf("\n Enter option number");
        gets(temp_text);
        switch (atoi(temp_text))
        {
        case 1:
            FIFO_AddStudent();
            break;
        case 2:
            FIFO_Delete_Student();
            break;
        case 3:
            FIFO_view_Students();
            break;
        case 4:
            FIFO_Delete_All();
            break;
        case 5:
            FIFO_GetNth();
            break;
        case 6:
            FIFO_Num_of_nodes();
            break;
        case 7:
            FIFO_Reverse_list();
            break;
        case 8:
            FIFO_middle_list();
            break;
        case 9:
            FIFO_Num_of_nodes_recursive(gpFirstStudent);
            break;
        // case 7:
        //     FIFO_GetNth_Reverse_order();
        //     break;
        default:
            printf("\n wrong option");
        }
    }
}
