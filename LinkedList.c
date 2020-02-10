#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct
{
    node *start;
}LL;
void insertBeginning(LL *l, int ele)
{
    node *newrec;
    newrec=(node*)malloc(sizeof(node));
    newrec->data=ele;
    newrec->next=l->start;
    l->start=newrec; 
}
void insertEnd(LL *l, int ele)
{
    node *newrec, *p;
    newrec=(node*)malloc(sizeof(node));
    newrec->data=ele;
    newrec->next=NULL;

    if(l->start==NULL)
        l->start=newrec;
    else
    {
        p=l->start;
        while(p->next!=NULL)
        p=p->next;
        p->next=newrec;
    }
}
int count(LL *l)
{
    node *p;
    int count=0;
    p=l->start;
    while (p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;    
}
int deleteBeginning(LL *l)
{
    if(l->start==NULL)
    return -1;
    node *p;
    p = l->start;
    l->start = l->start->next;
    return p->data;
}
int deleteEnd(LL *l)
{
    node *p, *q;
    
    if(l->start==NULL)
    return -1;
    
    else if(l->start->next==NULL)
    {
        q = l->start;
        l->start=NULL;
    }

    else
    {   p = l->start;
        while(p->next->next != NULL)
            p = p->next;
        q = p->next;
        p->next = NULL;
    }
    return q->data;
}
void deleteElement(LL *l, int ele)
{   node *p, *q;
    if(l->start == NULL)
    {
        return;
    }
    if(l->start->data==ele)
    {
        q=l->start;
        l->start=l->start->next;
        printf("\nElement deleted\n");
        return;
    }
    p=l->start;
    while(p->next!=NULL && p->next->data!=ele)
        p=p->next;
    if(p->next==NULL)
    {
        return;
    }
    p->next=p->next->next;
    printf("\nElement deleted\n");
}
void display(LL *l)
{
    node *p;
    p=l->start;
    
    if(l->start==NULL)
    {
        printf("\nThe linked list is empty\n");
        return;
    }
    printf("Linked List");
    while(p!=NULL)
    {
        printf("->%d", p->data);
        p=p->next;
    }
    printf("\n");
}
int search(LL *l, int ele)
{
    node *p;
    p=l->start;
    if(p==NULL)
    {
        return 0;
    }
    while(p->next!=NULL)
    {
        if(p->data==ele)
            return 1;
        p = p->next;
    }
    return 0;
}
void sort(LL *l)
{
    node *i, *j;
    int temp;

    for(i=l->start; i->next!=NULL; i=i->next)
    {
        for(j=l->start; j->next!=NULL; j=j->next)
        {
            if(j->data > j->next->data)
            {
                temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}
