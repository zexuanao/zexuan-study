#define MAXSIZE 10
#define Status int
#define TRUE 1
#define FALSE 0
typedef struct 
{
    int r[MAXSIZE+1];
    int length;
}SqList;
#define MAX_LENGTH_INSERT_SORT 7 // Threshold value for switching to Insertion Sort

// Function to perform partition in QuickSort
int Partition(SqList *L, int low, int high) {
    // Implementation of partition logic...
}

// Function to perform Insertion Sort
void InsertSort(SqList *L) {
    // Implementation of Insertion Sort...
}

// QuickSort function with a threshold for switching to Insertion Sort
void QSort(SqList *L, int low, int high) {
    int pivot;

    if ((high - low) > MAX_LENGTH_INSERT_SORT) {
        while (low < high) {
            // Partition the subarray L->r[low..high] and get pivot
            pivot = Partition(L, low, high);

            // Recursively sort the lower subarray
            QSort(L, low, pivot - 1);

            // Tail recursion for the upper subarray
            low = pivot + 1;
        }
    } else {
        // Use Insertion Sort for smaller subarrays
        InsertSort(L);
    }
}

int Partition(SqList *L, int low, int high) {
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