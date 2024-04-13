#ifndef INT_TYPES_H
#define INT_TYPES_H

// intmax_t
typedef long long int intmax_t;
// uintmax_t
typedef unsigned long long int uintmax_t;

#define PRIdMAX "lld"

intmax_t strtoimax(const char *nptr, char **endptr, int base);
uintmax_t strtoumax(const char *nptr, char **endptr, int base);

#endif // INT_TYPES_H
