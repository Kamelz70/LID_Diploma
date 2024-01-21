/*
 * linked_list.h
 *
 *  Created on: Jan 10, 2021
 *      Author: Shady mamdouh
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

extern struct SStudent *gpFirstStudent;
// extern int Rcount;
typedef struct Sdata
{
    unsigned int ID;
    float height;
    char name[40];

} Sdata;
// linked list node
typedef struct SStudent
{
    struct Sdata student;
    struct SStudent *pNextStudent;

} SStudent;
// counter to calculate length using recursive way
// APIs
void FIFO_AddStudent();
int FIFO_Delete_Student();
void FIFO_view_Students();
void FIFO_Delete_All();
int FIFO_GetNth();
int FIFO_Num_of_nodes();
void FIFO_Reverse_list();
int FIFO_middle_list();
int FIFO_Num_of_nodes_recursive(SStudent *pCurrentStudent);
#endif /* LINKED_LIST_H_ */
