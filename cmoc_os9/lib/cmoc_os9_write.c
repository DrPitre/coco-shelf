#include <cmoc.h>

#include "cmoc_os9_io.h"

__norts__ asm int
write(int fd, char *buf, int count)
{
    asm
    {
* stack:
*   0,s = return address
*   2,s = fd
*   4,s = buffer pointer
*   6,s = write count
        pshs    y
        ldy     2+6,s
        beq     write10
        lda     2+2+1,s
        ldx     2+4,s

        os9     I$Write

write1  bcc     write10
        puls    y
_os9err EXTERNAL
        lbra    _os9err

write10 tfr     y,d
        puls    y,pc
    }
}
