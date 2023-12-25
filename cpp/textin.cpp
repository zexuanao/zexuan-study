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
    }

    cout << endl << count << " characters read\n";

    return 0;
}
