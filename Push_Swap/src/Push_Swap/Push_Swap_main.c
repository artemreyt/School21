#include "Push_Swap.h"
#include "libft.h"

static int     *scan_numbers(int argc, char **argv)
{
    int *arr;
    int i;

    arr = (int *)malloc((argc - 1) * sizeof(*arr));
    if (arr == NULL)
        exit(EXIT_FAILURE);
    i = 1;
    while (i < argc)
    {
        arr[i - 1] = ft_atoi(argv[i]);
        ++i;
    }
    return (arr);
}


int main(int argc, char **argv)
{
    int *arr;

    arr = scan_numbers(argc, argv);
    launch_push_swap(arr, argc - 1);
    return (0);
}
