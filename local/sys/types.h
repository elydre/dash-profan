#ifndef SYS_TYPES_H
#define SYS_TYPES_H

#include <profan/type.h>

#define PATH_MAX 4096
#define NAME_MAX 255

#define open64(path, flags, ...) profan_open((char *) (path), (flags), ##__VA_ARGS__)

// ino_t
typedef unsigned long ino_t;
// mode_t
typedef unsigned int mode_t;
// nlink_t
typedef unsigned int nlink_t;
// uid_t
typedef unsigned int uid_t;
// gid_t
typedef unsigned int gid_t;
// dev_t
typedef unsigned int dev_t;
// blksize_t
typedef long blksize_t;
// blkcnt_t
typedef long blkcnt_t;

// ino64_t
typedef unsigned long ino64_t;
// off64_t
typedef long off64_t;
// blkcnt64_t
typedef long blkcnt64_t;

#endif // SYS_TYPES_H
