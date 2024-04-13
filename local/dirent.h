#ifndef DIRENT_H
#define DIRENT_H

typedef struct {
    int fd;
    char *path;
} DIR;

// dirent64
struct dirent64 {
    unsigned long d_ino;
    unsigned long d_off;
    unsigned short d_reclen;
    char d_name[256];
};

DIR *opendir(const char *name);
struct dirent64 *readdir64(DIR *dirp);
int closedir(DIR *dirp);

#endif // DIRENT_H
