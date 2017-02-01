#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/times.h>
#include <sys/time.h>
#include <time.h>

/************************************************************************
* This file contains placeholder routines in order to allow a correct
* linking of the binaries; note that these routines will actually never
* be called since their behavior will be emulated using hardware OS emulation
*************************************************************************/

int _chmod(const char *path, mode_t mode){
    _exit(-1);
    return -1;
}

int _chown(const char *path, uid_t owner, gid_t group){
    _exit(-1);
    return -1;
}

int _close(int fd){
    _exit(-1);
    return -1;
}

int _dup(int oldfd){
    _exit(-1);
    return -1;
}

int _dup2(int oldfd, int newfd){
    _exit(-1);
    return -1;
}

void _exit(int exitVal){
    _exit(exitVal);
}

int _fstat(const char *path, struct stat *buf){
    _exit(-1);
    return -1;
}

pid_t _getpid(void){
    _exit(-1);
    return -1;
}

int _isatty(int desc){
    _exit(-1);
    return 0;
}

int _kill(pid_t pid, int sig){
    _exit(-1);
    return -1;
}

off_t _lseek(int fd, off_t offset, int whence){
    _exit(-1);
    return -1;
}

int _lstat(const char *path, struct stat *buf){
    _exit(-1);
    return -1;
}

int _open(const char *pathname, int flags){
    _exit(-1);
    return -1;
}

ssize_t _read(int fd, void *buf, size_t count){
    _exit(-1);
    return -1;
}

void* _sbrk(intptr_t increment){
    _exit(-1);
    return NULL;
}

int _stat(const char *path, struct stat *buf){
    _exit(-1);
    return -1;
}

long _sysconf(int name){
    _exit(-1);
    return -1;
}

int _usleep(useconds_t usec){
    _exit(-1);
    return -1;
}

int _utimes(const char *filename, const struct timeval times[2]){
    _exit(-1);
    return -1;
}

ssize_t _write(int fd, const void *buf, size_t count){
    _exit(-1);
    return -1;
}
