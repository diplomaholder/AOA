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
void genRandomGraphFile(int n,char *filename,int start,int end)
{   
    FILE *fp = fopen(filename,"w");
    int i,temp[n*n];
    genRandomFile1(n*n,filename,2);
    readRandomFile(filename,temp);
    time_t seed = time(NULL);
    srand((int)seed);
    for(i=0;i<n*n;i++)
    {
        fprintf(fp,"%d ",(temp[i]*(start+(rand()%(end-start+1)))));
    }
    fclose(fp);
}
int* readRandomGraphFile(char *filename,int* temp,int n)
{
    FILE *fp = fopen(filename,"r");
    int i=0,j=0,t;
    while(fscanf(fp,"%d",&t)==1)
    {
        if(*((temp + i)+j)!=0){
            *((temp + j)+i) = *((temp + i)+j);
            continue;
        }
        if(i==j)
        {
            *((temp + j)+i) = 0;
            continue;
        }
        *((temp + j)+i) = t;
        j++;
        if(j==n)
        {
            j=0;
            i++;
        }
    }   
    return temp;
}