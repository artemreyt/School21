#include <stdlib.h>
#include <sys/errno.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;

	return (i);
}

char *ft_strcpy(char *dst, const char *src)
{	
	int i;

	i = 0;	
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}

	return (dst);	
}

char *ft_strdup(char *src)
{
	char *res;

	res = (char *) malloc(sizeof(char) * ft_strlen(src));
	if (!res)
	{
		errno = ENOMEM;
		return NULL;
	}

	ft_strcpy(res, src);
	return (res);
}
