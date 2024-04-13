#ifndef SYS_WAIT_H
#define SYS_WAIT_H

#define WNOHANG 1
#define WUNTRACED 2

#include <sys/types.h>
#include <sys/time.h>

// WEXITSTATUS
#define WEXITSTATUS(status) ((status) & 0xFF)

// WIFEXITED
#define WIFEXITED(status) (1)

// WSTOPSIG
#define WSTOPSIG(status) (1)

// WIFSTOPPED
#define WIFSTOPPED(status) (1)

// WTERMSIG
#define WTERMSIG(status) (1)

pid_t wait3(int *status, int options, struct rusage *rusage);

#endif // SYS_WAIT_H
