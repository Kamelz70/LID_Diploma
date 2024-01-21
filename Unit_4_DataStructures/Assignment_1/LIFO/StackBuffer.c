#include <stdio.h>
#include "LIFO.h"
#include "stdlib.h"
unsigned int lifo_buf[5];
int main()
{
    // setvbuf(stdout, NULL, _IONBF, 0);
    // setvbuf(stderr, NULL, _IONBF, 0);
    unsigned int i, temp = 0;
    LIFO_Buf_t uart_lifo, I2C_lifo;
    unsigned int *buffer2 = malloc(5 * sizeof(int));
    LIFO_init(&uart_lifo, lifo_buf, 5);

    for (i = 0; i < 5; i++)
    {
        if (LIFO_Add_item(&uart_lifo, i) == LIFO_no_error)
        {

            printf("UART LIFO add : %d\n", i);
        }
    }

    for (i = 0; i < 5; i++)
    {
        int state = 0;
        if ((state = LIFO_pop_item(&uart_lifo, &temp)) == LIFO_no_error)
        {

            printf("UART LIFO get : %d\n", temp);
        }
    }

    return 0;
}
