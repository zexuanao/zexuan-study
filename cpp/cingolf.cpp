#include <iostream>
const int Max = 5;

int main() {
    using namespace std;
    // 获取数据
    int golf[Max];
    cout << "请输入您的高尔夫分数。\n";
    cout << "您必须输入 " << Max << " 轮比赛分数。\n";

    int i;
    for (i = 0; i < Max; i++) {
        cout << "第" << i + 1 << "轮：";
        while (!(cin >> golf[i])) {
            // 重置输入
            cin.clear();
            //cin.clear() 函数会清除输入流的错误状态，并使其恢复到正常的状态，
            //这样就可以继续进行输入操作。通常在使用 cin 读取数据时，
            //如果发生错误（比如输入了非数字字符，但你需要输入数字），
            //可以结合 cin.clear() 和 cin.ignore() 来处理错误状态并清除错误的输入。
            while (cin.get() != '\n')
                continue; // 清除错误的输入

            // 提示用户重新输入数字
            cout << "请输入一个数字：";
        }
    }

    // 计算平均值
    double total = 0;
    for (i = 0; i < Max; i++)
        total += golf[i];

    // 报告结果
    cout << "平均分为：" << total / Max << "，共" << Max << "轮比赛。\n";
    return 0;
}
