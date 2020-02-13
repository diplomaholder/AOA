#include<stdio.h>
#include<stdlib.h>
#include"diploma.h"
int min,cost[4000][4000]={0},parent[4000];
int find(int);
int uni(int,int);
void Kruskal(int temp[4000][4000],int n)
{
    int ne=1,i,j,a,b,u,v;
    int mincost=0;
    while(ne<n)
    {
        for(i=1,min=99999;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }
        u=find(u);
        v=find(v);
        if(uni(u,v))
        {
            ne++;
            mincost +=min;
        }
        cost[a][b]=cost[b][a]=99999;
    }
    printf("\n\tMinimum cost = %d\n",mincost);
}
void caseGen()
{
    int i,j,start=100,end=1000,n;
    FILE *fpworst = fopen("kworst.csv", "w");
    for(n=100;n<=1000;n=n+10)
    {
        for(i=1;i<=n;i++)
        {
            parent[i] = 0;
        }
        genRandomGraphFile(n,"graph.txt",start,end);
        readRandomGraphFile("graph.txt",cost,n);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i==j)
                {
                    cost[i][j]=99999;
                    continue;
                }
                if(cost[i][j]==0)
                    cost[i][j]=99999;
            }
        }
        clock_t t1 = clock();
        Kruskal(cost,n);
        t1 = clock() - t1;
        fprintf(fpworst, "%lf,",(double)t1/CLOCKS_PER_SEC);
    }
}
void main()
{
    caseGen();
}
int find(int i)
{
    while(parent[i])
        i=parent[i];
    return i;
}
int uni(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}
