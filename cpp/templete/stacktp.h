#ifndef STACKTP_H
#define STACKTP_H

template <class Type>
class Stack {
private:
    enum { MAX = 101 }; // 类特有的常量
    Type items[MAX]; // 存储栈项
    int top; // 栈顶索引
public:
    Stack(); // 构造函数
    bool isempty(); // 检查栈是否为空
    bool isfull(); // 检查栈是否已满
    bool push(const Type & item); // 向栈中添加项
    bool pop(Type & item); // 弹出栈顶项到 item 中
};

template <class Type>
Stack<Type>::Stack() {
    top = 0;
}

template <class Type>
bool Stack<Type>::isempty() {
    return top == 0;
}

template <class Type>
bool Stack<Type>::isfull() {
    return top == MAX;
}

template <class Type>
bool Stack<Type>::push(const Type & item) {
    if (top < MAX) {
        items[top++] = item;
        return true;
    } else {
        return false;
    }
}

template <class Type>
bool Stack<Type>::pop(Type & item) {
    if (top > 0) {
        item = items[--top];
        return true;
    } else {
        return false;
    }
}

#endif
