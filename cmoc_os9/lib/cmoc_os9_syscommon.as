        section code

_oserr  EXPORT
_oserr
        clra
_errno  EXTERNAL
        std     _errno,y
        rts

_osret  EXPORT
_osret
        bcs     _oserr
        clra
        clrb
        rts

_os9err EXPORT
_os9err
        clra
        std     _errno,y
        ldd     #-1
        rts

_sysret EXPORT
_sysret
        bcs     _os9err
        clra
        clrb
        rts

        endsect
