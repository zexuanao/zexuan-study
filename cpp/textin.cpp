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
/*std::getline() 函数读取输入流中的一行文本，并将其中的换行符之前的内容存储到指定的字符串中，然后将换行符从输入流中移除。

即使你在第一个 getline() 后输入了回车字符（换行符），它会被 getline() 函数读取并从输入流中移除。所以在后续调用的 getline() 函数中，回车字符已经不再输入流中，因此它会等待用户输入新的非空行内容，不会被之前的回车字符影响。

换句话说，每次调用 getline() 都会从输入流中读取一行文本，即使之前输入的内容包含了换行符或回车符，它也不会对后续的 getline() 造成影响，因为它们会从输入流中读取新的一行文本。






*/