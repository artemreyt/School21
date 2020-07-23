#include "ft_algorithms.h"
#include "libft.h"
#include <stdlib.h>

static void         count_bytes(union Int32 *arr, int n, int byte, int *count)
{
    int i;
    int j;

    i = 0;
    while (i < n)
    {
        if (byte != 3)
            count[arr[i].bytes[byte]]++;
        else
            count[arr[i].bytes[byte] ^ 128]++;
        ++i;
    }
    i = 255;
    while (i >= 0)
    {
        count[i] = 0;
        j = 0;
        while (j < i)
        {
            count[i] += count[j];
            ++j;
        }
        --i;
    }
}

static union Int32  *count_sort(union Int32 *arr, int n, int byte)
{
    int         i;
    int         j;
    int         count[256];
    union Int32 *dest;

    ft_bzero(count, sizeof(*count) * 256);
    dest = (union Int32 *) malloc(n * sizeof(union Int32));
    count_bytes(arr, n, byte, count);
    i = 0;
    while (i < n)
    {
        if (byte < 3)
            j = count[arr[i].bytes[byte]]++;
        else
            j = count[arr[i].bytes[byte] ^ 128]++;
        dest[j] = arr[i];
        ++i;
    }
    free(arr);
    return (dest);
}

void                radix_sort(int *arr, int n)
{
    int byte;
    int *arr_copy;

    arr_copy = (int *)malloc(n * sizeof(*arr));
    ft_memcpy(arr_copy, arr, n * sizeof(*arr));
    byte = 0;
    while (byte < 4)
        arr_copy = (int *)count_sort((union Int32 *)arr_copy, n, byte++);
    ft_memcpy(arr, arr_copy, n * sizeof(*arr));
    free(arr_copy);
}