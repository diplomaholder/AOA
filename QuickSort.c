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

void casegen()
{
    int temp[50000],n,start=100,end=1000;
    FILE *fpworst = fopen("qworst.csv", "w");
    FILE *fpbest = fopen("qbest.csv", "w");
    for(n=5000; n<=25000; n=n+500)
    {
        genRandomFile2(n,"test.txt",start,end);
        readRandomFile("test.txt",temp);
        clock_t t1 = clock();
        quicksort(temp,0,n-1);
        t1 = clock() - t1;
        fprintf(fpworst, "%lf,",(double)t1/CLOCKS_PER_SEC);
        clock_t t2 = clock();
        quicksort(temp, 0,n-1);
        t2 = clock() - t2;
        fprintf(fpbest,"%lf,",(double)t2/CLOCKS_PER_SEC);
    }
    fclose(fpbest);
    fclose(fpworst);
}
void main()
{
    casegen();
}