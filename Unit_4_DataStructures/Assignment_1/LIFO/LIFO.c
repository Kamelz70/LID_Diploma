#include "LIFO.h"
#include <stdbool.h>

bool LIFO_isValid(LIFO_Buf_t *lifo_buf)
{
    if (!lifo_buf || !lifo_buf->head || !lifo_buf->base)
    {
        return false;
    }
    else
        return true;
}
bool LIFO_isFull(LIFO_Buf_t *lifo_buf)
{
    // check if lifo is full
    if (lifo_buf->count == lifo_buf->length)
    {
        return true;
    }
    else
        return false;
}
bool LIFO_isEmpty(LIFO_Buf_t *lifo_buf)
{
    // check if lifo is full
    if (lifo_buf->head == lifo_buf->base)
    {
        return true;
    }
    else
        return false;
}
LIFO_status LIFO_Add_item(LIFO_Buf_t *lifo_buf, unsigned int item)
{
    // check if LIFO isn't valid
    if (!LIFO_isValid(lifo_buf))
    {
        return LIFO_null;
    }
    // check if lifo is full
    if (LIFO_isFull(lifo_buf))
    {
        return LIFO_full;
    }
    // add is possible
    *(lifo_buf->head) = item;
    (lifo_buf->head)++;
    (lifo_buf->count)++;
    // success
    return LIFO_no_error;
}
LIFO_status LIFO_pop_item(LIFO_Buf_t *lifo_buf, unsigned int *item)
{
    // check if LIFO isn't valid
    if (!LIFO_isValid(lifo_buf))
    {
        return LIFO_null;
    }

    // check if lifo is empty
    if (LIFO_isEmpty(lifo_buf))
    {
        return LIFO_empty;
    }
    // pop is possible
    (lifo_buf->head)--;
    *item = *(lifo_buf->head);
    (lifo_buf->count)--;
    // success
    return LIFO_no_error;
}
LIFO_status LIFO_init(LIFO_Buf_t *lifo_buf, unsigned int *buf, unsigned int length)
{
    // check buf structure if null
    if (!lifo_buf)
    {
        return LIFO_null;
    }
    // initialize all structur values
    lifo_buf->length = length;
    lifo_buf->count = 0;
    lifo_buf->base = buf;
    lifo_buf->head = buf;
    // success
    return LIFO_no_error;
}
