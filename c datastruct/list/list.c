#include <stdlib.h>
#include "list.h"


int Getint (LinkList L,int i,int *e)
{
    int j=1;
    LinkList p;
    p=L->next;
    while (p&&j<i)
    {
        p=p->next;
        ++j;
        /* code */
    }
    if(!p||j>i)
    {
        return 0;
    }
    *e=p->data;
    return 1;
    }

int ListInsert(LinkList L,int i,int e)
{
    int j=1;
    LinkList p,s;
    p=L->next;
    while(p&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i)
    {
        return 0;
    }
    s=(LinkList)malloc(sizeof(Node));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return 1;
}

int ListDelete(LinkList L, int i)
 {
    int j = 0;
    LinkList p, q;
    p = L;
    while (p->next && j < i - 1) {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1) {
        return 0; // 未找到位置 i，删除失败或者 i 超过链表长度
    }
    q = p->next; // 待删除节点
    p->next = q->next; // 将待删除节点的前驱节点指向其后继节点
    free(q); // 释放待删除节点的内存
    return 1; // 删除成功
}

int CreatList(LinkList *L,int n)
{   
    int i=0;
    LinkList p,r;
    *L=(LinkList)malloc(sizeof( Node));
    r=*L;
    for(i=0;i<n;i++)
    {
        p=(LinkList)malloc(sizeof(Node));
        p->data=0;
        r->next=p;
        r=p;
    }
    r->next=NULL;
    return 1;
}

int Clearlist(LinkList *L)
{
    LinkList p,q;
    p=(*L)->next;
    while(p)
    {
        q=p->next;
        free(p);
        p=q;
    }
    (*L)->next=NULL;
    return 1;

}

