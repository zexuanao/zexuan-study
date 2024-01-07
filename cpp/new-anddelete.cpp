#include <iostream>
#include <string>
#include <new>
using namespace std;

const int BUF = 512;

class JustTesting {
private:
    string words;
    int number;

public:
    JustTesting(const string & s = "Just Testing", int n = 0)
    {words=s;
     number=n; 
        cout << words << " constructed\n";
    }

    ~JustTesting() {
        cout << words << " destroyed\n";
    }

    void Show() const {
        cout << words << " " << number << endl;
    }
};

int main() {
    char * buffer = new char[BUF]; // 获取一个内存块

    JustTesting *pc1, *pc2;
    pc1 = new (buffer) JustTesting; // 在缓冲区中放置对象
    pc2 = new JustTesting("Heap1", 20); // 在堆上放置对象

    cout << "Memory block addresses:\n";
    cout << "buffer: " << static_cast<void *>(buffer) << "\n";
    cout << "heap: " << pc2 << endl;

    cout << "Memory contents:\n";
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2->Show();

    JustTesting *pc3, *pc4;

    // 使用放置 new 来安排存放位置
    pc3 = new (buffer + sizeof(JustTesting)) JustTesting("Better Idea", 6);
    pc4 = new JustTesting("Heap2", 10);

    cout << "Memory contents:\n";
    cout << pc3 << ": ";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();

    delete pc2; // 释放 Heap1
    delete pc4; // 释放 Heap2

    // 显式销毁放置 new 创建的对象
    pc3->~JustTesting(); // 销毁 pc3 指向的对象
    pc1->~JustTesting(); // 销毁 pc1 指向的对象

    delete[] buffer; // 释放 buffer
    cout << "Done\n";

    return 0;
}
