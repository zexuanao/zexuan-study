#include <iostream>
#include <string>

// 函数版本1：接收两个常量引用字符串，将它们连接起来并返回一个新的字符串
std::string version1(const std::string &s1, const std::string &s2);

// 函数版本2：接收一个字符串引用和一个常量字符串，将第二个字符串连接到第一个字符串的末尾，并返回第一个字符串的引用
const std::string &version2(std::string &s1, const std::string &s2); // 具有副作用

// 函数版本3：接收一个字符串引用和一个常量字符串，将这两个字符串连接起来，但是返回了一个对局部变量的引用，不安全
std::string &version3(std::string &s1, const std::string &s2); // 设计不良

int main() {
    std::string input;
    std::string copy;
    std::string result;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
    copy = input;

    std::cout << "Your string as entered: " << input << std::endl;

    result = version1(input, "***");
    std::cout << "Your string enhanced: " << result << std::endl;
    std::cout << "Your original string: " << input << std::endl;

    result = version2(input, "###");
    std::cout << "Your string enhanced: " << result << std::endl;
    std::cout << "Your original string: " << input << std::endl;

    std::cout << "Resetting original string." << std::endl;
    input = copy;

    result = version3(input, "@@@");
    std::cout << "Your string enhanced: " << result << std::endl;
    std::cout << "Your original string: " << input << std::endl;

    return 0;
}

std::string version1(const std::string &s1, const std::string &s2) {
    std::string temp;
    temp = s2 + s1 + s2;
    return temp;
}

const std::string &version2(std::string &s1, const std::string &s2) {
    // 具有副作用
    s1 = s2 + s1 + s2; // 安全返回对s1的引用，因为它是传递给函数的并且可以返回
    return s1;
}

std::string &version3(std::string &s1, const std::string &s2) {
    // 设计不良
    std::string temp;
    temp = s2 + s1 + s2; // 不安全地返回了对局部变量temp的引用
    return temp;
}
