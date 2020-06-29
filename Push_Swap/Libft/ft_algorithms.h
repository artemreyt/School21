#ifndef ALGORITHMS_H
# define ALGORITHMS_H

union Int32
{
    int             x;
    unsigned char   bytes[4];
};


/*
 * works only with arrays
 * on the heap memory segment
 */
void    radix_sort(int *arr, int n);

/*
 * m - max size of chunk to sort by selection sort
 * (optimization)
 * if m == 0, then all chunks will be sorted
 * by quick push_swap_sort algorithm
 */
void    quick_sort(int *arr, int n, int m);

void    selection_sort(int *arr, int n);

#endif
