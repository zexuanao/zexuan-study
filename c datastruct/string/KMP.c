//此算法为KMP，具体原理为匹配串若有相同的部分不需要每次匹配时全部退回，
//通过计算next数组得出如何回溯，而get_next函数通过优化前缀串和后缀串
//的计算长度即每次通过看门牌来回溯来精简代码。
//get_nextval为优化版本，通过把next数组优化来继续缩减时间。
typedef char* String;
void get_next(String T,int *next)
{
    int i=1,j=0;
    next[1]=0;
    while(i<T[0])
    {
        if(j==0||T[i]==T[j])
            next[++i]=++j;
        else
            j=next[j];
    }
}
int Index_KMP(String S,String T,int pos)
{
    int i=pos;
    int j=1;
    int next[255];
    get_next(T,next);
    while (i<=S[0]&&j<=T[0])
    {
        if(j==0||S[i]==T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j=next[j];
        }
    }
    if(j>T[0])
        return i-T[0];
    else
        return 0;
}

/*总结改进过的KMP算法，它是在计算出next值的同时，
如果a位字符与它next值指向的b位字符相等，
则该a位的nextval就指向b位的nextval值，
如果不等，则该a位的nextval值就是它自己a位的next的值*/
void get_nextval(String T,int *nextval)
{
    int i=1,j=0;
    nextval[1]=0;
    while(i<T[0])
    {
        if(j==0||T[i]==T[j])
        {   ++i;
            ++j;
            if(T[i]!=T[j])
                nextval[i]=j;
            else
                nextval[i]=nextval[j];
        }
        else
            j=nextval[j];
    }
}
#include<stdio.h>
int main()
{
    char A[11]={10,0,1,0,1,0,0,0,0,0,0};
    char B[3]={2,1,0};
    int i;
    i=Index_KMP(A,B,0);
    printf("%d",i);
}