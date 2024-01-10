#ifndef BRASS_H
#define BRASS_H

#include <string>

// Brass Account Class
class Brass {
private:
    std::string fullName;
    long acctNum;
    double balance;

public:
    Brass(const std::string &s = "Nullbody", long an = -1, double bal = 0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt);
    double Balance() const;
    virtual void ViewAcct() const;
    virtual ~Brass(){};
};

// Brass Plus Account Class
class BrassPlus : public Brass {
private:
    double maxLoan;
    double rate;
    double owesBank;

public:
    BrassPlus(const std::string &s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.11125);
    BrassPlus(const Brass &ba, double ml = 500, double r = 0.11125);
    virtual void ViewAcct() const;
    virtual void Withdraw(double amt);
    void ResetMax(double m) { maxLoan = m; }
    void ResetRate(double r) { rate = r; }
    void ResetOwes() { owesBank = 0; }
};

#endif
/*
Brass dom("Dominic Banker", 11224, 4183.45);
BrassPlus dot("Dorothy Banker", 12118, 2592.00);
Brass& bl_ref = dom;
Brass& b2_ref = dot;

bl_ref.ViewAcct();  // 调用 Brass::ViewAcct() 或其派生类版本
b2_ref.ViewAcct();  // 调用 BrassPlus::ViewAcct() 

*/