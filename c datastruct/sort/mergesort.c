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
void MergeSort(SqList*L)
{
    Msort(L->r,L->r,1,L->length);
}
void Msort(int SR[],int TR1[],int s,int t)
{
    int m;
    int TR2[MAXSIZE+1];
    if(s==t)
    TR1[s]=SR[s];
    else
    {
        m=(s+t)/2;
        Msort(SR,TR2,s,m);
        Msort(SR,TR2,m+1,t);
        Merge(TR2,TR1,s,m,t);
    }
}
void Merge(int SR[], int TR[], int i, int m, int n) {
    int j, k, l;

    // 将SR中记录由小到大归并入TR
    for (j = m + 1, k = i; i <= m && j <= n; k++) {
        if (SR[i] < SR[j])
            TR[k] = SR[i++];    
        else
            TR[k] = SR[j++];
    }

    if (i <= m) {
        for (l = 0; l <= m - i; l++)
            // 将剩余的SR[i..m]复制到TR
            TR[k + l] = SR[i + l];
    }

    if (j <= n) {
        for (l = 0; l <= n - j; l++)
            // 将剩余的SR[j..n]复制到TR
            TR[k + l] = SR[j + l];
    }
}


void MergeSort2(SqList *L) {
    // 申请额外空间
    int *TR = (int *)malloc(L->length * sizeof(int));
    int k = 1;

    while (k < L->length) {
        MergePass(L->r, TR, k, L->length);
        // 子序列长度加倍
        k = 2 * k;
        MergePass(TR, L->r, k, L->length);
        // 子序列长度加倍
        k = 2 * k;
    }

    free(TR); // 释放额外空间
}
void MergePass(int SR[], int TR[], int s, int n) {
    int i = 1;
    int j;

    while (i <= n - 2 * s + 1) {
        // 两两归并
        Merge(SR, TR, i, i + s - 1, i + 2 * s - 1);
        i = i + 2 * s;
    }

    // 归并最后两个序列
    if (i < n - s + 1) {
        Merge(SR, TR, i, i + s - 1, n);
    } else {
        // 若最后只剩下单个子序列
        for (j = i; j <= n; j++) {
            TR[j] = SR[j];
        }
    }
}
