#ifndef MYTIME1_H
#define MYTIME1_H
#include<iostream>
// Time class before operator overloading
// 运算符重载之前的 Time 类

class Time {
private:
    int hours;
    int minutes;

public:
    Time(); // 默认构造函数
    Time(int h, int m = 0); // 带参数的构造函数
    void AddMin(int m); // 将分钟增加
    void AddHr(int h); // 将小时增加
    void Reset(int h = 0, int m = 0); // 重置时间
    Time operator+(const Time &t)const; // 重载加法运算符
    void Show() const; // 显示时间信息
    friend void operator<<(std::ostream & os,const Time & t);
};

#endif
