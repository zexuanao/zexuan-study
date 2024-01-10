typedef enum{
    true,
    false
}BOOL;
#define MAXSIZE 20
typedef struct 
{
    /* data */
    int data[MAXSIZE];
    int top1;
    int top2;
}SqDoubleStack;
BOOL Push(SqDoubleStack *S,int e,int number)
{
    if(S->top1+1==S->top2)
        return false;
    if(number==1)
        S->data[++S->top1]=e;
    else if(number==2)
        S->data[++S->top2]=e;
    return true;
}
BOOL Pop (SqDoubleStack*S,int *e,int number)
{
    if(number==1)
    {
        if(S->top1==-1)
            return false;
        *e=S->data[S->top1--];
    }
    else if (number==2)
    {
        if(S->top2==MAXSIZE)
            return false;
        *e=S->data[S->top2++];
    }
    return true;
}

