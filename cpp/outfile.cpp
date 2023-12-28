#include <iostream>
#include <fstream>

int main() {
    using namespace std;
    char automobile[50];
    int year;
    double a_price;
    double d_price;
    ofstream outFile;
    outFile.open("carinfo.txt");

    // 提示用户输入车辆信息
    cout << "请输入汽车的品牌和型号: " << endl;
    cin.getline(automobile, 50);

    // 输入车辆的型号年份和原始价格
    cout << "请输入车辆的型号年份: ";
    cin >> year;

    cout << "请输入车辆的原始价格: ";
    cin >> a_price;

    // 计算现在的价格
    d_price = 0.913 * a_price;

    // 在屏幕上显示信息
    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout << "品牌和型号: " << automobile << endl;
    cout << "型号年份: " << year << endl;
    cout << "原始价格: " << a_price << endl;
    cout << "现在价格: " << d_price << endl;

    // 使用 outFile 输出相同的信息
    outFile << fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile << "品牌和型号: " << automobile << endl;
    outFile << "型号年份: " << year << endl;
    outFile << "原始价格: " << a_price << endl;
    outFile << "现在价格: " << d_price << endl;

    outFile.close(); // 关闭文件
    return 0;
}
