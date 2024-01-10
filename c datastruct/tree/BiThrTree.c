typedef enum 
{true,false
    /* data */
}BOOL;

typedef struct BiThrNode {
    /* 结点数据 */
    char data;
    /* 左右孩子指针 */
    struct BiThrNode *lchild, *rchild;
    int LTag; /* 左标志 */
    int RTag; /* 右标志 */
} BiThrNode, *BiThrTree;
BiThrTree pre; /* 全局变量，始终指向刚刚访问过的结点 */

/* 中序遍历进行中序线索化 */
void InThreading(BiThrTree p) {
    if (p) {
        /* 递归左子树线索化 */
        InThreading(p->lchild);

        /* 没有左孩子 */
        if (!p->lchild) {
            /* 前驱线索 */
            p->LTag = 1;
            /* 左孩子指针指向前驱 */
            p->lchild = pre;
        }

        /* 前驱没有右孩子 */
        if (!pre->rchild) {
            /* 后继线索 */
            pre->RTag = 1;
            /* 前驱右孩子指针指向后继（当前结点p） */
            pre->rchild = p;
        }

        /* 保持pre指向p的前驱 */
        pre = p;

        /* 递归右子树线索化 */
        InThreading(p->rchild);
    }
}
BOOL InOrderTraverse_Thr(BiThrTree T) {
    BiThrTree p;

    /* p指向根结点 */
    p = T->lchild;

    /* 空树或遍历结束时，p == T */
    while (p != T) {

        /* 当LTag==0时循环到中序序列第一个结点 */
        while (p->LTag == 0)
            p = p->lchild;

        /* 显示结点数据，可以更改为其他对结点操作 */
        printf("%c", p->data);

        while (p->RTag == 1 && p->rchild != T) {
            p = p->rchild;
            printf("%c", p->data);
        }

        /* p进至其右子树根 */
        p = p->rchild;
    }

    return true;
}

