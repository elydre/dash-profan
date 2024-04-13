#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <inttypes.h>
#include <dirent.h>
#include <fcntl.h>
#include <pwd.h>

#include <profan/filesys.h>
#include <profan/syscall.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

int fcntl(int fd, int cmd, int arg) {
    serial_debug("OK fcntl(fd=%d, cmd=%d, arg=%d)\n", fd, cmd, arg);
    if (cmd == F_DUPFD) {
        
        int new_fd = fm_dup(fd);
        if (new_fd == -1) {
            serial_debug("dup(%d) failed\n", fd);
            return -1;
        }

        if (new_fd != arg) {
            if (fm_dup2(new_fd, arg) == -1) {
                serial_debug("dup2(%d, %d) failed\n", new_fd, arg);
                fm_close(new_fd);
                return -1;
            }
            fm_close(new_fd);
        }

        return arg;
    } else if (cmd == F_SETFD) {
        return 0;
    } else {
        serial_debug("Unknown fcntl cmd %d\n", cmd);
        return -1;
    }
}            


/*
struct stat64 {
    dev_t     st_dev;      // Périphérique
    ino64_t   st_ino;      // Numéro i-nœud
    mode_t    st_mode;     // Protection
    nlink_t   st_nlink;    // Nb liens matériels
    uid_t     st_uid;      // UID propriétaire
    gid_t     st_gid;      // GID propriétaire
    dev_t     st_rdev;     // Type périphérique
    off64_t   st_size;     // Taille totale en octets
    blksize_t st_blksize;  // Taille de bloc pour E/S
    blkcnt64_t  st_blocks; // Nombre de blocs de 512B alloué
    time_t    st_atime;    // Heure dernier accès
    time_t    st_mtime;    // Heure dernière modification
    time_t    st_ctime;    // Heure dernier changement état
};
*/

int stat64(const char *path, struct stat64 *buf) {
    serial_debug("OK stat64(%s)\n", path);

    buf->st_dev = 0;
    buf->st_ino = 0;
    buf->st_mode = 0;
    buf->st_nlink = 0;
    buf->st_uid = 0;
    buf->st_gid = 0;
    buf->st_rdev = 0;
    buf->st_size = 0;
    buf->st_blksize = 0;
    buf->st_blocks = 0;
    buf->st_atime = 0;
    buf->st_mtime = 0;
    buf->st_ctime = 0;

    char *pwd = getenv("PWD");
    if (pwd == NULL) pwd = "/";
    char *full_path = assemble_path(pwd, (char *) path);

    sid_t sid = fu_path_to_sid(ROOT_SID, full_path);
    free(full_path);

    if (IS_NULL_SID(sid)) {
        errno = ENOENT;
        return -1;
    }

    buf->st_dev = sid.device;
    
    if (fu_is_file(sid)) {
        buf->st_mode = S_IFREG;
    } else if (fu_is_dir(sid)) {
        buf->st_mode = S_IFDIR;
    } else {
        buf->st_mode = S_IFLNK;
    }
    buf->st_mode |= 00777;

    buf->st_size = c_fs_cnt_get_size(c_fs_get_main(), sid);
    buf->st_blksize = 512;
    buf->st_blocks = (buf->st_size + 511) / 512;

    return 0;    
}

intmax_t strtoimax(const char *nptr, char **endptr, int base) {
    return (intmax_t) strtol(nptr, endptr, base);
}

pid_t wait3(int *status, int options, struct rusage *rusage) {
    printf("wait3(%d)\n", options);
    return 0;
}

mode_t umask(mode_t mask) {
    printf("umask(%d)\n", mask);
    return 0;
}

int getrlimit(int resource, struct rlimit *rlim) {
    printf("getrlimit(%d)\n", resource);
    return 0;
}

DIR *opendir(const char *name) {
    printf("opendir(%s)\n", name);
    return NULL;
}

struct passwd *getpwnam(const char *name) {
    printf("getpwnam(%s)\n", name);
    return NULL;
}

int fstat64(int fd, struct stat64 *buf) {
    printf("fstat64(%d)\n", fd);
    return 0;
}

int setrlimit(int resource, const struct rlimit *rlim) {
    printf("setrlimit(%d)\n", resource);
    return 0;
}

struct dirent64 *readdir64(DIR *dirp) {
    printf("readdir64(%p)\n", dirp);
    return NULL;
}

int closedir(DIR *dirp) {
    printf("closedir(%p)\n", dirp);
    return 0;
}

int lstat64(const char *path, struct stat64 *buf) {
    printf("lstat64(%s)\n", path);
    return 0;
}

uintmax_t strtoumax(const char *nptr, char **endptr, int base) {
    printf("strtoumax(%s, %d)\n", nptr, base);
    return 0;
}
