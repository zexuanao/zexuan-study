int F[100];
void Fibonacci();


int Fibonacci_Search(int *a, int n, int key) {
    int low, high, mid, i, k;
    Fibonacci(F,100);
    // 定义最低下标为记录首位
    low = 0;

    // 定义最高下标为记录末位
    high = n - 1;

    k = 0;

    // 计算n位于斐波那契数列的位置
    while (n > F[k] - 1)
        k++;

    // 将不满的数值补全
    for (i = n; i < F[k] - 1; i++)
        a[i] = a[n];

    while (low <= high) {
        // 计算当前分隔的下标
        mid = low + F[k - 1] - 1;

        // 若查找记录小于当前分隔记录
        if (key < a[mid]) {
            // 最高下标调整到分隔下标mid-1处
            high = mid - 1;
            // 斐波那契数列下标减一位
            k = k - 1;
        }
        // 若查找记录大于当前分隔记录
        else if (key > a[mid]) {
            // 最低下标调整到分隔下标mid+1处
            low = mid + 1;
            // 斐波那契数列下标减两位
            k = k - 2;
        } else {
            if (mid <= n)
                // 若相等则说明mid即为查找到的位置
                return mid;
            else
                // 若mid>n说明是补全数值，返回n
                return n;
        }
    }
    
    return -1; // 如果未找到返回-1或其他适当值
}
void Fibonacci(int F[], int n) {
    F[0] = 0;
    F[1] = 1;

    for (int i = 2; i < n; i++) {
        F[i] = F[i - 1] + F[i - 2];
    }
}
