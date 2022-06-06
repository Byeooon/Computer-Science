#include <stdlib.h>
#include <stdio.h>

#define N 10

typedef struct
{
    int n; //number of vertex
    int adjMat[N][N];
}GraphType;

void init(GraphType* G)
{
    G->n = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            G->adjMat[i][j] = 0;
}

void makeVertex(GraphType* G)
{
    G->n++;
}

void insertEdge(GraphType* G, int u, int v)
{
    if(u >= G->n || v >= G->n)
        printf("Error!");
    else
        G->adjMat[u][v] = G->adjMat[v][u] = 1; //non-direction matrix
}

void print(GraphType* G)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            printf("%d ", G->adjMat[i][j]);
        printf("\n");
    }
}

int main()
{
    GraphType G;
    init(&G);

    int n; //input number of vertex
    scanf("%d ", &n);

    for(int i = 0; i < n; i++)
        makeVertex(&G);

    insertEdge(&G, 0, 1); insertEdge(&G, 0, 2); insertEdge(&G, 0, 3);
    insertEdge(&G, 1, 2); insertEdge(&G, 2, 3);

    print(&G);

    return 0;
}