
#include "stdint.h"
#include "platform_types.h"

// registers
#define RCC_BASE 0x40021000
#define PortA_BASE 0x40010800

#define RCC_APB2ENR *(volatile uint32 *)(RCC_BASE + 0x18)
#define GPIOA_CRH *(volatile uint32 *)(PortA_BASE + 0x04)
#define GPIOA_ODR *(volatile uint32 *)(PortA_BASE + 0x0C)
unsigned char g_vars[4] = {5, 0xF, 2};
unsigned char const const_vars[3] = {1, 2, 3};
typedef union
{
    vuint32 all_fields; // 32bits
    struct
    {
        vuint32 reserved : 13;
        vuint32 P_13 : 1;
    } Pin;
} R_ODR_t;

volatile R_ODR_t *R_ODR = (volatile R_ODR_t *)(PortA_BASE + 0x0C);
int uninitialized;
int main(void)
{
    RCC_APB2ENR |= 1 << 2; // set bit 13
    GPIOA_CRH &= 0xFF0FFFFF;
    GPIOA_CRH |= 0x00200000;
    while (1)
    {

        // R_ODR->Pin.P_13 = 1;
        for (int i = 0; i < 5000; i++)
            ; // delay
        // R_ODR->Pin.P_13 = 0;
        GPIOA_ODR ^= (1 << 13);
        for (int i = 0; i < 5000; i++)
            ;
    }
}