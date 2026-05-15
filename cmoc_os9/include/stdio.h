#ifndef _STDIO_H
#define _STDIO_H

#include <sys/types.h>

#define BUFSIZ  256
#define _NFILE  16

typedef struct _iobuf {
	char *_ptr;
	char *_base;
	char *_end;
	int _flag;
	int _fd;
	char _save;
	int _bufsiz;
} FILE;

extern FILE _iob[_NFILE];

#define _READ       1
#define _WRITE      2
#define _UNBUF      4
#define _BIGBUF     8
#define _EOF        0x10
#define _ERR        0x20
#define _SCF        0x40
#define _RBF        0x80
#define _DEVMASK    0xc0
#define _WRITTEN    0x0100
#define _INIT       0x8000

#define EOF (-1)
#define EOL 13

#ifndef NULL
#define NULL 0
#endif

#define stdin  _iob
#define stdout (&_iob[1])
#define stderr (&_iob[2])

int getc(FILE *stream);
int putc(int c, FILE *stream);
int putw(int w, FILE *stream);
int puts(char *s);
int fputs(char *s, FILE *stream);

#define fgetc getc
#define putchar(c) putc(c, stdout)
#define getchar() getc(stdin)
#define ferror(p) ((p)->_flag & _ERR)
#define feof(p) ((p)->_flag & _EOF)
#define clearerr(p) ((p)->_flag &= ~_ERR)
#define fileno(p) ((p)->_fd)

int printf(char *fmt, ...);
int fprintf(FILE *fp, char *fmt, ...);
int sprintf(char *str, char *fmt, ...);
char *fgets(char *str, int size, FILE *stream);

FILE *fopen(char *path, char *mode);
int fclose(FILE *fp);
int fflush(FILE *fp);

long fseek(FILE *fp, long pos, int whence);
long ftell(FILE *fp);
void rewind(FILE *fp);

#endif
