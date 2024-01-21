// By Mohamed Kamel
#include <stdint.h>
#define STACK_START 0x20001000

extern void main(void);

void Reset_Handler(void);

void Default_Handler()
{
    Reset_Handler();
}

void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
;
void H_fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
;
// saved in .bss
int stack[256];
// void *(g_p_f_vectors[])() __attribute__((section(".vectors"))) = {
//     (void (*)())((unsigned long)stack + sizeof(stack)),
//     &Reset_Handler,
//     &NMI_Handler,
//     &H_fault_Handler,

// };
unsigned int(g_p_f_vectors[]) __attribute__((section(".vectors"))) = {
    (void (*)())((unsigned long)stack + sizeof(stack)),
    &Reset_Handler,
    &NMI_Handler,
    &H_fault_Handler,

};
// not actual variables, only symbols, to access add & before
extern unsigned char _E_text;
extern unsigned char _S_DATA;
extern unsigned char _E_DATA;
extern unsigned char _S_bss;
extern unsigned char _E_bss;
void Reset_Handler(void)
{
    // copy data from ROM to RAM
    unsigned int DATA_size = (unsigned char *)&_E_DATA - (unsigned char *)&_S_DATA;
    unsigned char *P_src = (unsigned char *)&_E_text;
    unsigned char *P_dst = (unsigned char *)&_S_DATA;

    for (int i = 0; i < DATA_size; i++)
    {
        *((unsigned char *)P_dst++) = *((unsigned char *)P_src++);
    }

    // init bss with zeros
    unsigned int bss_size = (unsigned char *)&_E_bss - (unsigned char *)&_S_bss;
    P_dst = (unsigned char *)&_S_bss;
    for (int i = 0; i < bss_size; i++)
    {
        *((unsigned char *)P_dst++) = (unsigned char)0;
    }
    // jump to main
    main();
}