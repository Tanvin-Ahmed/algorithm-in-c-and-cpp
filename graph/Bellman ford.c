#include <stdio.h>
#include <stdlib.h>
#define INFINITY 99999

struct Edge
{
    int start;
    int end;
    int weight;
};

struct Graph
{
    int total_vertices;
    int total_edge;
    struct Edge *edge;
};

void bellmanford(struct Graph *g, int source);
void print(int distance[], int predecessor[], int n);

int main()
{
    struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
    g->total_edge = 5;
    g->total_vertices = 4;
    g->edge = (struct Edge *)malloc(sizeof(struct Edge));

    // edge 0 -start> 1
    g->edge[0].start = 0;
    g->edge[0].end = 1;
    g->edge[0].weight = 5;
    // edge 0 -start> 2
    g->edge[1].start = 0;
    g->edge[1].end = 2;
    g->edge[1].weight = 4;
    // edge 1 -start> 3
    g->edge[2].start = 1;
    g->edge[2].end = 3;
    g->edge[2].weight = 3;
    // edge 2 -start> 1
    g->edge[3].start = 2;
    g->edge[3].end = 1;
    g->edge[3].weight = 6;
    // edge 3 -start> 2
    g->edge[4].start = 3;
    g->edge[4].end = 2;
    g->edge[4].weight = 2;

    bellmanford(g, 0);

    return 0;
}

void bellmanford(struct Graph *g, int source)
{
    int distance[g->total_vertices];
    int predecessor[g->total_vertices];

    for (int i = 0; i < g->total_vertices; i++)
    {
        distance[i] = INFINITY;
        predecessor[i] = 0;
    }

    distance[source] = 0;

    // step 2: relax edges |V| - 1 times
    for (int i = 0; i < g->total_vertices - 1; i++)
    {
        for (int j = 0; j < g->total_edge; j++)
        {
            int start = g->edge[j].start;
            int end = g->edge[j].end;
            int weight = g->edge[j].weight;

            if (distance[start] != INFINITY && distance[end] > distance[start] + weight)
            {
                distance[end] = distance[start] + weight;
                predecessor[end] = start;
            }
        }
    }

    // step 3: detect negative cycle
    // if value changes then we have a negative cycle in the graph
    // and we cannot find the shortest distances
    for (int i = 0; i < g->total_edge; i++)
    {
        int start = g->edge[i].start;
        int end = g->edge[i].end;
        int weight = g->edge[i].weight;

        if (distance[start] != INFINITY && distance[end] > distance[start] + weight)
        {
            printf("Negative weight cycle detected!\n");
            return;
        }
    }

    print(distance, predecessor, g->total_vertices);
}

void print(int distance[], int predecessor[], int n)
{
    for (int i = 0; i < n; i++)
        printf("Sortest path from %d to %d: %d\n", predecessor[i], i, distance[i]);
}