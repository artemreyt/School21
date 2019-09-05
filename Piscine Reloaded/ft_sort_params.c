void ft_putchar(char c);

void ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*(str++));
}

int ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

char **ft_sort_params(char **lst, int n)
{
	int i;
	char *buf;

	while (n > 1)
	{
		i = 0;
		while (i < n - 1)
		{
			if (ft_strcmp(lst[i], lst[i + 1]) > 0)
			{
				buf = lst[i];
				lst[i] = lst[i + 1];
				lst[i + 1] = buf;
			}

			i++;
		}

		n--;
	}

	return lst;
}

int main(int argc, char **argv)
{
	int i;
	char **params;

	i = 0;
	params = ft_sort_params(argv + 1, argc - 1);
	while (i < argc - 1)
	{
		ft_putstr(params[i++]);
		ft_putchar('\n');
	}

	return (0);
}