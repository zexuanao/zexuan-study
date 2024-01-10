#include "tabtenn.h"
#include <iostream>

// TableTennisPlayer类的构造函数实现
TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool ht)
    : firstname(fn), lastname(ln), hasTable(ht) {}

// TableTennisPlayer类的Name方法实现
void TableTennisPlayer::Name() const {
    std::cout << lastname << ", " << firstname;
}

// RatedPlayer类的带参数构造函数实现
RatedPlayer::RatedPlayer(unsigned int r, const string &fn, const string &ln, bool ht)
    : TableTennisPlayer(fn, ln, ht), rating(r) {}

// RatedPlayer类的拷贝构造函数实现
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp)
    : TableTennisPlayer(tp), rating(r) {}
