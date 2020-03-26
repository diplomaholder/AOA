#include<stdio.h> 
#define MAX 1000
#define INF 99999 
void printSolution(int dist[MAX][MAX], int n); 
void floydWarshall (int graph[MAX][MAX], int n) 
{ 
    int dist[MAX][MAX], i, j, k; 
    for (i = 0; i < n; i++) 
        for (j = 0; j < n; j++) 
            dist[i][j] = graph[i][j]; 
    for (k = 0; k < n; k++) 
    { 
        for (i = 0; i < n; i++) 
        { 
            for (j = 0; j < n; j++) 
            { 
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
            } 
        } 
    } 
    printSolution(dist,n); 
} 
void printSolution(int dist[MAX][MAX] ,int n) 
{ 
    printf ("The following matrix shows the shortest distances between every pair of vertices \n"); 
    for (int i = 0; i < n; i++) 
    { 
        for (int j = 0; j < n; j++) 
        { 
            if (dist[i][j] == INF) 
                printf("%7s", "INF"); 
            else
                printf ("%7d", dist[i][j]); 
        } 
        printf("\n"); 
    } 
} 

void accept() 
{ 
    /* Let us create the following weighted graph 
            10 
       (0)------->(3) 
        |         /|\ 
      5 |          | 
        |          | 1 
       \|/         | 
       (1)------->(2) 
            3           */
    int graph[MAX][MAX] = {0},n,i,j;
    printf("\nEnter the number of nodes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                graph[i][j] = 0;
                continue;
            }
            printf("\nEnter Weight of Node (%d,%d):",i+1,j+1);
            scanf("%d",&graph[i][j]);
            if(graph[i][j]==0)
            {
                graph[i][j] = INF;
            }
        }
    }
    floydWarshall(graph,n); 
} 

void main()
{
    accept();
}