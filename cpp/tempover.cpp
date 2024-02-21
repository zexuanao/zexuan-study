#include <iostream>

template <typename T>
void ShowArray(T arr[], int n);

/*template <typename T>
void ShowArray(T * arr[], int n);
*/
template <typename T>
struct debts {
    char name[50];
    T amount;
};

int main() {
    using namespace std;
    int things[6] = {13, 31, 103, 301, 310, 1301};
    struct debts<double> mrE[3] = {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.01},
        {"Iby Stout", 1800.0}
    };

    double * pd[3];
    for (int i = 0; i < 3; i++)
        pd[i] = &mrE[i].amount;

    cout << "Listing Mr. E's counts of things: \n";
    ShowArray(things, 6); // 使用模板 A
    cout << "Listing Mr. E's debts:\n";
    ShowArray(pd, 3); // 使用模板 B（更加特化）
    return 0;
}

template <typename T>
void ShowArray(T arr[], int n) {
    using namespace std;
    cout << "template A\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

/*template <typename T>
void ShowArray(T * arr[], int n) {
    using namespace std;
    cout << "template B\n";
    for (int i = 0; i < n; i++)
        cout << *arr[i] << ' ';
    cout << endl;
}*/

//这里用的都是void函数，如果要返回T a+T b的话不知道具体的
//返回值是什么类型，所以可以
/*
templaie<class T1,class T2>
aotu gt(T1 x,T2 y)->delltype(x+y)
{
    ...
    return x+y;
}
*/
