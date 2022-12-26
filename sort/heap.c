#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[largest] < arr[left])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n)
{
    // heapify
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // sort array using heap
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
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
    int arr[] = {6, 2, 5, -7, 9, 4, 1, 0, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    heap_sort(arr, n);
    print(arr, n);

    return 0;
}