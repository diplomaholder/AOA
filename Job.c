#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct Job 
{ 
    int id;
    int dead;
    int profit;
}Job;
Job j[MAX];
int job[MAX]={0}; 
int cmpfunc (const void * a, const void * b) {
    struct Job *j1 = (struct Job *)a;
    struct Job *j2 = (struct Job *)b;
    return (j1->profit < j2->profit);
}
int getSlot(Job j1)
{
    int temp = j1.dead-1;
    while(temp>=0)
    {
        if(!job[temp])
        {
            job[temp] = j1.id;
            return 1;
        }
        temp--;
    }
    return 0;
}
int max(int n)
{
    int i,max=0;
    for(i=0;i<n;i++)
    {
        if(j[i].dead>max)
            max = j[i].dead;
    }
    return max;
}
void jobSequencing(int n)
{
    int i,allocated,totalProfit=0;
    qsort(j, n, sizeof(Job), cmpfunc);
    for(i=0;i<n;i++)
    {
        allocated = getSlot(j[i]);
        if(allocated)
        {
            totalProfit = totalProfit + j[i].profit;
        }
        else
        {
            printf("\nJob %d not scheduled",j[i].id);
        }
    }
    printf("\nTotal Profit = %d",totalProfit);
}
void main()
{
    int n,i;
    printf("\nEnter the number of jobs to be sequenced:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter id, deadline and profit of Job %d:",i+1);
        scanf("%d%d%d",&j[i].id,&j[i].dead,&j[i].profit);
    }
    jobSequencing(n);
}