#include "libft.h"

static int	check_overflow(long long value, char c)
{
    long long	min_long;
    long long	max_long;

    max_long = ~((unsigned long long)0) >> 1;
    min_long = 1LL << (sizeof(long long) * 8 - 1);
    return (value * 10 < min_long + c - '0'
            || value * 10 > max_long - c + '0'
            || value < min_long / 10 || value > max_long / 10);
}

int			ft_atoi_safe(const char *str, const char **end, int *result)
{
    long long	value;
    size_t		i;
    int			is_negative;

    is_negative = 0;
    i = 0;
    while (ft_strchr(" \t\n\b\f\v\r", str[i]))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            is_negative = 1;
        i++;
    }
    value = 0;
    while (ft_isdigit(str[i]))
    {
        if (check_overflow(value, str[i]))
            return (0);
        value = value * 10 + str[i++] - '0';
    }
    *end = str + i;
    *result = (int)(value * (is_negative ? -1 : 1));
    return (1);
}
