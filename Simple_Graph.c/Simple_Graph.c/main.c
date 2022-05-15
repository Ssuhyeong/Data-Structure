#include <stdio.h>
#include <stdlib.h>

#define NUM_VERTEX 4

int graph[NUM_VERTEX][NUM_VERTEX];

int getIndex(char c)
{
    return c - 'A';
}

void addEdge(char _src, char _dst)
{
    int s = getIndex(_src);
    int d = getIndex(_dst);
    
    graph[s][d] = 1;
    graph[d][s] = 1;
}

void showConnectedVertex(char _obj)
{
    int r = getIndex(_obj);
    
    for(int i = 0;i<NUM_VERTEX;i++)
    {
        if(graph[r][i] == 1)
            printf("%c ", i+65);
    }
    printf("\n");
}

int main()
{
    addEdge('A', 'B');
    addEdge('A', 'C');
    addEdge('B', 'D');
    addEdge('C', 'D');
    showConnectedVertex('D');
    return 0;
}
