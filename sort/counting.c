#include <stdio.h>

int max_value(int arr[], int n)
{
    int max = arr[0];

    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    return max;
}

void counting_sort(int arr[], int n)
{
    int count_len = max_value(arr, n) + 1;

    int count[count_len], output[n];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= count_len; i++)
        count[i] += count[i - 1];

    for (int i = 0; i < n; i++)
        output[--count[arr[i]]] = arr[i];

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {5, 4, 3, 7, 4, 2, 756, 5, 1000};
    int n = sizeof(arr) / sizeof(arr[0]);

    counting_sort(arr, n);
    print(arr, n);

    return 0;
}

// Counting sort is a sorting technique based on keys between a specific range.
// Time Complexity : O(N + K) where N is the number of elements
// in the input array and K is the range of input.
// Auxiliary Space : O(N + K)