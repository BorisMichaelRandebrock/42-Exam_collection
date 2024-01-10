#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		put_char(str[i++]);
}
