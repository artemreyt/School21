#include "algorithms.h"
#include <stdlib.h>

static void swap(int *a, int *b)
{
    int buf = *a;
    *a = *b;
    *b = buf;
}

static void partition(int *arr, int *left, int *right)
{
    int pivot;

    pivot = *(arr + (*right + 1) / 2);
    while (left <= right)
    {
        while (arr[*left] < pivot)
            (*left)++;
        while (arr[*right] > pivot)
            (*right)--;
        if (*left <= *right)
        {
            swap(arr + *left, arr + *right);
            (*left)++;
            (*right)--;
        }
    }
}

void    quick_sort(int *arr, int n, int m)
{
    int left;
    int right;

    if (n < m)
        selection_sort(arr, n);
    else
    {
        left = 0;
        right = n - 1;
        partition(arr, &left, &right);
        quick_sort(arr, right + 1, m);
        quick_sort(arr + left, n - left, m);
    }
}