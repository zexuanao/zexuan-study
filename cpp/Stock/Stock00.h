#ifndef STOCK00_H_
#define STOCK00_H_
#include<string>
class Stock
{
    private:
        std::string company;
        int shares;
        double share_val;
        double total_val;
        void set_tot(){total_val=shares*share_val;}
        //默认是内联函数也可以在外面使用inline定义函数
    public:
        Stock(const std::string & co, long n, double pr);
        Stock();
        ~Stock();
        void buy(int num,double price);
        void sell(int num,double price);
        void update(double price);
        void show() const;
        const Stock & topval(const Stock& s)const;
        //也可以 Stock(const std::string & co=“no name", long n=0, double pr=0);
};
#endif