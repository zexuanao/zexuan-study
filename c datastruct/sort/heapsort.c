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
void HeapSort(SqList *L) {
    int i;
    // 把L中的r构建成一个大顶堆
    for (i = L->length / 2; i > 0; i--)
        HeapAdjust(L, i, L->length);
    
    for (i = L->length; i > 1; i--) {
        // 将堆顶记录和当前未经排序子序列的最后一个记录交换
        swap(L, 1, i);
        // 将L->r[1..i-1]重新调整为大顶堆
        HeapAdjust(L, 1, i - 1);
    }
}
void HeapAdjust(SqList *L, int s, int m) {
    int temp, j;
    temp = L->r[s];
    
    // 沿关键字较大的孩子结点向下筛选
    for (j = 2 * s; j <= m; j *= 2) {
        if (j < m && L->r[j] < L->r[j + 1])
            // j为关键字中较大的记录的下标
            ++j;
        
        if (temp >= L->r[j])
            // rc应插入在位置s上
            break;
        
        L->r[s] = L->r[j];
        s = j;
    }
    
    // 插入
    L->r[s] = temp;
}
