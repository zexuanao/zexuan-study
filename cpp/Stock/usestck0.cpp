#include <iostream>
#include "stock00.h"

int main() {
    Stock arg[4]={
        Stock("NanoSmart", 20, 12.50),
        Stock("hellokitty",30,13),
        Stock(),
        Stock()
    };
    Stock top;
    top=arg[0].topval(arg[1]);
    top.show();
    Stock fluffy_the_cat("NanoSmart", 20, 12.50);
     // 创建一个名为 fluffy_the_cat 的 Stock 对象
    //fluffy_the_cat.show(); // 显示初始股票信息

    // 进行购买股票的交易并展示交易后的信息
    fluffy_the_cat.buy(15, 18.125);
    //fluffy_the_cat.show();

    // 进行卖出股票的交易并展示交易后的信息
    fluffy_the_cat.sell(400, 20.00);
    //fluffy_the_cat.show();

    // 尝试购买股票数量过多的交易，展示信息
    fluffy_the_cat.buy(300000, 40.125);
    //fluffy_the_cat.show();

    // 尝试卖出股票数量超过持有数量的交易，展示信息
    fluffy_the_cat.sell(300000, 0.125);
    //fluffy_the_cat.show();
    Stock test_cat;
    //test_cat.show();
    const Stock land=Stock("hellokitty",0,0);
    //land.show();
    return 0;
}
