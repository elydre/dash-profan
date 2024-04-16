#ifndef	_ALLOCA_H
#define	_ALLOCA_H	1

#include <stddef.h>

/* Remove any previous definition.  */
#undef	alloca

/* Allocate a block that will be freed when the calling function exits.  */
extern void *alloca (size_t __size);

#ifdef	__GNUC__
# define alloca(size)	__builtin_alloca (size)
#endif /* GCC.  */

#endif /* alloca.h */
