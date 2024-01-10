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

/* 对顺序表L作简单选择排序 */
void SelectSort(SqList *L) {
    int i, j, min;

    for (i = 1; i < L->length; i++) {
        /* 将当前下标定义为最小值下标 */
        min = i;

        /* 循环之后的数据 */
        for (j = i + 1; j <= L->length; j++) {
            /* 如果有小于当前最小值的关键字 */
            if (L->r[min] > L->r[j]) {
                /* 将此关键字的下标赋值给min */
                min = j;
            }
        }

        /* 若min不等于i，说明找到最小值，交换 */
        if (i != min) {
            /* 交换L->r[i]与L->r[min]的值 */
            swap(L, i, min);
        }
    }
}
