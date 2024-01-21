#include "linkedList.h"

struct SStudent *gpFirstStudent = NULL;

void FIFO_AddStudent()
{

    struct SStudent *pNewStudent;
    struct SStudent *pLastStudent;
    // common statements between the 2 conditions
    pNewStudent = malloc(sizeof(struct SStudent));
    pNewStudent->pNextStudent = NULL;
    ////////////////////////////////////////////////////////////////////////
    // on empty List
    if (gpFirstStudent == NULL)
    {
        gpFirstStudent = pNewStudent;
    }
    else
    {
        // add to last element
        pLastStudent = gpFirstStudent;
        while (pLastStudent->pNextStudent != NULL)
        {
            pLastStudent = pLastStudent->pNextStudent;
        }
        pLastStudent->pNextStudent = pNewStudent;
    }
    char temp_text[20] = {0};
    printf("\nEnter Student Name:\n");
    gets(pNewStudent->student.name);
    printf("\nEnter Student ID:\n");
    gets(temp_text);
    pNewStudent->student.ID = atoi(temp_text);
    printf("\n Enter student height :");
    gets(temp_text);
    pNewStudent->student.height = atof(temp_text);

    pNewStudent->pNextStudent = NULL;
}
int FIFO_Delete_Student()
{
    char temp_text[40];
    unsigned int Selected_ID;
    if (gpFirstStudent == NULL)
    {
        return printf("No students to search");
    }
    printf("\n Enter student ID to be deleted:\n");
    gets(temp_text);
    Selected_ID = atoi(temp_text);
    struct SStudent *pCurrStudent = gpFirstStudent, *pPrevStudent;
    // not Null
    while (pCurrStudent)
    {
        if (pCurrStudent->student.ID == Selected_ID)
        {
            if (pCurrStudent == gpFirstStudent)
            {
                // first element
                gpFirstStudent = pCurrStudent->pNextStudent;
            }
            else
            {
                // not first element
                pPrevStudent->pNextStudent = pCurrStudent->pNextStudent;
            }
            // common statement
            free(pCurrStudent);
            printf("\nItem Deleted Successfully");
            return 1;
        }
        pPrevStudent = pCurrStudent;
        pCurrStudent = pCurrStudent->pNextStudent;
    }
    printf("\nItem Not Found");
    return 0;
}
void FIFO_view_Students()
{
    struct SStudent *pCurrStudent = gpFirstStudent;
    int count = 0;
    // check if list is empty
    if (gpFirstStudent == NULL)
    {
        printf("\nNo Students to show ");
        return;
    }

    while (pCurrStudent)
    {
        printf("\n\n------ record number %d : ", count + 1);
        printf("\n\t ID : %d", pCurrStudent->student.ID);
        printf("\n\t Height : %f", pCurrStudent->student.height);
        printf("\n\t Name : %s", pCurrStudent->student.name);
        pCurrStudent = pCurrStudent->pNextStudent;
        count++;
    }
    return;
}
void FIFO_Delete_All()
{

    struct SStudent *pCurrStudent = gpFirstStudent;
    int count = 0;
    // check if list is empty
    if (gpFirstStudent == NULL)
    {
        printf("\nList is already empty ");
        return;
    }

    while (pCurrStudent)
    {
        struct SStudent *pPrevStudent = pCurrStudent;
        pCurrStudent = pCurrStudent->pNextStudent;
        free(pPrevStudent);
    }
    gpFirstStudent = NULL; // because we deleted whole list
    return;
}
int FIFO_GetNth()
{
    int index;
    char temp_text[10];
    struct SStudent *pCurrStudent = gpFirstStudent;
    int count = 0;
    printf("Enter index number :");
    gets(temp_text);
    index = atoi(temp_text);
    // if List is empty
    if (gpFirstStudent == NULL)
    {
        printf("\nNo Students to search");
        return 0;
    }

    while (pCurrStudent)
    {
        if (count == index)
        {
            printf("\n------index number %d : ", index);
            printf("\n\t ID : %d", pCurrStudent->student.ID);
            printf("\n\t Name : %s", pCurrStudent->student.name);
            printf("\n\t Height : %f", pCurrStudent->student.height);
            return 1;
        }
        pCurrStudent = pCurrStudent->pNextStudent;
        count++;
    }
    printf("\n index doesn't exist ");
    return 0;
}
int FIFO_Num_of_nodes()
{
    int count = 0;
    struct SStudent *pCurrStudent = gpFirstStudent;
    if (gpFirstStudent == NULL) // check if empty
    {
        printf("\n No Students to count ");
        return 0;
    }

    while (pCurrStudent)
    {
        pCurrStudent = pCurrStudent->pNextStudent;
        count++;
    }
    printf("\n Number of students : %d ", count);
    return count;
}

void FIFO_Reverse_list()
{
    // check if less than 2 elemets
    if (!gpFirstStudent || !(gpFirstStudent->pNextStudent))
    {
        printf("\n Less than 2 Students ");
        return;
    }
    // initialize 3 pointers to iterate with
    struct SStudent *pCurrStudent = gpFirstStudent, *pPrevStudent = NULL;
    struct SStudent *pNextStudent = pCurrStudent->pNextStudent;
    while (pNextStudent)
    {
        pCurrStudent->pNextStudent = pPrevStudent;
        // iterate
        pPrevStudent = pCurrStudent;
        pCurrStudent = pNextStudent;
        pNextStudent = pNextStudent->pNextStudent;
    }
    // set last student to point to previous
    pCurrStudent->pNextStudent = pPrevStudent;
    // set head
    gpFirstStudent = pCurrStudent;
    return;
}
int FIFO_middle_list()
{
    int oddFlag = 0, count = 0;
    struct SStudent *pFast = gpFirstStudent;
    struct SStudent *pSlow = gpFirstStudent;
    // On empty
    if (gpFirstStudent == NULL)
    {
        printf("\n list is empty ");
        return 0;
    }
    // pFast increments by 2 ,and pSlow increments by 1
    while (pFast)
    {
        pFast = pFast->pNextStudent;
        // if length is odd
        if (pFast == NULL)
        {
            oddFlag = 1;
            break;
        }
        count++;
        pSlow = pSlow->pNextStudent;
        pFast = pFast->pNextStudent;
    }
    // length is even
    if (oddFlag == 0)
    {
        printf("\n length is even, Second middle is :");
    }
    printf("\n index number %d : ", count);
    printf("\n\t ID : %d", pSlow->student.ID);
    printf("\n\t Name : %s", pSlow->student.name);
    printf("\n\t Height : %f", pSlow->student.height);
    return 1;
}
int FIFO_Num_of_nodes_recursive(SStudent *pCurrentStudent)
{
    static unsigned int Rcount = 0;
    // if item is null,
    if (!pCurrentStudent)
    {
        printf("\nNumber of students: %d", Rcount);
        Rcount = 0;
        return 1;
    }
    // increase count and call next
    Rcount++;
    return FIFO_Num_of_nodes_recursive(pCurrentStudent->pNextStudent);
}
