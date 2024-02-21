#include <iostream>
#include "stonewt.h"
using std::cout;

// 从双精度浮点数值构造 Stonewt 对象
Stonewt::Stonewt(double lbs) {
    stone = int(lbs) / Lbs_per_stn; // 整数除法
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}
//将double转换成stonewt类型
// 从石数和磅数构造 Stonewt 对象
Stonewt::Stonewt(int stn, double lbs) {
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

// 默认构造函数
Stonewt::Stonewt() {
    stone = pounds = pds_left = 0;
}

// 析构函数
Stonewt::~Stonewt() {
}

// 以石为单位显示重量
void Stonewt::show_stn() const {
    cout << stone << " stone, " << pds_left << " pounds\n";
}

// 以磅为单位显示重量
void Stonewt::show_lbs() const {
    cout << pounds << " pounds\n";
}

// 类型转换函数：转换为整数
Stonewt::operator int() const {
    return int(pounds + 0.5);
}

// 类型转换函数：转换为双精度浮点数
Stonewt::operator double() const {
    return pounds;
}
//从stonewt转换成double或int。explicit 可以禁止函数用于
//隐式转换
