#include <cmoc.h>

#include "cmoc_os9_io.h"

__norts__ asm int
readln(int fd, char *buf, int count)
{
    asm
    {
* stack:
*   0,s = return address
*   2,s = fd
*   4,s = buffer pointer
*   6,s = read count
        pshs    y
        ldx     2+4,s
        lda     2+2+1,s
        ldy     2+6,s
        pshs    y
        os9     I$ReadLn

read1   bcc     rdexit
        cmpb    #E$EOF
        bne     read10
        clra
        clrb
        puls    x,y,pc

read10  puls    x,y
_os9err EXTERNAL
        lbra    _os9err

rdexit  tfr     y,d
        puls    x,y,pc
    }
}
