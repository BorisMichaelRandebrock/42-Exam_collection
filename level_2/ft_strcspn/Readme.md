Assignment name	: ft_strcspn   
Expected files	: ft_strcspn.c  
Allowed functions: None   
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);

man strcspn:
---------------------------------------------------------------
NAME
     strspn, strcspn – span a string

LIBRARY
     Standard C Library (libc, -lc)

SYNOPSIS
     #include <string.h>

     size_t
     strspn(const char *s, const char *charset);

     size_t
     strcspn(const char *s, const char *charset);

DESCRIPTION
     The strspn() function spans the initial part of the null-terminated string s as
     long as the characters from s occur in the null-terminated string charset.  In
     other words, it computes the string array index of the first character of s
     which is not in charset, else the index of the first null character.

     The strcspn() function spans the initial part of the null-terminated string s as
     long as the characters from s do not occur in the null-terminated string charset
     (it spans the complement of charset).  In other words, it computes the string
     array index of the first character of s which is also in charset, else the index
     of the first null character.

RETURN VALUES
     The strspn() and strcspn() functions return the number of characters spanned.

SEE ALSO
     memchr(3), strchr(3), strpbrk(3), strrchr(3), strsep(3), strstr(3), strtok(3),
     wcsspn(3)

STANDARDS
     The strspn() and strcspn() functions conform to ISO/IEC 9899:1990 (“ISO C90”).
