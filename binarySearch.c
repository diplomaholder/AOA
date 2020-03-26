#include"diploma.h"
int binarySearch(int a[],int low,int high,int ele)
{
    int m = (low+high)/2;
    if(low<=high)
    {
        if(a[m]==ele)
            return 1;
        if(ele<a[m])
            return binarySearch(a,low,m-1,ele);
        else return binarySearch(a,m+1,high,ele);
    }
    return 0;
}
void casegen()
{
    int temp[1000000],n,start=100,end=1000;
    FILE *fpworst = fopen("bworst.csv", "w");
    for(n=5000; n<=1000000; n=n+1000)
    {
        srand((int)time(NULL));
        genRandomFile2(n,"test.txt",start,end);
        readRandomFile("test.txt",temp);
        clock_t t1 = clock();
        binarySearch(temp,0,n-1,(start+(rand()%(end-start+1))));
        t1 = clock() - t1;
        fprintf(fpworst, "%lf,",(double)t1/CLOCKS_PER_SEC);
    }
    fclose(fpworst);
}
void main()
{
    casegen();
}