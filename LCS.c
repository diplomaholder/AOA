#include<stdio.h>
#include<string.h>
#define MAX 100
typedef struct 
{
    int a[MAX],top;
}Stack;
int pop(Stack *s)
{
    if(s->top == -1)
        return -1;
    int x = s->a[s->top];
    s->top--;
    return x;
}
void push(Stack *s,int ele)
{
    if(s->top == MAX-1)
        return;
    s->top++;
    s->a[s->top] = ele;
}
int isempty(Stack *s)
{
    if(s->top==-1)
        return 1;
    return 0;
}
char s1[MAX], s2[MAX];
Stack st;
void direct(char D[MAX][MAX],int i, int j)
{
    if(i==0||j==0)
        return;
    if(D[i][j]=='d')
    {
        push(&st,i-1);
        --i;
        --j;
        direct(D,i,j);
    }
    else if(D[i][j]=='u')
    {
        --i;
        direct(D,i,j);
    }
    else
    {
        --j;
        direct(D,i,j);
    }
}
void printLCS()
{
    while(!isempty(&st))
    {
        printf("%c",s1[pop(&st)]);
    }
    printf("\n");
}
void LCS()
{
    int M[MAX][MAX],i,j;
    char D[MAX][MAX];
    st.top = -1;
    for(i=0;i<strlen(s1)+1;i++)
    {
        M[i][0] = 0;
    }
    for(j=0;j<strlen(s2)+1;j++)
    {
        M[0][j] = 0;
    }
    for(i=1;i<strlen(s1)+1;i++)
    {
        for(j=1;j<strlen(s2)+1;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                M[i][j] = M[i-1][j-1] + 1;
                D[i][j] = 'd';
            }
            else if (M[i-1][j] > M[i][j-1])
            {
                M[i][j] = M[i-1][j];
                D[i][j] = 'u';
            }
            else
            {
                M[i][j] = M[i][j-1];
                D[i][j] = 'l';                
            }
        }
    }
    int a = strlen(s1), b = strlen(s2);
    direct(D,a,b);
    printf("\nLongest Common Subsequence is ");
    printLCS();
}
void main()
{
    printf("\nEnter two strings to find the Longest Common Subsequence between the two:");
    printf("\nEnter String 1:");
    scanf("%s",&s1);
    printf("\nEnter String 2:");
    scanf("%s",&s2);
    LCS();
}