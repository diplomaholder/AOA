#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
void genRandomFile(int n,char *filename)
{   
    FILE *fp = fopen(filename,"w");
    int i;
    time_t seed = time(NULL);
    srand((int)seed);
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%d ",rand());
    }
    fclose(fp);
}
void genRandomFile1(int n,char *filename,int limit)
{   
    FILE *fp = fopen(filename,"w");
    int i;
    time_t seed = time(NULL);
    srand((int)seed);
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%d ",rand()%limit);
    }
    fclose(fp);
}
void genRandomFile2(int n,char *filename,int start,int end)
{   
    FILE *fp = fopen(filename,"w");
    int i;
    time_t seed = time(NULL);
    srand((int)seed);
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%d ",(start+(rand()%(end-start+1))));
    }
    fclose(fp);
}
int* readRandomFile(char *filename,int* temp)
{
    FILE *fp = fopen(filename,"r");
    int i=0,t;
    while(fscanf(fp,"%d",&t)==1)
    {
        *(temp + i) = t;
        i++;
    }   
    return temp;
}