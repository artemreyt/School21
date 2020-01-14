/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artemstarshov <artemstarshov@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:33:46 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/01/13 19:30:00 by artemstarsh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "libft.h"
#include <math.h>

# define FRACTION_BITS		113
# define EXPONENT_BITS		15
# define EXPONENT_NUMBER	16383

struct			s_double_repr
{
	unsigned long	fraction: FRACTION_BITS;
	unsigned int	exponent: EXPONENT_BITS;
	unsigned		sign: 1;
};
typedef struct s_double_repr	t_double_repr;

static char	*get_int_part(unsigned long fraction, unsigned first_bit, unsigned exponent)
{
	unsigned long	long	number;
	char			*str;

	puts("IN GET_INT_PART");
	if (exponent > 0)
	{
		puts("HERE1");
		number = fraction >> (first_bit - exponent + 1);
		printf("%lu\n", number);
		str = ft_unsigned_itoa(number);
	}
	else
	{
		puts("HERE2");
		str = (char *)ft_memalloc(2);
		if (!str)
			return (NULL);
		str[0] = '0';
	}
	return (str);
}

static char	*get_frac_part(unsigned long fraction, int first_bit, int exponent, int precision)
{
	return (0);
}

static int	find_parts(double num, char *int_part, char *fract_part, int precision)
{
	t_double_repr	*repr;
	unsigned long	fraction;
	unsigned		first_bit;

	repr = (t_double_repr *)&num;
	fraction = repr->fraction;
	fraction |= 1L << FRACTION_BITS;
	first_bit = 0;
	while (!(fraction & 1LU))
	{
		fraction >>= 1;
		first_bit++;
	}
	first_bit = FRACTION_BITS - first_bit;
	int_part = get_int_part(fraction, first_bit, repr->exponent - EXPONENT_NUMBER + 1);
	fract_part = get_frac_part(fraction, first_bit, repr->exponent - EXPONENT_NUMBER + 1, precision);
	return (1); // (int_part && fract_part ? 1 : 0);
}

char		*dtoa(double num, int precision)
{
	char	*int_part;
	char	*fract_part;
	char	*result;

	result = NULL;
	if (find_parts(num, int_part, fract_part, precision))
	{
		result = int_part;//combine_parts(int_part, fract_part);
		// free(int_part);
		// free(fract_part);
	}
	return (result);
}

void	print_double(double num)
{
	double	buf;
	int		digit;
	
	while (num > 1.0)
	{
		buf = num / 10;
	}
}


int main()
{
	// double num;
	// scanf("%lf", &num);
	// t_double_repr *repr = (t_double_repr *) &num;
	// printf("fraction: %ld\nexponent: %d\nsign: %u\n",
	// 		repr->fraction, repr->exponent, repr->sign);
	// printf("%lf\n", num);
	// char res[500];
	// puts(ftoa(num, 6));

	printf("%zu %zu\n", sizeof(double), sizeof(long double));
	
	return (0);
}
