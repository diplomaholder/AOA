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

void casegen()
{
    int temp[50000],n,start=100,end=1000;
    FILE *fpbest = fopen("mbest.csv", "w");
    for(n=5000; n<=25000; n=n+500)
    {
        genRandomFile2(n,"test.txt",start,end);
        readRandomFile("test.txt",temp);
        clock_t t1 = clock();
        mergesort(temp, 0, n-1);
        t1 = clock() - t1;
        fprintf(fpbest, "%d, ",(int)t1);        
    }
    fclose(fpbest);
}

void main()
{
    casegen();
}