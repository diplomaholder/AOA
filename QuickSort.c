#include"time_handler.h"
int partition(int a[], int low, int high)
{
    int i = low;
    int j = high;
    int x = a[low];
    while(i<=j)
    {
        while(a[i]<=x)
            i++;
        while(a[j]>x)
            j--;
        if(i<j)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}
void quicksort(int a[], int low, int high)
{
    if(low<high)
    {   
        int pos = partition(a,low,high);
        quicksort(a,low,pos-1);
        quicksort(a,pos+1,high);
    }
}
void main()
{
    int temp[1000000],i,n=1000000,start=100,end=1000;
    genRandFile2(n,"test.txt",start,end);
    readRandFile("test.txt",temp);
    clock_t t = clock();
    quicksort(temp,0,n-1);
    t = clock()-t;
    printf("Time taken %fs\n",((double)t/CLOCKS_PER_SEC));
}