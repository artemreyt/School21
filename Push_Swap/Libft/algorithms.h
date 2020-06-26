#ifndef ALGORITHMS_H
# define ALGORITHMS_H

union Int32
{
    int             x;
    unsigned char   bytes[4];
};

void    radix_sort(int *arr, int n);
void    quick_sort(int *arr, int n, int m);
void    selection_sort(int *arr, int n);

#endif
