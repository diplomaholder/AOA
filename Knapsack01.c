#include<stdio.h>
#define MAX 100
int max(int a,int b)
{
    return a>b?a:b;
}
int knapsack(int w,int wt[],int val[],int n)
{
    if(n==0||w==0)
        return 0;
    else if(wt[n-1]>w)
        return knapsack(w,wt,val,n-1);
    else max((knapsack(w-wt[n-1],wt,val,n-1)+val[n-1]),knapsack(w,wt,val,n-1));
}
void main()
{
    int n,w,val[MAX],wt[MAX],i;
    printf("\nEnter the number of items:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the Weight and Profit of Item %d:",i+1);
        scanf("%d%d",&wt[i],&val[i]);
    }
    printf("\nEnter the size of the sack:");
    scanf("%d",&w);
    printf("\nMaximum Profit is %d \n",knapsack(w,wt,val,n));
}