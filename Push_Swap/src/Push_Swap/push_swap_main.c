#include "push_swap.h"
#include "checker.h"
#include "libft.h"

int main(int argc, char **argv)
{
    int *arr;
    int size;

    if (!checker_parse_arguments(argc, argv, &arr, &size))
    {
        ft_putendl(ERROR_MSG);
        return (1);
    }
    launch_push_swap(arr, size);
    free(arr);
    return (0);
}
