// Author:Mohamed Kamel

#ifndef _LIFO_H_
#define _LIFO_H_

typedef struct
{
    unsigned int length;
    unsigned int count;
    unsigned int *head;
    unsigned int *base;
} LIFO_Buf_t;

typedef enum
{
    LIFO_no_error,
    LIFO_full,
    LIFO_empty,
    LIFO_null
} LIFO_status;

// Function Declarations
LIFO_status LIFO_Add_item(LIFO_Buf_t *lifo_buf, unsigned int item);
LIFO_status LIFO_pop_item(LIFO_Buf_t *lifo_buf, unsigned int *item);
LIFO_status LIFO_init(LIFO_Buf_t *lifo_buf, unsigned int *buf, unsigned int length);
#endif // LIFO_H_