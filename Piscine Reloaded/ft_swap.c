void	ft_swap(int *a, int *b)
{
	int buf;

	if (a && b)
	{
		buf = *a;
		*a = *b;
		*b = buf;
	}
}
