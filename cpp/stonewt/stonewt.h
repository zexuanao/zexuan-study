#ifndef STONEWT1_H
#define STONEWT1_H

class Stonewt {
private:
    enum { Lbs_per_stn = 14 }; // 每石的磅数
    int stone; // 整数石数
    double pds_left; // 除去整数石数后的小数磅数
    double pounds; // 总磅数

public:
    Stonewt(double lbs); // 通过磅数构造
    Stonewt(int stn, double lbs); // 通过石数和磅数构造
    Stonewt(); // 默认构造函数
    ~Stonewt();
    void show_lbs() const; // 以磅为单位显示重量
    void show_stn() const; // 以石为单位显示重量
    // 转换函数
    operator int() const; // 转换为整数
    operator double() const; // 转换为双精度浮点数
};

#endif
