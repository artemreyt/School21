void ft_putchar(char c);

void ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++));
}

int main(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i++]);
		ft_putchar('\n');
	}

	return (0);
}
