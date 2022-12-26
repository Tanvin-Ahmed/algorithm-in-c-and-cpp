#include <stdio.h>

void DFS(int arr[][7], int visited[], int n, int i)
{
    printf("%d, ", i);

    visited[i] = 1;

    for (int j = 0; j < n; j++)
    {
        if (arr[i][j] == 1 && !visited[j])
        {
            DFS(arr, visited, n, j);
        }
    }
}

int main()
{
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};

    int arr[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    DFS(arr, visited, 7, 0);

    return 0;
}