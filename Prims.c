#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.c"
#define MAX 100
int ExtractMin(int a[],int visited[],int n)
{
    int i,min=99999,pos;
    for(i=0;i<n;i++)
    {
        if(a[i]<min&&!visited[i])
        {
            min = a[i];
            pos = i;
        }
    }
    return pos;
}
void printArray(int a[MAX][MAX],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}
void PrimMST(int w[MAX][MAX],int n,int r)
{
    int pi[MAX]={-1};
    int d[MAX]={99999},visited[MAX]={0};
    int i,j,min,mincost=0;
    d[r] = 0;
    for(j=0;j<n;j++)
    {
        printArray(w,n);
        min = ExtractMin(d,visited,n);
        printf("\n%d",min);
        for(i=0;i<n;i++)
        {
            if(w[min][i]<d[i])
            {
                d[i] = w[min][i];
                pi[i] = min;
            }
        }
        visited[min] = 1;
        printf("\nCheck");
    }
    for(i=0;i<n;i++)
    {
        if(pi[i]!=-1)
        {
            printf("\n%d------>%d  =  %d",pi[i]+1,i+1,d[i]);
        }
        mincost = mincost + d[i];
    }
    printf("\n\nMinimum Cost of MCST = %d",mincost);
}
void main()
{
    int w[MAX][MAX],pi[MAX],d[MAX],Q[MAX],i,j,n,r;
    printf("\n\n\tImplementation of Kruskal's algorithmnn");
    printf("\nEnter the no. of vertices\n");
    scanf("%d",&n);
    printf("\nEnter the cost adjacency matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                w[i][j]=99999;
                continue;
            }
            else if(w[j][i])
            {
                w[i][j] = w[j][i];
                continue;
            }
            printf("\nCost of (%d,%d):",i+1,j+1);
            scanf("%d",&w[i][j]);
            if(w[i][j]==0)
                w[i][j]=99999;
        }
    }
    printArray(w,n);
    printf("\n\nEnter Starting Node:");
    scanf("%d",&r);
    PrimMST(w,n,r-1);
}