int Binary_Search(int *a, int n, int key) {
    int low, high, mid;

    // 定义最低下标为记录首位
    low = 0;
    
    // 定义最高下标为记录末位
    high = n - 1;

    while (low <= high) {
        // 折半
//        mid = (low + high) / 2;
        mid=low+(high-low)*(key-a[low])/(a[high]-a[low]);/* 插值 */

        // 若查找值比中值小
        if (key < a[mid])
            // 最高下标调整到中位下标小一位
            high = mid - 1;
        // 若查找值比中值大
        else if (key > a[mid])
            // 最低下标调整到中位下标大一位
            low = mid + 1;
        else
            // 若相等则说明mid即为查找到的位置
            return mid;
    }

    return -1; // 如果未找到返回-1或其他适当值
}
