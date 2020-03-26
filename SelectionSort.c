#include"diploma.h"
void selectionSort(int temp[],int n)
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
        if(!(i==pos))
        {
            temp[pos] = temp[i];
            temp[i] = val;    
        }
    }
}

void casegen()
{
    int temp[50000],n,start=100,end=1000;
    FILE *fpbest = fopen("sAverage.csv", "w");
    for(n=5000; n<=25000; n=n+500)
    {
        genRandomFile2(n,"test.txt",start,end);
        readRandomFile("test.txt",temp);
        clock_t t1 = clock();
        selectionSort(temp, n);
        t1 = clock() - t1;
        fprintf(fpbest, "%f, ",(double)t1/CLOCKS_PER_SEC);        
    }
    fclose(fpbest);
}

void main()
{
    casegen();
}