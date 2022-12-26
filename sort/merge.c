#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int left_length = m - l + 1;
    int right_length = r - m;

    int left_arr[left_length];
    int right_arr[right_length];

    for (int i = 0; i < left_length; i++)
        left_arr[i] = arr[l + i];

    for (int i = 0; i < right_length; i++)
        right_arr[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < left_length && j < right_length)
    {
        if (left_arr[i] <= right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
        }
        else
        {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    while (i < left_length)
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < right_length)
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        merge_sort(arr, m + 1, r);
        merge_sort(arr, l, m);

        merge(arr, l, m, r);
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {4, 3, 6, 1, 0, -9, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, 0, n - 1);
    print(arr, n);

    return 0;
}

// The Merge Sort algorithm is a sorting algorithm that is based
// on the Divide and Conquer paradigm.
// Time Complexity: O(N log(N)),
// Sorting arrays on different machines. Merge Sort is a recursive
// algorithm and time complexity can be expressed as following recurrence relation.

// T(n) = 2T(n / 2) + θ(n)