#ifndef ARRAYTP_H
#define ARRAYTP_H

#include <iostream>
#include <cstdlib>

template <class T, int n>
class ArrayTP {
private:
    T ar[n];

public:
    ArrayTP();
    explicit ArrayTP(const T & v);
    virtual T & operator[](int i);
    virtual T operator[](int i) const;
};

template <class T, int n>
ArrayTP<T, n>::ArrayTP() {
    // 默认构造函数，将数组元素初始化为默认值（零值）
    for (int i = 0; i < n; i++)
        ar[i] = T();
}

template <class T, int n>
ArrayTP<T, n>::ArrayTP(const T & v) {
    // 将所有数组元素初始化为同一个值 v
    for (int i = 0; i < n; i++)
        ar[i] = v;
}

template <class T, int n>
T & ArrayTP<T, n>::operator[](int i) {
    // 重载 [] 运算符以访问数组元素（可写）
    if (i < 0 || i >= n) {
        std::cerr << "数组下标越界: " << i << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}

template <class T, int n>
T ArrayTP<T, n>::operator[](int i) const {
    // 重载 [] 运算符以访问数组元素（只读）
    if (i < 0 || i >= n) {
        std::cerr << "数组下标越界: " << i << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return ar[i];
}

#endif
