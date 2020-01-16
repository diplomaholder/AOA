#include"diploma.h"
void insertionSort(int temp[],int n)
{
    int i,j,val,pos;
    for(i=0;i<n-1;i++)
    {
        val = temp[i];
        for(j=i+1;j<n;j++)
        {
            if(val>temp[j])
            {
                val = temp[j];
                pos = j;
            }
        }
        temp[pos] = temp[i];
        temp[i] = val;
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