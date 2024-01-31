// Author        : Mohamed Kamel

#ifndef STUDENTS_H_
#define STUDENTS_H_

#include "FIFO.h"
#include "string.h"
#include "studentStruct.h"
#include "platform_types.h"
// //////////////////////////////////////////
// Configuration
// //////////////////////////////////////////
#define BUFFER_LENGTH 50
#define MAX_NUM_OF_COURSES 10
#define MAX_NAME_CHARACTERS 50
#define FILENAME "studentsDB.txt"
// //////////////////////////////////////////
// APIs
// //////////////////////////////////////////
void addManually(FIFO_Buf_t *S_FIFO);
void addFromFile(FIFO_Buf_t *S_FIFO);
void printStudentByID(FIFO_Buf_t *S_FIFO);
void printByFirstName(FIFO_Buf_t *S_FIFO);
void printCourseStudents(FIFO_Buf_t *S_FIFO);
void printAll(FIFO_Buf_t *S_FIFO);
void deleteByID(FIFO_Buf_t *S_FIFO);
void updateByID(FIFO_Buf_t *S_FIFO);
void countStudents(FIFO_Buf_t *S_FIFO);

bool isUniqueID(FIFO_Buf_t *S_FIFO, uint32 ID);
Student *getStudentByID(FIFO_Buf_t *S_FIFO, uint32 ID, int *studentListingNumP);
void printStudentInfo(Student *s);
bool FIFO_validator(FIFO_Buf_t *S_FIFO, bool isEmptyValidate, bool isFullValidate);
void enterStudentInfo(FIFO_Buf_t *S_FIFO, Student *targetStudent, uint8 choice);
// //////////////////////////////////////////
// export student FIFO
// //////////////////////////////////////////
extern Student DB_Buffer[BUFFER_LENGTH];
extern FIFO_Buf_t studentsFIFO;

#endif /* STUDENTS_H_ */
