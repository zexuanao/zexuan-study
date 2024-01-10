//将所有节点排成一列，他们有自己的双亲节点和子结点
//且子结点按照顺序依次向后排列
#define MAX_TREE_SIZE 100 
typedef struct CTNODE
{
    /* data */
    int child;
    int parent;
    struct CTNode *next;
}*ChildPtr;
 typedef struct 
 {
    /* data */
    int data;
    ChildPtr firstchild;
 }CTBox;
 typedef struct  
 {
    /* data */
    CTBox nodes[MAX_TREE_SIZE];
    int r,n;
 }CTtree;
 
 