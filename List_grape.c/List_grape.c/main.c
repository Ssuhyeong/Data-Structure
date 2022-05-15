#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 30

typedef struct grapeType
{
    int n;
    int adjMatrix[MAX_VERTEX][MAX_VERTEX];
}grapeType;

void createGrape(grapeType* g)
{
    int i, j;
    g -> n = 0;
    for(i = 0;i<MAX_VERTEX;i++)
    {
        for(j = 0;j<MAX_VERTEX;j++)
        g->adjMatrix[i][j] = 0;
    }
}

void insertVertex(grapeType *g, int v)
{
    if(((g->n) +1) > MAX_VERTEX)
    {
        printf("\n 그래프 정점의 개수를 초과하였습니다!");
        return;
    }
    g->n++;
}

void insertEdge(grapeType *g, int u, int v)
{
    if(u >= g->n || v >= g->n)
    {
        printf("그래프의 없는 정점입니다!");
        return;
    }
    g->adjMatrix[u][v] = 1;
    
}

void print_adjMatrix(grapeType *g)
{
    int i, j;
    for(i = 0;i<(g->n);i++)
    {
        printf("\n\t\t");
        for(j = 0;j<(g->n);j++)
        {
            printf("%2d", g->adjMatrix[i][j]);
        }
    }
}

int main(void)
{
    int i;
    grapeType *G1, *G2, *G3, *G4;
    G1 = (grapeType*)malloc(sizeof(grapeType));
    G2 = (grapeType*)malloc(sizeof(grapeType));
    G3 = (grapeType*)malloc(sizeof(grapeType));
    G4 = (grapeType*)malloc(sizeof(grapeType));
    
    createGrape(G1);
    createGrape(G2);
    createGrape(G3);
    createGrape(G4);
    
    insertVertex(G1, 1);
    insertVertex(G2, 2);
    
}
