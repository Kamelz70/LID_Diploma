// Author:Mohamed Kamel

#ifndef FIFO_H_
#define FIFO_H_
#include "stdio.h"
#include "platform_types.h"
#include "stdbool.h"
#include "studentStruct.h"

// User Configuration
//  set preferred element type
#define EL_TYPE Student
// set Width
#define WIDTH 4
// fifo data types
typedef struct
{
    unsigned int length;
    unsigned int count;
    EL_TYPE *base;
    EL_TYPE *head;
    EL_TYPE *tail;
} FIFO_Buf_t;

typedef enum
{
    FIFO_no_error,
    FIFO_full,
    FIFO_empty,
    FIFO_null
} FIFO_buf_status;
// Function Declarations
FIFO_buf_status FIFO_init(FIFO_Buf_t *fifo, EL_TYPE *buf, uint32_t length);
FIFO_buf_status FIFO_Enqueue(FIFO_Buf_t *fifo, EL_TYPE item);
FIFO_buf_status FIFO_Dequeue(FIFO_Buf_t *fifo, EL_TYPE *item);
bool FIFO_isFull(FIFO_Buf_t *fifo);
bool FIFO_isEmpty(FIFO_Buf_t *fifo);
bool FIFO_isValid(FIFO_Buf_t *fifo);
void FIFO_print(FIFO_Buf_t *fifo);

#endif // FIFO_H_