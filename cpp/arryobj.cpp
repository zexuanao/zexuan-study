#include <iostream>
#include <array>
#include <string>

// 季节数
const int Seasons = 4;

// 季节名称数组
const std::array<std::string, Seasons> Snames = {
    "Spring", "Summer", "Fall", "Winter"
};

// 填充数组的函数
void fill(std::array<double, Seasons> *pa);

// 显示数组内容的函数
void show(std::array<double, Seasons> da);

int main() {
    std::array<double, Seasons> expenses;
    fill(&expenses);
    show(expenses);
    return 0;
}

// 填充数组的函数实现
void fill(std::array<double, Seasons> *pa) {
    using namespace std;
    for (int i = 0; i < Seasons; ++i) {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> (*pa)[i];
    }
}

// 显示数组内容的函数实现
void show(std::array<double, Seasons> da) {
    using namespace std;
    double total = 0.0;
    
    cout << "\n\nEXPENSES\n";
    for (int i = 0; i < Seasons; ++i) {
        cout << Snames[i] << ": $" << da[i] << endl;
        total += da[i];
    }
    
    cout << "\nTotal Expenses: $" << total << endl;
}

