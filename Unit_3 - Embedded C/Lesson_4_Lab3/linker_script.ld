MEMORY
{
    flash (rx) : ORIGIN = 0X00000000, LENGTH = 512M  
    sram (rwx) : ORIGIN = 0x20000000, LENGTH = 512M
}   

SECTIONS
{
    .text :
    {
        *(.vectors*)
        *(.text*)
        *(.rodata)
        _E_text = . ;
    }> flash
    .data :
    {
        _S_DATA = . ;
        *(.data)
        _E_DATA = . ;
    }>sram AT> flash
    .bss :
    {
        _S_bss = . ;
        *(.bss*)
        . = ALIGN(4);
        _E_bss = . ;
        . = . + 0x1000;
    }> sram
}