//  Author      : Mohamed Kamel

#include "fifo.h"
#include <stdio.h>
EL_TYPE fifo_buf[5];

int main(void)
{
    EL_TYPE temp = 0, i;
    FIFO_Buf_t FIFO_UART;
    if (FIFO_init(&FIFO_UART, fifo_buf, 5) == FIFO_no_error)
    {
        printf("fifo_init is done\n");
    }

    for (i = 0; i < 7; i++)
    {
        printf("FIFO Enqueue (%X) \n", i);
        if (FIFO_Enqueue(&FIFO_UART, i) == FIFO_no_error)
        {
            printf("\t fifo_enqueue.... is done\n");
        }
        else
        {
            printf("\t fifo_enqueue.... failed\n");
        }
    }

    FIFO_print(&FIFO_UART);
    printf("\t fifo_dequeue\n");
    if (FIFO_Dequeue(&FIFO_UART, &temp) == FIFO_no_error)
    {
        printf("\t fifo_dequeue %x .... is done\n", temp);
    }
    else
    {
        printf("\t fifo_dequeue.... failed\n");
    }

    if (FIFO_Dequeue(&FIFO_UART, &temp) == FIFO_no_error)
    {
        printf("\t fifo_dequeue %x .... is done\n", temp);
    }
    else
    {
        printf("\t fifo_dequeue.... failed\n");
    }
    printf("\n\t fifo_print:\n");
    FIFO_print(&FIFO_UART);
}
