int ft_iterative_factorial(int nb)
{
	if (nb < 0 || nb >= 13)
		return 0;

	int result;

	result = 1;
	while (nb > 0)
		result *= nb--;

	return result;
}
