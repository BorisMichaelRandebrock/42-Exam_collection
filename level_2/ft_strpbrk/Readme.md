Assignment name	: ft_strpbrk   
Expected files	: ft_strpbrk.c   
Allowed functions: None  
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);

man strpbrk:
----------
NAME
     strpbrk – locate multiple characters in string

LIBRARY
     Standard C Library (libc, -lc)

SYNOPSIS
     #include <string.h>

     char *
     strpbrk(const char *s, const char *charset);

DESCRIPTION
     The strpbrk() function locates in the null-terminated string s the first
     occurrence of any character in the string charset and returns a pointer to this
     character.  If no characters from charset occur anywhere in s strpbrk() returns
     NULL.

SEE ALSO
     memchr(3), strchr(3), strcspn(3), strrchr(3), strsep(3), strspn(3), strstr(3),
     strtok(3), wcspbrk(3)

STANDARDS
     The strpbrk() function conforms to ISO/IEC 9899:1990 (“ISO C90”).
