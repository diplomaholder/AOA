#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int x[MAX]={0},n;
void nextvalue(int k)
{
    int j;
    start: x[k] = (x[k]+1)%(n+1);
    if(x[k]==0)
        return;
    for(j=1;j<k;j++)
        if(x[k]==x[j]||abs(x[k]-x[j])==abs(k-j))
            goto start;
}
void display()
{
    for(int i=1;i<=n;i++)
        printf("%7d",x[i]);
    printf("\n\n");
    for(int i=1;i<=n;++i)
    {
        printf("|");
        for(int j=1;j<=n;++j) 
        {
            if(x[i]==j)
                printf("%3c%3c|",'Q',' '); 
            else
                printf("%3c%3c|",'-',' '); 
        }
        printf("\n");
    }
    printf("\n\n");
}
void nqueens(int k)
{
    loop: nextvalue(k);
    if(x[k]==0)
        return;
    if(k==n)
        display();
    else nqueens(k+1);
    goto loop;
}
void main()
{
    printf("\nEnter the number queens to be placed in 'nxn' checkerboard:");
    scanf("%d",&n);
    nqueens(1);
}