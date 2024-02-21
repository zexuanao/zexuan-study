#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int LIMIT = 5;

// 函数定义：将焦距和目镜数组写入给定的输出流
void file_it(ostream &os, const double fo, const double fe[], int n);

int main() {
    ofstream fout;
    const char *fn = "rep-data.txt";
    fout.open(fn);

    if (!fout.is_open()) {
        cout << "Can't open file " << fn << ", Bye.\n";
        exit(EXIT_FAILURE);
    }

    double objective;
    cout << "Enter the focal length of your telescope objective in mm: ";
    cin >> objective;

    double eps[LIMIT];
    cout << "Enter the focal lengths, in mm, of " << LIMIT << " eyepieces:\n";
    for (int i = 0; i < LIMIT; i++) {
        cout << "Eyepiece #" << i + 1 << ": ";
        cin >> eps[i];
    }

    file_it(fout, objective, eps, LIMIT);
    file_it(cout, objective, eps, LIMIT);

    cout << "Done.\n";
    return 0;
}

// 函数定义：将焦距和目镜数组写入给定的输出流
void file_it(ostream &os, const double fo, const double fe[], int n) {
    ios_base::fmtflags initial;
    initial = os.setf(ios_base::fixed); // 保存初始的格式化状态
    os.precision(0);
    os << "Focal length of objective: " << fo << " mm\n";
    os.setf(ios::showpoint);
    os.precision(1);
    os.width(12);
    os << "f.l. eyepiece";
    os.width(15);
    os << "magnification\n";

    for (int i = 0; i < n; i++) {
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int(fo / fe[i] + 0.5) << endl;
    }

    os.setf(initial); // 恢复初始的格式化状态
}
