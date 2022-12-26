#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct Queue *q)
{
    if (q->r == q->f)
        return 1;
    else
        return 0;
}

int isFull(struct Queue *q)
{
    if (q->r == q->size - 1)
        return 1;
    else
        return 0;
}

void enqueue(struct Queue *q, int value)
{
    if (isFull(&q))
        printf("Queue is full\n");
    else
    {
        q->r++;
        q->arr[q->r] = value;
    }
}

int dequeue(struct Queue *q)
{
    int element = -1;
    if (isEmpty(&q))
        printf("Queue is Empty\n");
    else
    {
        q->f++;
        element = q->arr[q->f];
    }

    return element;
}

int main()
{
    int i = 0;
    struct Queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    int visited[7] = {0, 0, 0, 0, 0, 0, 0};

    int arr[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q, i); // enqueue i for exploration

    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (arr[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

    return 0;
}