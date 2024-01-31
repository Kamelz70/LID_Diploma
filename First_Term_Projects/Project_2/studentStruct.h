#ifndef STUDENTS_STRUCT_H_
#define STUDENTS_STRUCT_H_
#include "platform_types.h"

#define BUFFER_LENGTH 50
#define MAX_NUM_OF_COURSES 10
#define MAX_NAME_CHARACTERS 50
#define FILENAME "studentsDB.txt"
typedef struct Student
{
    uint8 FirstName[MAX_NAME_CHARACTERS];
    uint8 LastName[MAX_NAME_CHARACTERS];
    uint32 ID;
    float32 GPA;
    uint32 CoursesID[MAX_NUM_OF_COURSES];
    uint32 CoursesNum;
} Student;
#endif