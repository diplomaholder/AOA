#include"diploma.h"
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void cocktailSort(int a[],int low,int high)
{
    int start = low,i=0,change=1,min=a[0],max=a[0],pmax,pmin;
    int end = high;
    while(start<end)
    {
        if((a[i]>a[i+1])&&change==1&&i+1<=end)
        {
            swap(&a[i],&a[i+1]);
            i=i+change;
            continue;
        }
        if((a[i]<a[i-1])&&change==-1&&i-1>=start)
        {
            swap(&a[i],&a[i-1]);
            i=i+change;
            continue;
        }
        if(i==end)
        {
            change = -1;
            end = end - 1;
            i = i+change;
        }
        if(i==start)
        {
            change = 1;
            start = start + 1;
            i = i+change;
        }
        i=i+change;
    }
}
void main()
{
    int temp[50000],n=50000,start=100,end=1000,i;
    genRandomFile2(n,"test.txt",start,end);
    readRandomFile("test.txt",temp);
    clock_t t1 = clock();
    cocktailSort(temp,0,n-1);
    t1 = clock() - t1;
    printf("Time Taken %fs\n",(double)t1/CLOCKS_PER_SEC);
    for(i=0;i<n;i++)
    {
        printf(" %d",temp[i]);
    }    
}