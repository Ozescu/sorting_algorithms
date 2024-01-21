#include "sort.h"

void custom_swap_ints(int *a, int *b);
int custom_lomuto_partition(int *array, size_t size, int left, int right);
void custom_lomuto_sort(int *array, size_t size, int left, int right);
void custom_quick_sort(int *array, size_t size);

/**
 * custom_swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void custom_swap_ints(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * custom_lomuto_partition - Order a subset of an array of integers according to
 *                           the Lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int custom_lomuto_partition(int *array, size_t size, int left, int right)
{
    int *pivot, above, below;

    pivot = array + right;
    for (above = below = left; below < right; below++)
    {
        if (array[below] < *pivot)
        {
            if (above < below)
            {
                custom_swap_ints(array + below, array + above);
                print_array(array, size);
            }
            above++;
        }
    }

    if (array[above] > *pivot)
    {
        custom_swap_ints(array + above, pivot);
        print_array(array, size);
    }

    return (above);
}

/**
 * custom_lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void custom_lomuto_sort(int *array, size_t size, int left, int right)
{
    int part;

    if (right - left > 0)
    {
        part = custom_lomuto_partition(array, size, left, right);
        custom_lomuto_sort(array, size, left, part - 1);
        custom_lomuto_sort(array, size, part + 1, right);
    }
}

/**
 * custom_quick_sort - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void custom_quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    custom_lomuto_sort(array, size, 0, size - 1);
}
