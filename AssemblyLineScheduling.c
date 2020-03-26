#include<stdio.h>
#define MAX 100
int min(int a,int b)
{
    return a<b?a:b;
}
int assemblyLineScheduling(int a[2][MAX],int t[2][MAX],int n,int e[2],int x[2])
{
    int t1[MAX], t2[MAX],i;
    t1[0] = e[0] + a[0][0];
    t2[0] = e[1] + a[1][0];
    for(i=1;i<n;i++)
    {
        t1[i] = min(t1[i-1]+a[0][i],t2[i-1]+t[1][i]+a[0][i]);
        t2[i] = min(t2[i-1]+a[1][i],t1[i-1]+t[0][i]+a[1][i]);
    }
    return min((t1[n-1]+x[0]),(t2[n-1]+x[1]));
}
void main()
{
    int n,a[2][MAX],t[2][MAX],e[2],x[2],i;
    printf("\nEnter the number of stages:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the processing time and switching time to Stage(1,%d):",i+1);
        scanf("%d%d",&a[0][i],&t[0][i]);
    }
    for(i=0;i<n;i++)
    {
        printf("\nEnter the processing time and switching time to Stage(2,%d):",i+1);
        scanf("%d%d",&a[1][i],&t[1][i]);
    }
    for(i=0;i<2;i++)
    {
        printf("\nEnter the entry time and exit time for Assembly Line %d:",i+1);
        scanf("%d%d",&e[i],&x[i]);
    }
    printf("\nMinimum Time Required to complete a job is %d \n",assemblyLineScheduling(a,t,n,e,x));
}