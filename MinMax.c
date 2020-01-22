#include"diploma.h"
int min(int a,int b)
{
    return a<b?a:b;
}
int max(int a,int b)
{
    return a>b?a:b;
}
void minmax(int a[],int i,int j,int fmin,int fmax)
{
    int gmin,gmax,hmin,hmax;
    if(i==j)
    {
        fmin=fmax=a[i];
        return;
    }
    if(i==j-1)
    {
        fmin=min(a[i],a[j]);
        fmax=max(a[i],a[j]);
        return;
    }
    int m=(i+j)/2;
    minmax(a,i,m,gmin,gmax);
    minmax(a,m+1,j,hmin,hmax);
    fmin = min(gmin,hmin);
    fmax = max(gmax,hmax);
}
void casegen()
{
    int temp[1000000],n,start=100,end=1000,min,max;
    FILE *fpworst = fopen("bworst.csv", "w");
    for(n=5000; n<=1000000; n=n+1000)
    {
        srand((int)time(NULL));
        genRandomFile2(n,"test.txt",start,end);
        readRandomFile("test.txt",temp);
        clock_t t1 = clock();
        minmax(temp,0,n-1,min,max);
        t1 = clock() - t1;
        fprintf(fpworst, "%lf,",(double)t1/CLOCKS_PER_SEC);
    }
    fclose(fpworst);
}
void main()
{
    casegen();
}