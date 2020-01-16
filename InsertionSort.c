#include"diploma.h"
void insertionSort(int temp[],int n)
{
    int i,j,val;
    for(i=1;i<n;i++)
    {
        val = temp[i];
        j=i-1;
        while(temp[j]>val && j>=0)
        {
            temp[j+1] = temp[j];
            j=j-1;
        }
        temp[j+1] = val;
    }
}
void main()
{
    int temp[10000],n=10000,start=100,end=1000;
    genRandomFile2(n,"test.txt",start,end);
    readRandomFile("test.txt",temp);
    clock_t t = clock();
    insertionSort(temp,n);
    t = clock() - t;
    printf("Time Taken:%fs\n",(double)t/CLOCKS_PER_SEC);
}