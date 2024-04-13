#ifndef FCNTL_H
#define FCNTL_H

#define O_EXCL 0x8000
#define O_NONBLOCK 0x4000
#include <profan.h>

#define F_DUPFD 0
#define F_SETFD 1
#define F_GETFD 2
#define F_GETFL 3
#define F_SETFL 4

#define FD_CLOEXEC 1

int fcntl(int fd, int cmd, int arg);

#endif // FCNTL_H
