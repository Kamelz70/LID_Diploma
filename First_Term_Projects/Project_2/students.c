
#include "students.h"
#include "FIFO.h"
// //////////////////////////////////////////
// Student FIFO & Buffer
// //////////////////////////////////////////
Student DB_Buffer[BUFFER_LENGTH];
FIFO_Buf_t studentsFIFO;

// //////////////////////////////////////////
// APIs
// //////////////////////////////////////////
void addManually(FIFO_Buf_t *S_FIFO)
{
    // check if fifo is invalid or full
    // works as intended
    if (!FIFO_validator(S_FIFO, false, true))
    {
        return;
    }

    Student newStudent = {0};
    enterStudentInfo(S_FIFO, &newStudent, 0);
    // add this student to the database
    FIFO_buf_status BufS = FIFO_Enqueue(S_FIFO, newStudent);
    if (BufS == FIFO_no_error)
    {
        printf("Student added successfully\n");
        printf("=============================");
    }
    else
    {
        printf("Couldn't add Student\n");
        printf("=============================");
    }
    countStudents(S_FIFO);
}
void addFromFile(FIFO_Buf_t *S_FIFO)
{

    // check if fifo is invalid or full
    if (!FIFO_validator(S_FIFO, false, true))
    {
        return;
    }
    FILE *studentFile;
    Student newStudent;
    //* Opening file
    studentFile = fopen(FILENAME, "r");

    // file check
    if (!studentFile)
    {
        printf("=====================================\n");
        printf("*File not fount\n");
        printf("=====================================\n");
        return;
    }
    //* reading file
    while (!feof(studentFile))
    {

        //* Reading ID from file
        fscanf(studentFile, "%d", &newStudent.ID);
        if (!isUniqueID(S_FIFO, newStudent.ID))
        {
            printf("===============================================\n");
            printf("* ID %d is Already Taken\n", newStudent.ID);
            printf("===============================================\n\n");
            // read next line
            fscanf(studentFile, "%*[^\n]");
            continue;
        }
        fscanf(studentFile, "%s", newStudent.FirstName);
        fscanf(studentFile, "%s", newStudent.LastName);
        fscanf(studentFile, "%f", &newStudent.GPA);
        fscanf(studentFile, "%d", &newStudent.CoursesNum);

        for (uint8 i = 0; i < newStudent.CoursesNum; i++)
        {
            fscanf(studentFile, "%d", &newStudent.CoursesID[i]);
        }

        if (FIFO_Enqueue(S_FIFO, newStudent) == FIFO_no_error)
        {
            printf("* Student with ID %d Saved Successfully\n", newStudent.ID);
        }
        else
        {
            printf("=================================\n");
            printf("*Adding Student From File Failed\n");
            printf("=================================\n");
            return;
        }
    }

    //  Close file
    fclose(studentFile);
    printf("=============================");
    countStudents(S_FIFO);
}
// Prints all students
void printAll(FIFO_Buf_t *S_FIFO)
{
    // check if fifo is invalid or empty
    if (!FIFO_validator(S_FIFO, true, false))
    {
        return;
    }
    Student *currentS = S_FIFO->tail;
    // start printing each student
    for (uint8 i = 0; i < S_FIFO->count; i++)
    {
        printStudentInfo(currentS);
        if (currentS == (S_FIFO->base + (S_FIFO->length)))
            currentS = S_FIFO->base;
        else
            currentS++;
    }
    printf("=============================================\n");
}
void deleteByID(FIFO_Buf_t *S_FIFO)
{
    uint32 ID;
    printf("Enter Student ID to delete");
    scanf("%d", &ID);

    // var for saving student listing number (0-indexed)
    int studentListingNum = -1;
    Student *targetStudent = getStudentByID(S_FIFO, ID, &studentListingNum);
    if (!targetStudent)
    {
        printf("=====================================\n");
        printf("Student ID not found");
        printf("=====================================\n");
        return;
    }
    else
    {
        Student *current = targetStudent;
        Student *next = targetStudent + 1;
        // shift back next students

        for (unsigned int j = studentListingNum; j < S_FIFO->count; j++)
        {
            // if current pointer passed the buffer memory
            if (current == S_FIFO->base + S_FIFO->length)
            {
                current = S_FIFO->base;
            }
            // if next pointer passed the buffer memory
            if (next == S_FIFO->base + S_FIFO->length)
            {
                next = S_FIFO->base;
            }
            // put next in current
            *current = *next;

            next++;
            current++;
        }
        // decrease FIFO count
        S_FIFO->count--;

        S_FIFO->head--;
        if (S_FIFO->head < S_FIFO->base)
        {
            //        	if head pointer is lower than base
            S_FIFO->head = (S_FIFO->base + (S_FIFO->length - 1));
            next = S_FIFO->base;
        }
    }

    printf("=====================================\n");
    printf("Student deleted successfully");
    printf("=====================================\n");
}
void updateByID(FIFO_Buf_t *S_FIFO)
{
    uint32 ID;
    printf("Enter Student ID to update");
    scanf("%d", &ID);

    Student *targetStudent = getStudentByID(S_FIFO, ID, NULL);
    if (!targetStudent)
    {
        printf("=====================================\n");
        printf("Student ID not found");
        printf("=====================================\n");
        return;
    }
    else
    {
        uint8 choice;
        while (1)
        {
            printf("1) Update First Name\n");
            printf("2) Update Last Name\n");
            printf("3) Update ID\n");
            printf("4) Update GPA\n");
            printf("5) Update Courses\n");
            scanf("%hhu", &choice);
            if (choice > 5)
            {
                printf("\ninvalid choice");
                continue;
            }
            else
            {
                break;
            }
        }
        enterStudentInfo(S_FIFO, targetStudent, choice);
    }

    printf("=====================================\n");
    printf("Student Updated successfully");
    printf("=====================================\n");
}
void countStudents(FIFO_Buf_t *S_FIFO)
{
    // check if fifo is invalid
    if (!FIFO_validator(S_FIFO, false, false))
    {
        return;
    }
    printf("The Total Number Of Students is %d\n", S_FIFO->count);
    printf("You Can Add Up To %d Students\n", S_FIFO->length);
    printf("You Can Add %d More Students\n", S_FIFO->length - S_FIFO->count);
    printf("===================================================\n");
}
void printStudentByID(FIFO_Buf_t *S_FIFO)
{
    uint32 ID;
    printf("Enter Student ID:");
    scanf("%d", &ID);
    // if FIFO Is empty
    // check if fifo is invalid or empty
    if (!FIFO_validator(S_FIFO, true, false))
    {
        return;
    }

    Student *result = getStudentByID(S_FIFO, ID, NULL);
    if (!result)
    {
        printf("=====================================\n");
        printf("Student ID not found");
        printf("=====================================\n");
        return;
    }
    else
    {
        printStudentInfo(result);
    }
}
void printByFirstName(FIFO_Buf_t *S_FIFO)
{
    // check if fifo is invalid or empty
    if (!FIFO_validator(S_FIFO, true, false))
    {
        return;
    }
    printf("Enter First name to search:");
    uint8 firstName[MAX_NAME_CHARACTERS];
    scanf("%s", firstName);
    // iterator
    Student *currStudent = S_FIFO->tail;
    for (uint8 i = 0; i < S_FIFO->count; i++)
    {
        // if ID is found, return
        if (!strcmp((const char *)currStudent->FirstName, (const char *)firstName))
        {
            // if compare returns 0, name found
            printStudentInfo(currStudent);
            return;
        }
        // iterate crurrent
        if (currStudent == S_FIFO->base + (S_FIFO->length))
        {
            currStudent = S_FIFO->base;
        }
        else
        {
            currStudent++;
        }
    }
    // if not found
    printf("=====================================\n");
    printf("Student name not found");
    printf("=====================================\n");

    return;
}

