void	ft_putstr(char *str);
void	put_char(char c);

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_putstr(argv[1]);
	put_char('\n');
	return (0);
}
