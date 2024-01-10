#define MAXSIZE 10
#define Status int
#define TRUE 1
#define FALSE 0
typedef struct 
{
    int r[MAXSIZE+1];
    int length;
}SqList;
void swap(SqList*L,int i,int j)
{
    int temp=L->r[i];
    L->r[i]=L->r[j];
    L->r[j]=temp;
}

/* 对顺序表L作交换排序(冒泡排序初级版) */

void BubbleSort0(SqList *L) {
    int i, j;

    for (i = 1; i < L->length; i++) {
        for (j = i + 1; j <= L->length; j++) {
            if (L->r[i] > L->r[j]) {
                /* 交换L->r[i]与L->r[j]的值 */
                swap(L, i, j);
            }
        }
    }
}

/* 对顺序表L作冒泡排序 */
void BubbleSort(SqList *L) {
    int i, j;

    for (i = 1; i < L->length; i++) {
        /* 注意j是从后往前循环 */
        for (j = L->length - 1; j >= i; j--) {
            /* 若前者大于后者(注意这里与上一算法差异) */
            if (L->r[j] > L->r[j + 1]) {
                /* 交换L->r[j]与L->r[j+1]的值 */
                swap(L, j, j + 1);
            }
        }
    }
}

/* 对顺序表L作改进冒泡算法 */
void BubbleSort2(SqList *L) {
    int i, j;
    /* flag用来作为标记 */
    Status flag = TRUE;  // Status应该是一个枚举类型

    /* 若flag为true说明有过数据交换，否则停止循环 */
    for (i = 1; i < L->length && flag; i++) {
        /* 初始为false */
        flag = FALSE;

        for (j = L->length - 1; j >= i; j--) {
            if (L->r[j] > L->r[j + 1]) {
                /* 交换L->r[j]与L->r[j+1]的值 */
                swap(L, j, j + 1);
                /* 如果有数据交换，则flag为true */
                flag = TRUE;
            }
        }
    }
}