void printCourseStudents(FIFO_Buf_t *S_FIFO)
{
    // check if fifo is invalid or empty
    if (!FIFO_validator(S_FIFO, true, false))
    {
        return;
    }
    printf("Enter Course ID to search:");
    uint32 courseID;
    scanf("%d", &courseID);
    // iterator
    Student *currStudent = S_FIFO->tail;
    bool printFlag = false;
    for (uint8 i = 0; i < S_FIFO->count; i++)
    {
        // if ID is found, return

        for (uint8 j = 0; j < currStudent->CoursesNum; j++)
        {
            // iterate on all courses for each student, then print student on match
            if (currStudent->CoursesID[j] == courseID)
            {
                printFlag = true;
                printStudentInfo(currStudent);
                break;
            }
        }
        // iterate crurrent
        if (currStudent == S_FIFO->base + (S_FIFO->length))
        {
            currStudent = S_FIFO->base;
        }
        else
        {
            currStudent++;
        }
    }
    // if not found
    if (!printFlag)
    {

        printf("=====================================\n");
        printf("No Students found taking such course");
        printf("=====================================\n");
    }

    return;
}
//////////////////////////////////////////
// Helper Functions
// //////////////////////////////////////////
bool FIFO_validator(FIFO_Buf_t *S_FIFO, bool isEmptyValidate, bool isFullValidate)
{
    if (!FIFO_isValid(S_FIFO))
    {
        printf("FIFO_isValid:%d", FIFO_isValid(S_FIFO));

        printf("=====================================\n");
        printf("Queue isn't initialized/corrupt");
        printf("=====================================\n");
        return false;
    }
    if (isEmptyValidate && FIFO_isEmpty(S_FIFO))
    {
        printf("=====================================\n");
        printf("FIFO is Empty, no students");
        printf("=====================================\n");
        return false;
    }
    if (isFullValidate && FIFO_isFull(S_FIFO))
    {
        printf("=====================================\n");
        printf("FIFO is FULL, Can't add anymore data");
        printf("=====================================\n");
        return false;
    }
    return true;
}
// studentListingNumP: is an unsigned int* to save the student listing Number
// Used in delete student to find student place in buffer
// if you ListingNum isn't needed, pass it as NULL
Student *getStudentByID(FIFO_Buf_t *S_FIFO, uint32 ID, int *studentListingNumP)
{
    // isStudentListingNeeded to see if an extra argument of student
    // Used in delete student

    //  distance from base pointer should be passed
    // unsigned int *distanceFromBaseP = NULL;
    // student listing number pointer should be passed

    // check if fifo is invalid or empty
    if (!FIFO_validator(S_FIFO, false, false))
    {
        return NULL;
    }
    if (FIFO_isEmpty(S_FIFO))
    {
        return NULL;
    }
    // iterator
    Student *currStudent = S_FIFO->tail;
    for (uint8 i = 0; i < S_FIFO->count; i++)
    {
        // if ID is found, return
        if (currStudent->ID == ID)
        {
            if (studentListingNumP)
            {
                // Calculate student distance from base
                //                *distanceFromBaseP = currStudent - S_FIFO->base;
                *studentListingNumP = i;
            }
            return currStudent;
        }
        // iterate crurrent
        if (currStudent == S_FIFO->base + (S_FIFO->length))
        {
            currStudent = S_FIFO->base;
        }
        else
        {
            currStudent++;
        }
    }
    // if not found, return NULL
    return NULL;
}
// check if an ID is unique
bool isUniqueID(FIFO_Buf_t *S_FIFO, uint32 ID)
{
    // getStudentByID validates the FIFO, no need for guards
    if (!getStudentByID(S_FIFO, ID, NULL))
    {
        // if result s null (no student with such id)
        return true;
    }
    else
    {
        // if there's another student with such ID
        return false;
    }
}
void printStudentInfo(Student *Student)
{
    // print students information
    printf("==================Student=====================\n");
    printf("=============================================\n");
    printf("ID:\t%d\n", Student->ID);
    printf("First Name is:\t%s\n", Student->FirstName);
    printf("Last Name is:\t%s\n", Student->LastName);
    printf("GPA: \t%.2f\n", Student->GPA);
    printf("No. Of Courses Enrolled:\t %d\n", Student->CoursesNum);
    for (int i = 0; i < Student->CoursesNum; i++)
    {
        printf("Course Number %d ID is %d\n", i + 1, Student->CoursesID[i]);
    }
    printf("=============================================\n");
}

