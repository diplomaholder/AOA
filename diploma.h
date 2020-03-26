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

void readRandomGraphFile(char *filename,int temp[4000][4000],int n)
{
    FILE *fp = fopen(filename,"r");
    int i=1,j=1,t;
    while(fscanf(fp,"%d",&t)==1)
    {
        temp[i][j] = t;
        j++;
        if(j==n+1)
        {
            j=0;
            i++;
        }
    }   
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(temp[i][j])
                temp[j][i] = temp[i][j];
        }
    }
    fclose(fp);
}