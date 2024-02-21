// brass.cpp
// 银行账户类的方法

#include <iostream>
#include "brass.h"

using std::cout;
using std::endl;
using std::string;

// 格式化相关
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;

format setFormat();
void restore(format f, precis p);

// Brass 类的方法
Brass::Brass(const string & s, long an, double bal)
    : fullName(s), acctNum(an), balance(bal) {
}

void Brass::Deposit(double amt) {
    if (amt < 0)
        cout << "Negative deposit not allowed.\n"
             << "Deposit is cancelled.\n";
    else
        balance += amt;
}

void Brass::Withdraw(double amt) {
    format initialState = setFormat();
    precis prec = cout.precision(2);

    if (amt < 0)
        cout << "Withdrawal amount must be positive.\n"
             << "Withdrawal cancelled.\n";
    else if (amt <= balance)
        balance -= amt;
    else
        cout << "Withdrawal amount of $" << amt
             << " exceeds your balance.\n"
             << "Withdrawal cancelled.\n";
    restore(initialState, prec);
}

double Brass::Balance() const {
    return balance;
}

void Brass::ViewAcct() const {
    format initialState = setFormat();
    precis prec = cout.precision(2);

    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;

    restore(initialState, prec); // 恢复原始格式
}

// BrassPlus 类的方法
BrassPlus::BrassPlus(const string & s, long an, double bal,
                     double ml, double rl)
    : Brass(s, an, bal), maxLoan(ml), owesBank(0.0), rate(rl) {
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double rl)
    : Brass(ba), maxLoan(ml), owesBank(0.0), rate(rl) {
    // 使用隐式拷贝构造函数
}

void BrassPlus::ViewAcct() const {
    format initialState = setFormat();
    precis prec = cout.precision(2);

    Brass::ViewAcct(); // 显示基类部分
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3); // 格式化为小数点后三位
    cout << "Loan Rate: " << 100 * rate << "%\n";

    restore(initialState, prec);
}

void BrassPlus::Withdraw(double amt) {
    format initialState = setFormat();
    precis prec = cout.precision(2);

    double bal = Balance();
    if (amt <= bal)
        Brass::Withdraw(amt);
    else if (amt <= bal + maxLoan - owesBank) {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    } else {
        cout << "Credit limit exceeded. Transaction cancelled.\n";
    }
    restore(initialState, prec);
}

format setFormat() {
    // 设置为 ###.## 格式
    return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p) {
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}
