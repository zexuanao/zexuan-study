#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"

using std::cin;
using std::cout;
using std::string;

int main() {
    Stack<string> st; // 创建一个空栈
    char ch;
    string po;

    cout << "请输入 A 添加一个采购订单，输入 P 处理订单，输入 Q 退出。" << std::endl;

    while (cin >> ch && std::toupper(ch) != 'Q') {
        while (cin.get() != '\n') // 清空输入缓冲区
            continue;

        if (!std::isalpha(ch)) {
            cout << 'A';
            continue;
        }

        switch (ch) {
            case 'A':
            case 'a':
                cout << "请输入要添加的订单号：";
                cin >> po;
                if (st.isfull())
                    cout << "栈已满。" << std::endl;
                else
                    st.push(po);
                break;

            case 'P':
            case 'p':
                if (st.isempty())
                    cout << "栈已空。" << std::endl;
                else {
                    st.pop(po);
                    cout << "PO号 #" << po << " 已弹出。" << std::endl;
                }
                break;
        }

        cout << "请输入 A 添加一个采购订单，输入 P 处理订单，输入 Q 退出。" << std::endl;
    }

    cout << "再见！" << std::endl;
    return 0;
}
