#include"list.h"
#include<stdio.h>

int main()
{   int n,re;
    int i=0; 
    printf("创建一个几个元素的链表？\n"); 
    scanf("%d",&n);
    LinkList L;
    re=CreatList(&L,n);
    if(re==0)
    {
        printf("没有成功创建\n");
    }
    while(re)
    {
        printf("添加1,删除2,退出0\n");
        scanf("%d",&re);
        if(re==1)
        {
            i++;
            ListInsert(L,i,0);
            
        }
       else if(re!=1&&re!=2&&re!=0)
        {
            printf("请输入1、2");

        }
        else
        {
            printf("已退出");
        }
        
    }
    re=Clearlist(&L);
    if(re==0)
    {
        printf("清空错误\n");
    } 
    return 0;
}