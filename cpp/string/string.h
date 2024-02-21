#ifndef STRING1_H
#define STRING1_H

#include <iostream>
using std::ostream;
using std::istream;

class String {
private:
    char* str;    // 指向字符串的指针
    int len;      // 字符串长度
    static int num_strings;  // 对象数量
    static const int CINLIM = 80;  // cin 输入限制

public:
    // 构造函数和其他方法
    String(const char* s);  // 构造函数
    String();
    String(const String&);  // 拷贝构造函数
    ~String();  // 析构函数
    int length() const{return len;};  // 返回字符串长度

    // 重载运算符方法
    String& operator=(const String&);
    String& operator=(const char*);
    char& operator[](int);
    const char& operator[](int) const;

    // 友元重载运算符
    friend bool operator<(const String& st1, const String& st2);
    friend bool operator>(const String& st1, const String& st2);
    friend bool operator==(const String& st1, const String& st2);
    friend ostream& operator<<(ostream& os, const String& st);
    friend istream& operator>>(istream& is, String& st);

    // 静态函数
    static int HowMany();
};

#endif
