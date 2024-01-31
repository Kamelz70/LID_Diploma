#include "FIFO.h"
#include <stdbool.h>

FIFO_buf_status FIFO_init(FIFO_Buf_t *fifo, EL_TYPE *buf, uint32_t length)
{
    // check on invalid input
    if (!fifo || !buf || length < 1)
    {
        return FIFO_null;
    }
    fifo->length = length;
    fifo->count = 0;
    fifo->base = buf;
    fifo->head = buf;
    fifo->tail = buf;
    return FIFO_no_error;
}
FIFO_buf_status FIFO_Enqueue(FIFO_Buf_t *fifo, EL_TYPE item)
{
    // on invalid fifo
    if (!FIFO_isValid(fifo))
    {
        return FIFO_null;
    }
    // check if full
    if (FIFO_isFull(fifo))
    {
        return FIFO_full;
    }
    // on add element head moves
    // potential error
    *(fifo->head) = item;
    fifo->count++;
    fifo->head++;
    // if head is out of bounds reset to base
    if (fifo->head == ((fifo->base) + fifo->length))
    {
        fifo->head = fifo->base;
    }

    return FIFO_no_error;
}
FIFO_buf_status FIFO_Dequeue(FIFO_Buf_t *fifo, EL_TYPE *item)
{
    // on invalid fifo
    if (!FIFO_isValid(fifo))
    {
        return FIFO_null;
    }
    // on fifo empty
    if (FIFO_isEmpty(fifo))
    {
        return FIFO_empty;
    }
    // on remove element tail moves
    // potential error
    *item = *(fifo->tail);
    fifo->count--;
    fifo->tail++;
    // if tail is out of bounds reset to base
    if (fifo->tail == ((fifo->base) + fifo->length))
    {
        fifo->tail = fifo->base;
    }
    return FIFO_no_error;
}
void FIFO_print(FIFO_Buf_t *fifo)
{
    // on invalid fifo
    if (!FIFO_isValid(fifo))
    {
        return FIFO_null;
    }
    // on fifo empty
    if (FIFO_isEmpty(fifo))
    {
        return FIFO_empty;
    }
    EL_TYPE *temp = fifo->tail;
    for (int i = 0; i < fifo->count; i++)
    {
        if (temp == ((fifo->base) + fifo->length))
        {
            temp = fifo->base;
        }
        printf("\t %d\n", *temp);
        temp++;
    }
    return FIFO_no_error;
}
// helper functions
bool FIFO_isValid(FIFO_Buf_t *fifo)
{

    return fifo && fifo->base && fifo->tail && fifo->head;
}
bool FIFO_isEmpty(FIFO_Buf_t *fifo)
{
    return fifo->count == 0;
}
bool FIFO_isFull(FIFO_Buf_t *fifo)
{
    return fifo->count == fifo->length;
}
