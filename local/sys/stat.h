#ifndef STAT_H
#define STAT_H

#include <sys/types.h>

#define S_ISREG(m)  (((m) & 0170000) == 0100000)
#define S_ISDIR(m)  (((m) & 0170000) == 0040000)

#define S_IFREG 0100000
#define S_IFDIR 0040000
#define S_IFLNK 0120000

struct stat {
    dev_t     st_dev;      /* Périphérique                    */
    ino_t     st_ino;      /* Numéro i-nœud                   */
    mode_t    st_mode;     /* Protection                      */
    nlink_t   st_nlink;    /* Nb liens matériels              */
    uid_t     st_uid;      /* UID propriétaire                */
    gid_t     st_gid;      /* GID propriétaire                */
    dev_t     st_rdev;     /* Type périphérique               */
    off_t     st_size;     /* Taille totale en octets         */
    blksize_t st_blksize;  /* Taille de bloc pour E/S         */
    blkcnt_t  st_blocks;   /* Nombre de blocs de 512B alloués */
    time_t    st_atime;    /* Heure dernier accès             */
    time_t    st_mtime;    /* Heure dernière modification     */
    time_t    st_ctime;    /* Heure dernier changement état   */
};

struct stat64 {
    dev_t     st_dev;      /* Périphérique                    */
    ino64_t   st_ino;      /* Numéro i-nœud                   */
    mode_t    st_mode;     /* Protection                      */
    nlink_t   st_nlink;    /* Nb liens matériels              */
    uid_t     st_uid;      /* UID propriétaire                */
    gid_t     st_gid;      /* GID propriétaire                */
    dev_t     st_rdev;     /* Type périphérique               */
    off64_t   st_size;     /* Taille totale en octets         */
    blksize_t st_blksize;  /* Taille de bloc pour E/S         */
    blkcnt64_t  st_blocks; /* Nombre de blocs de 512B alloués */
    time_t    st_atime;    /* Heure dernier accès             */
    time_t    st_mtime;    /* Heure dernière modification     */
    time_t    st_ctime;    /* Heure dernier changement état   */
};

int stat(const char *path, struct stat *buf);
int fstat(int fd, struct stat *buf);
int lstat(const char *path, struct stat *buf);

int stat64(const char *path, struct stat64 *buf);
int fstat64(int fd, struct stat64 *buf);
int lstat64(const char *path, struct stat64 *buf);

mode_t umask(mode_t mask);

#endif
