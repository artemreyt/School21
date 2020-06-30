#include "checker.h"
#include "libft.h"
#include "ft_algorithms.h"
#include <stdlib.h>

static int  check_argument(char *arg, int *number)
{
    int         success;
    const char  *end;

    success = ft_atoi_safe(arg, &end, number);
    if (!success || *end != '\0')
        return (0);
    return (1);
}

static int  check_duplicates(int *arr, int n)
{
    int i;

    radix_sort(arr, n);
    i = 0;
    while (i < n - 1)
    {
        if (arr[i] == arr[i + 1])
            return (0);
        ++i;
    }
    return (1);
}

int         check_valid_arguments(int argc, char **argv)
{
    int i;
    int retv;
    int *args;

    retv = 1;
    args = (int *)malloc((argc - 1) * sizeof(int));
    i = 1;
    while (i < argc)
    {
        if (!check_argument(argv[i], &args[i - 1]))
        {
            retv = 0;
            break;
        }
        ++i;
    }
    if (retv)
        retv = check_duplicates(args, argc - 1);
    free(args);
    return (retv);
}
