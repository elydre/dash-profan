#ifndef SYS_RESOURCE_H
#define SYS_RESOURCE_H

#include <sys/time.h>

// rlim_t
typedef unsigned long rlim_t;

#define RLIM_INFINITY ((rlim_t)-1)

// rlimit
struct rlimit {
    rlim_t rlim_cur;
    rlim_t rlim_max;
};

int getrlimit(int resource, struct rlimit *rlim);
int setrlimit(int resource, const struct rlimit *rlim);

#endif