void enterStudentInfo(FIFO_Buf_t *S_FIFO, Student *targetStudent, uint8 choice)
{
    // check if fifo is invalid
    if (!FIFO_validator(S_FIFO, false, false))
    {
        return;
    }

    switch (choice)
    {
        // if 0 choice passed, enter all data
    case 0:
    case 1:
        // //////////////////////First Name
        printf("Enter Student First Name : ");
        scanf(" %s", targetStudent->FirstName);
        if (choice)
            break;
    case 2:
        // //////////////////////Last Name
        printf("Enter Student Last Name : ");
        scanf(" %s", targetStudent->LastName);
        if (choice)
            break;
    case 3:
        // //////////////////////ID
        // recieve IDs until one is valid
        while (1)
        {
            // entering student ID
            printf("Enter A Unique Student ID : ");
            scanf("%d", &targetStudent->ID);
            if (!isUniqueID(S_FIFO, targetStudent->ID))
            {
                printf("\nID already taken");
                continue;
            }
            else
            {
                break;
            }
        }
        if (choice)
            break;
    case 4:
        // //////////////////////GPA
        printf("Enter Student GPA : ");
        scanf("%f", &targetStudent->GPA);
        if (choice)
            break;
    case 5:
        // //////////////////////Courses
        while (1)
        {
            // getting the number of courses are enrolled in
            printf("Enter The Number Of Courses choosen (MAX = %d): ", MAX_NUM_OF_COURSES);
            scanf("%d", &targetStudent->CoursesNum);
            if (targetStudent->CoursesNum > MAX_NUM_OF_COURSES)
            {
                printf("\nToo Many Courses");
                continue;
            }
            else
            {
                break;
            }
        }
        // Entering Courses
        for (unsigned char i = 0; i < targetStudent->CoursesNum; i++)
        {
            printf(" Enter ID for Course No. %d : ", i + 1);
            scanf("%d", &targetStudent->CoursesID[i]);
        }

        break;
    default:
        printf("Invalid Choice\n");
        break;
    }
}
