#include "ft_algorithms.h"

void    selection_sort(int *arr, int n)
{
    int min;
    int i_min;
    int i;
    int j;

    i = 0;
    while (i < n - 1)
    {
        min = arr[i];
        i_min = i;
        j = i + 1;
        while (j < n)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                i_min = j;
            }
            ++j;
        }
        arr[i_min] = arr[i];
        arr[i] = min;
        ++i;
    }
}
