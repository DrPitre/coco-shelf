#include <cmoc.h>

#include "cmoc_os9_io.h"

__norts__ asm int
creat(char *path, int mode)
{
    asm
    {
* stack:
*   0,s = return address
*   2,s = pathname pointer
*   4,s = mode
pmode   equ         FAP_READ|FAP_WRITE|FAP_PREAD

        pshs        u
        ldx         2+2,s
        lda         2+4+1,s
        tfr         a,b
        andb        #FAP_PEXEC|FAP_EXEC
        orb         #pmode
        os9         I$Create
        bcc         crret
        cmpb        #E$CEF
        bne         errout

        lda         2+4+1,s
        bita        #FAP_DIR
        bne         errout

        anda        #7
        ldx         2+2,s
        os9         I$Open
        bcs         errout

        pshs        a,u
        ldx         #0
        leau        ,x
        ldb         #SS_Size
        os9         I$SetStt
        puls        a,u
        bcc         crret

        pshs        b
        os9         I$Close
        puls        b
errout  leas        2,s
_os9err EXTERNAL
        lbra        _os9err

crret   leas        2,s
        tfr         a,b
        clra
    }
}
