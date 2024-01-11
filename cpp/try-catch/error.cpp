#include <iostream>
#include <cmath> // 或 math.h，Unix 用户可能需要添加 -lm 标志
#include "exc_mean.h"

// 函数原型
double hmean(double a, double b);
double gmean(double a, double b);

int main() {
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Enter two numbers: ";
    while (cin >> x >> y) {
        try {
            // 开始 try 块
            z = hmean(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                 << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y
                 << " is " << gmean(x, y) << endl;
            cout << "Enter next set of numbers (<q> to quit): ";
            // 结束 try 块
        } catch (bad_hmean &bg) {
            // 开始 catch 块
            bg.mesg();
            cout << "Try again.\n";
            continue;
        } catch (bad_gmean &hg) {
            cout << hg.mesg() << endl;
            cout << "Values used: " << hg.v1 << ", " << hg.v2 << endl;
            cout << "Sorry, you don't get to play any more.\n";
            break;
        } // 结束 catch 块
    }

    cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b) {
    if (a == -b)
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) {
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);
    return std::sqrt(a * b);
}
