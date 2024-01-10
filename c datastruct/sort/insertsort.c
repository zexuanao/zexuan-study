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

/* 对顺序表L作直接插入排序 */
void InsertSort(SqList *L) {
    int i, j;

    for (i = 2; i <= L->length; i++) {
        /* 需将L->r[i]插入有序子表 */
        if (L->r[i] < L->r[i - 1]) {
            /* 设置哨兵 */
            L->r[0] = L->r[i];

            for (j = i - 1; L->r[j] > L->r[0]; j--) {
                /* 记录后移 */
                L->r[j + 1] = L->r[j];
            }

            /* 插入到正确位置 */
            L->r[j + 1] = L->r[0];
        }
    }
}
//第一个for循环是用来找到最小的,相当于一个个插入