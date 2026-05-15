#ifndef _CTYPE_H
#define _CTYPE_H

extern const unsigned char _chcodes[];

#define _CONTROL 0x01
#define _UPPER   0x02
#define _LOWER   0x04
#define _DIGIT   0x08
#define _WHITE   0x10
#define _PUNCT   0x20
#define _HEXDIG  0x40

#define isascii(c)      ((unsigned)(c) <= 0x7f)
#define isalpha(c)      (_chcodes[(unsigned char)(c)] & (_UPPER | _LOWER))
#define isupper(c)      (_chcodes[(unsigned char)(c)] & _UPPER)
#define islower(c)      (_chcodes[(unsigned char)(c)] & _LOWER)
#define isdigit(c)      (_chcodes[(unsigned char)(c)] & _DIGIT)
#define isxdigit(c)     (_chcodes[(unsigned char)(c)] & _HEXDIG)
#define isspace(c)      (_chcodes[(unsigned char)(c)] & _WHITE)
#define ispunct(c)      (_chcodes[(unsigned char)(c)] & _PUNCT)
#define isalnum(c)      (_chcodes[(unsigned char)(c)] & (_UPPER | _LOWER | _DIGIT))
#define isprint(c)      (_chcodes[(unsigned char)(c)] & (_PUNCT | _UPPER | _LOWER | _DIGIT))
#define iscntrl(c)      (_chcodes[(unsigned char)(c)] & _CONTROL)
#define _toupper(c)     ((c) & 0xdf)
#define _tolower(c)     ((c) | 0x20)
#define toascii(c)      ((c) & 0x7f)
#define toupper(c)      (islower(c) ? _toupper(c) : (c))
#define tolower(c)      (isupper(c) ? _tolower(c) : (c))

#endif
