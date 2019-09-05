int ft_sqrt(int nb)
{
	int result;

	result = 0;
	while (result * result < nb)
		result++;

	return result * result == nb ? result : 0;
}
