#include "libft.h"
#include <string.h>

# define BOUND_WIDTH 30

void	print_bound()
{
	int i;

	i = 0;
	while (i++ < BOUND_WIDTH)
		ft_putchar('-');
	ft_putchar('\n');
}

void	compare_results(const char *func_name, const char *std_answer, const char *ft_answer)
{
	print_bound();
	ft_putstr("Comparing ");
	ft_putstr(func_name);
	ft_putstr(" vs ft_");
	ft_putstr(func_name);
	ft_putstr(": ");
	if (ft_strequ(std_answer, ft_answer))
		ft_putstr("OK :D\n");
	else
	{
		ft_putchar('\n');
		ft_putstr(std_answer);
		ft_putchar('\n');
		ft_putstr(ft_answer);
		ft_putstr("\nKO :(\n");
	}
	print_bound();
}

int main() 
{
	// if (ft_strequ("12", "123"))
	// 	ft_putstr("OK\n");
	// else
	// 	ft_putstr("KO\n");

	/* ft_strlen */
	print_bound();
	ft_putstr("strlen(\"ABhsbjuyguvsyt\") = ");
	ft_putnbr(strlen("ABhsbjuyguvsyt"));
	ft_putstr(", ft_strlen(\"ABhsbjuyguvsyt\") = ");
	ft_putnbr(ft_strlen("ABhsbjuyguvsyt"));
	ft_putstr("\nft_strlen of empty string = ");
	ft_putnbr(ft_strlen(""));
	ft_putchar('\n');
	print_bound();
	/* ft_strlen */

	/* ft_strcpy */
	char dst_std[20];
	char dst_ft[20];
	compare_results("strcpy()", strcpy(dst_std, "Hello"), ft_strcpy(dst_ft, "Hello"));
	compare_results("strncpy()", strncpy(dst_std, "Goodbye", 3), ft_strncpy(dst_ft, "Goodbye", 3));
	compare_results("strncpy()", strncpy(dst_std, "Hello world!", 6), ft_strncpy(dst_ft, "Hello, world!", 6));
/*
	ft_putstr(dst_std);
	ft_putchar(' ');
	ft_putstr(dst_ft);
*/
	/* ft_strcpy */



	return (0);
}