#include <stdio.h>
#include <limits.h>

#define TRUE 1 // 최단 경로가 확정된 상태
#define FALSE 0
#define MAX_VERTICES 5 // 그래프의 정점 개수
#define INF 10000

int weight[MAX_VERTICES][MAX_VERTICES] =
{
    {0, 10, 5, INF, INF}, //그래프 가중치 인접 행렬
    {INF, 0, 2, 1, INF},
    {INF, 3, 0, 9 ,2},
    {INF, INF, INF, 0, 4},
    {7, INF, INF, 6, 0},
};

int distance[MAX_VERTICES]; // 시작 정점에서 시작하는 최단 경로 길이 저장
int S[MAX_VERTICES]; // 정점의 집합

// 최단 경로를 갖는 다음 정점을 찾는 연산
int nextVertex(int n)
{
    int i, min, minpos; // 최소값, 최소값 인덱스
    min = INT_MAX;
    minpos = -1;
    for(i = 0;i<n;i++)
    {
        if((distance[i] < min) && !S[i]) // 최소 경로를 가지는 정점의 인덱스를 반환
        {
            min = distance[i];
            minpos = i;
        }
    }
    return minpos;
}

//최단 경로 구하는 과정을 출력하는 연ㅅ나
int printStep(int step)
{
    int i;
    printf("\n %3d 단계 : S ={", step);
    for(i = 0;i<MAX_VERTICES;i++)
    {
        if(S[i] == TRUE)
            printf("%3c", i+65);
    }
    if(step<1) printf("  } \t\t\t");
    else if(step<4) printf("  } \t\t");
    else printf("  } \t");
    printf("distance : [");
    for(i = 0;i<MAX_VERTICES;i++)
        if(distance[i] == 10000)
            printf("%4c",'*');
        else printf("%4d", distance[i]);
        printf("%4c",']');
        return ++step;
}

void Dijkstr_shortestPath(int start, int n)
{
    int i, u, w, step = 0;
    
    for(i = 1;i<n;i++)
    {
        distance[i] = weight[start][i]; // 일단 경로를 구하는 정점과 인접한 정점을 입력
        S[i] = FALSE; // 정점 배열을 모두 FALSE로
    }
    
    S[start] = TRUE; // 자기 자신은 0으로 확정
    distance[start] = 0;
    
    step = printStep(0);
    
    for(i = 0;i<n-1;i++)
    {
        u = nextVertex(n); // 최단 경로를 가진 다음 정점을 구함
        S[u] = TRUE;
        for(w = 0;w<n;w++)
            if(!S[w])
                if(distance[u]+weight[u][w] < distance[w]) // 정점 최단경로 갱신
                    distance[w] = distance[u] + weight[u][w];
        step = printStep(step);
    }
}

int main(void)
{
    int i, j;
    for(i = 0;i<MAX_VERTICES;i++)
    {
        for(j = 0;j<MAX_VERTICES;j++)
        {
            if(weight[i][j] == 10000)
                printf("%4c", '*');
            else
                printf("%4d", weight[i][j]);
        }
        printf("\n\n");
    }
    
    Dijkstr_shortestPath(0, MAX_VERTICES);
    return 0;
    
}
