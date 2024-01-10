#pragma once
typedef struct Node

{

int data;

struct Node *next;

} Node;

/* 定义LinkList */
//相当于头指针
typedef struct Node *LinkList;
int Getint (LinkList L,int i,int *e);
int ListInsert(LinkList L,int i,int e);
int ListDelete(LinkList L, int i);
int CreatList(LinkList *L,int n);
int Clearlist(LinkList *L);