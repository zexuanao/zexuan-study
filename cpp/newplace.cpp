#include <iostream>
#include <new>

const int BUF = 512;
const int N = 5;
char buffer[BUF];

int main() {
    using namespace std;

    double *pdl, *pd2;

    cout << "Calling new and placement new:\n";

    // 在堆上使用 new
    pdl = new double[N];

    // 使用 buffer 数组
    pd2 = new (buffer) double[N];

    for (int i = 0; i < N; i++)
        pd2[i] = pdl[i] = 1000 + 20.0 * i;

    cout << "Memory addresses:\n  heap: " << pdl << "\n  static: " << static_cast<void *>(buffer) << endl;

    cout << "Memory contents:\n";
    for (int i = 0; i < N; i++)
        cout << pdl[i] << " at " << &pdl[i] << "; " << pd2[i] << " at " << &pd2[i] << endl;

    cout << "\nCalling new and placement new a second time:\n";

    double *pd3, *pd4;
    pd3 = new double[N];
    pd4 = new (buffer) double[N]; // 覆盖旧数据

    for (int i = 0; i < N; i++)
        pd4[i] = pd3[i] = 1000 + 40.0 * i;

    cout << "Memory contents:\n";
    for (int i = 0; i < N; i++)
        cout << pd3[i] << " at " << &pd3[i] << "; " << pd4[i] << " at " << &pd4[i] << endl;

    cout << "\nCalling new and placement new a third time:\n";

    delete[] pdl;

    pdl = new double[N];
    pd2 = new (buffer + N * sizeof(double)) double[N];

    for (int i = 0; i < N; i++)
        pd2[i] = pdl[i] = 1000 + 60.0 * i;

    cout << "Memory contents:\n";
    for (int i = 0; i < N; i++)
        cout << pdl[i] << " at " << &pdl[i] << "; " << pd2[i] << " at " << &pd2[i] << endl;

    delete[] pdl;
    delete[] pd3;

    return 0;
}
