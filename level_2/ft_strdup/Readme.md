Assignment name  : ft_strdup   
Expected files   : ft_strdup.c   
Allowed functions: malloc  
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);

man strdup:
---------------------------
NAME
     strdup, strndup – save a copy of a string

LIBRARY
     Standard C Library (libc, -lc)

SYNOPSIS
     #include <string.h>

     char *
     strdup(const char *s1);

     char *
     strndup(const char *s1, size_t n);

DESCRIPTION
     The strdup() function allocates sufficient memory for a copy of the string s1,
     does the copy, and returns a pointer to it.  The pointer may subsequently be
     used as an argument to the function free(3).

     If insufficient memory is available, NULL is returned and errno is set to
     ENOMEM.

     The strndup() function copies at most n characters from the string s1 always NUL
     terminating the copied string.

SEE ALSO
     free(3), malloc(3)

HISTORY
     The strdup() function first appeared in 4.4BSD.  The strndup() function was
     added in FreeBSD 7.2.
