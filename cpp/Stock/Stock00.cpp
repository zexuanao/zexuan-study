// stock00.cpp

#include <iostream>
#include "stock00.h"

void Stock::buy(int num, double price) {
    if (num <= 0) {
        std::cout << "购买的股票数量不能为负数。\n交易被取消。\n";
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(int num, double price) {
    using std::cout;
    if (num < 0) {
        cout << "卖出的股票数量不能为负数。\n交易被取消。\n";
    } else if (num > shares) {
        cout << "您不能卖出超过所拥有的股票数量！\n交易被取消。\n";
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price) {
    share_val = price;
    set_tot();
}

void Stock::show()  const{
    std::cout << "公司：" << company << "\n";
    std::cout << "股票数量：" << shares << "股\n";
    std::cout << "股票价格：$" << share_val << "\n";
    std::cout << "总价值：$" << total_val << "\n";
}

Stock::Stock(const std::string & co, long n, double pr)
{
    company = co;
    if (n < 0) {
        std::cout << "股票数量不能为负数；股票数量设为0。\n";
        shares = 0;
    } else {
        shares = n;
    }
    share_val = pr;
    set_tot();
}
Stock::Stock()
{
    company="no name";
    shares=0;
    share_val=0.0;
    total_val=0.0;
}
Stock::~Stock()
{
    //std::cout<<"Bye<"<<company<<"!\n";
}

const Stock & Stock::topval(const Stock& s)const
{
    if(s.total_val>total_val)
        return s;
    else
        return *this;
}