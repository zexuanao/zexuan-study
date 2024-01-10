typedef enum
{
    false,
    true
}BOOL;
#define MAXSIZE 20
typedef struct stack
{
    int data[MAXSIZE];
    int top;
}SqStack;
//空元素时top=-1
BOOL push(SqStack *S,int e)
{
    if(S->top==MAXSIZE-1)
        return false;
    S->top++;
    S->data[S->top]=e;
    return true;
}
BOOL Pop(SqStack*S,int *e)
{
    if (S->top==-1)
        return false;
    *e=S->data[S->top];
    S->top--;
    return true;
}
