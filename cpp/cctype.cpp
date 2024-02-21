#include <iostream>
#include <cctype>

// 字符函数的原型声明

int main() {
    using namespace std;

    cout << "输入要分析的文本，输入 '@' 结束输入。" << endl;
    char ch;
    int whitespace = 0;
    int digits = 0;
    int chars = 0;
    int punct = 0;
    int others = 0;

    cin.get(ch);
    while (ch != '@') {
        if (isalpha(ch)) {
            chars++;
        } else if (isspace(ch)) {
            whitespace++;
        } else if (isdigit(ch)) {
            digits++;
        } else if (ispunct(ch)) {
            punct++;
        } else {
            others++;
        }
        cin.get(ch); // 获取下一个字符
    }

    cout << "字母字符数：" << chars << endl;
    cout << "空白字符数：" << whitespace << endl;
    cout << "数字字符数：" << digits << endl;
    cout << "标点符号数：" << punct << endl;
    cout << "其他字符数：" << others << endl;

    return 0;
}
/*isalnum(): 检查字符是否是字母或数字（字母包括大小写字母），返回 true 或 false。

isalpha(): 检查字符是否是字母，返回 true 或 false。

iscntrl(): 检查字符是否是控制字符，返回 true 或 false。

isdigit(): 检查字符是否是数字（0 到 9），返回 true 或 false。

isgraph(): 检查字符是否是除空格之外的可打印字符，返回 true 或 false。

islower(): 检查字符是否是小写字母，返回 true 或 false。

isprint(): 检查字符是否是可打印字符（包括空格），返回 true 或 false。

ispunct(): 检查字符是否是标点符号，返回 true 或 false。

isspace(): 检查字符是否是空白字符（空格、进纸、换行符、回车、水平制表符或者垂直制表符），返回 true 或 false。

isupper(): 检查字符是否是大写字母，返回 true 或 false。

isxdigit(): 检查字符是否是十六进制数字（0 到 9、a 到 f 或 A 到 F），返回 true 或 false。

tolower(): 将字符转换为小写，如果字符是大写字母则返回对应的小写字母，否则返回原字符。

toupper(): 将字符转换为大写，如果字符是小写字母则返回对应的大写字母，否则返回原字符。

这些函数可以用于判断字符的类型，并进行相应的转换。在对字符类型进行判断时，它们返回一个非零值表示条件为真（true），否则返回零表示条件为假（false）。*/