ENTRY(reset)
MEMORY
{
    Mem (rwx) : ORIGIN = 0X00000000, LENGTH = 64M   
}

SECTIONS
{
    . = 0x10000;
    .startup . :
    {
        startup.o(.text)
    }> Mem
    .text :
    {
        *(.text) *(.rodata)
    }> Mem
    .data : 
    {
        *(.data)
    }
    .bss :
    {
        *(.bss)
    }> Mem
    .others : 
    {

        *(COMMON)
    }> Mem
    . = . + 0x1000;
    top_of_stack = .;
}