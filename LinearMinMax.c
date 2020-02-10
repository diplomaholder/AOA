#include"diploma.h"
int min(int a,int b)
{
    return a<b?a:b;
}
int max(int a,int b)
{
    return a>b?a:b;
}
void minmax(int a[],int n,int *fmin,int *fmax)
{
    int i,max=0,min=99999;
    for(i=0;i<=n;i++)
    {
        if(a[i]>max)
        {
            max = a[i];
        }
        if(a[i]<min)
        {
            min = a[i];
        }
    }
    *fmin = min;
    *fmax = max;
}
void casegen()
{
    int temp[1000000],n,start=100,end=1000,min,max;
    FILE *fpworst = fopen("lbworst.csv", "w");
    for(n=5000; n<=1000000; n=n+1000)
    {
        srand((int)time(NULL));
        genRandomFile2(n,"test.txt",start,end);
        readRandomFile("test.txt",temp);
        clock_t t1 = clock();
        minmax(temp,n-1,&min,&max);
        t1 = clock() - t1;
        fprintf(fpworst, "%lf,",(double)t1/CLOCKS_PER_SEC);
    }
    fclose(fpworst);
}
void main()
{
    casegen();
}