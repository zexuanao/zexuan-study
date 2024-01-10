#define MAXSIZE 20
typedef enum{
    true,false
}BOOL;
typedef struct 
{
    int data[MAXSIZE];
    int front;
    int rear;
    /* data */
}SqQuene;
BOOL InitQuene(SqQuene *Q)
{
    Q->front=0;
    Q->rear=0;
    return true;
}
int QueneLength(SqQuene Q)
{
    return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}
BOOL EnQuene(SqQuene *Q,int e)
{
    if((Q->rear+1)%MAXSIZE==Q->front)
        return false;
    Q->data[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXSIZE;
    return true;
}
BOOL DeQuene(SqQuene*Q,int *e)
{
    if(Q->front==Q->rear)
    return false;
    *e=Q->data[Q->front];
    Q->front=(Q->front+1)%MAXSIZE;
    return true;
}


