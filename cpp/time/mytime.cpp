// implementing Time methods
// 实现 Time 类的方法

#include <iostream>
#include "mytime.h"

Time::Time() {
    hours = 0;
    minutes = 0;
}

Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}

void Time::AddMin(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h) {
    hours += h;
}

void Time::Reset(int h, int m) {
    hours = h;
    minutes = m;
}

Time Time::operator+(const Time &t) const {
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

void Time::Show() const {
    std::cout << "Hours: " << hours << ", Minutes: " << minutes << std::endl;
}

void operator<<(std::ostream & os,const Time & t)
{
    os<<t.hours<<" hours, "<<t.minutes<<" minutes";
}