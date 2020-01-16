#include"time_handler.h"
void simplemerge(int a[], int low, int mid, int high)
{
    int temp[1000000],k=0;
    int i = low;
    int j = mid + 1;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while(i<=mid)
    {
        temp[k++] = a[i++];
    }
    while(j<=high)
    {
        temp[k++] = a[j++];
    }
    k=0;
    for(i=low;i<=high;i++)
    {
        a[i] = temp[k++];
    }
}
void mergesort(int a[], int low, int high)
{
    if(low<high)
    {   
        int mid = (low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        simplemerge(a,low,mid,high); 
    }
}
void main()
{
    int temp[1000000],i,n=1000000,start=100,end=1000;
    genRandFile2(n,"test.txt",start,end);
    readRandFile("test.txt",temp);
    clock_t t = clock();
    mergesort(temp,0,n-1);
    t = clock()-t;
    printf("Time taken %fs\n",((double)t/CLOCKS_PER_SEC));
}