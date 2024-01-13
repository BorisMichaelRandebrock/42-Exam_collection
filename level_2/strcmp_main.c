#include <stdio.h>
#include <string.h>

int     ft_strcmp(char *s1, char *s2);

int     main(void)
{
	char    *s;
	char    *s1;
	s = "somwhere over the rainbow ";
	s1 = "somwhere ober the rainbow";
	printf("Original strcmp:  %i\n", strcmp(s, s1));
	printf("ft_strcmp output: %i\n", ft_strcmp(s, s1));
	return (0);
}
