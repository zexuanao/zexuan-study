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
void QuickSort(SqList *L) {
    QSort(L, 1, L->length);
}
void QSort(SqList *L, int low, int high) {
    int pivot;
    if (low < high) {
        /* 将L->r[low..high]一分为二， 算出枢轴值pivot */
        pivot = Partition(L, low, high);
        /* 对低子表递归排序 */
        QSort(L, low, pivot - 1);
        /* 对高子表递归排序 */
        QSort(L, pivot + 1, high);
    }
}
int Partition(SqList *L, int low, int high) {
    int pivotkey;
    /* 用子表的第一个记录作枢轴记录 */
    pivotkey = L->r[low];

    /* 从表的两端交替向中间扫描 */
    while (low < high) {
        while (low < high && L->r[high] >= pivotkey)
            high--;

        /* 将比枢轴记录小的记录交换到低端 */
        swap(L, low, high);

        while (low < high && L->r[low] <= pivotkey)
            low++;

        /* 将比枢轴记录大的记录交换到高端 */
        swap(L, low, high);
    }

    /* 返回枢轴所在位置 */
    return low;
}
int Partition1(SqList *L, int low, int high) {
    int pivotkey;

    /* 用子表的第一个记录作为枢轴记录 */
    pivotkey = L->r[low];

    /* 将枢轴关键字备份到L->r[0] */
    L->r[0] = pivotkey;

    /* 从表的两端交替向中间扫描 */
    while (low < high) {
        while (low < high && L->r[high] >= pivotkey)
            high--;

        /* 采用替换而不是交换的方式进行操作 */
        L->r[low] = L->r[high];

        while (low < high && L->r[low] <= pivotkey)
            low++;

        /* 采用替换而不是交换的方式进行操作 */
        L->r[high] = L->r[low];
    }

    /* 将枢轴数值替换回L.r[low] */
    L->r[low] = L->r[0];

    /* 返回枢轴所在位置 */
    return low;
}
