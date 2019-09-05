#include <stdlib.h>

int *ft_range(int min, int max)
{
	int *range, i, n;

	if (min >= max)
		return NULL;

	n = max - min;
	range = (int *) malloc(n * sizeof(int));
	
	i = 0;
	while (i < n)
	{
		range[i] = min + i;
		i++;
	}
	
	return (range);
}
