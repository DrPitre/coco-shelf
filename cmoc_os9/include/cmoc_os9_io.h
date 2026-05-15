#ifndef CMOC_OS9_IO_H
#define CMOC_OS9_IO_H

typedef int error_code;

#ifndef NULL
#define NULL 0
#endif

/* OS-9 I/O system calls */
#define I$Create 0x83
#define I$Open   0x84
#define I$Seek   0x88
#define I$Read   0x89
#define I$Write  0x8A
#define I$ReadLn 0x8B
#define I$WritLn 0x8C
#define I$SetStt 0x8E
#define I$Close  0x8F

/* OS-9 errors and getstat/setstat codes used by the imported helpers */
#define E$EOF    0xD3
#define E$CEF    0xDA
#define SS_Size  0x02

/* CoCo/OS-9 file access modes */
#define FAM_READ  0x01
#define FAM_WRITE 0x02

/* OS-9 file permissions */
#define FAP_READ  0x01
#define FAP_WRITE 0x02
#define FAP_EXEC  0x04
#define FAP_PREAD 0x08
#define FAP_PEXEC 0x20
#define FAP_DIR   0x80

int open(char *path, int mode);
int close(int fd);
int creat(char *path, int mode);
int readln(int fd, char *buf, int count);
int write(int fd, char *buf, int count);

#endif
