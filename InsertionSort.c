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

void casegen()
{
    int temp[50000],n,start=100,end=1000;
    FILE *fpworst = fopen("iworst.csv", "w");
    FILE *fpbest = fopen("ibest.csv", "w");
    for(n=5000; n<=25000; n=n+500)
    {
        genRandomFile2(n,"test.txt",start,end);
        readRandomFile("test.txt",temp);
        clock_t t1 = clock();
        insertionSort(temp,n);
        t1 = clock() - t1;
        fprintf(fpworst, "%lf,",(double)t1/CLOCKS_PER_SEC);
        clock_t t2 = clock();
        insertionSort(temp, n);
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