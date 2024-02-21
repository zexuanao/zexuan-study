//类与其他类的互相转换问题
#include <iostream>
#include "stonewt.h"

int main() {
    using std::cout;
    Stonewt poppins(9, 2.8); // 9 stone, 2.8 pounds

    // 隐式转换
    double p_wt = poppins;
    cout << "Convert to double => ";
    cout << "Poppins: " << p_wt << " pounds.\n";

    cout << "Convert to int => ";
    cout << "Poppins: " << int(poppins) << " pounds.\n";

    return 0;
}
