#include "uart.h"
unsigned char string_buffer[100] = "learn-in-depth";
int main(void)
{
    const int a = 5;
    Uart_send_string(string_buffer);
    return 0;
}