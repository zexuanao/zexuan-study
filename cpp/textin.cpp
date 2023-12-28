#include <iostream>

int main() {
    using namespace std;
    char ch;
    int count = 0;

    cout << "Enter characters; enter # to quit: " << endl;
    //cin >> ch;
    //cin.get(ch);
    //ch!=EOF也是可以的
    while (/*!cin.fail()*/cin.get(ch)) {
        // test the character
        cout << ch;
        ++count;

        // get the next character
        //cin >> ch;
        //普通的cin是scanf,忽略空格和换行符
        //cin.get则是getchar(),不会忽略换行符和空格
        //cin.get(ch);
        /*
在C++中，cin 对象会忽略空白字符（例如空格、制表符和换行符等）。
当你使用 cin >> 连续读取输入时，它会自动忽略之前的换行符并等待新的输入。
所以，当你连续使用两次 cin >> 操作时，第一个 cin >> 读取了你输入的内容，
并且忽略了之前的换行符。第二个 cin >> 会等待新的输入，而不会受到之前的换行符的影响。
这就是为什么在连续使用 cin >> 时不会遇到换行符导致的问题，
因为每次 cin >> 都会忽略掉之前的空白字符，包括换行符，然后等待新的输入。*/
    }

    cout << endl << count << " characters read\n";

    return 0;
}
