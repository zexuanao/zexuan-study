#include <iostream>
#include "tabtenn.h"

int main() {
    using std::cout;
    using std::endl;

    // 创建 TableTennisPlayer 和 RatedPlayer 类的对象
    TableTennisPlayer player1("Tara", "Boomdea", false);
    RatedPlayer rplayer1(1140, "Mallory", "Duck", true);

    // 使用派生类 RatedPlayer 对象的方法
    rplayer1.Name();
    if (rplayer1.HasTable()) {
        cout << ": has a table\n";
    } else {
        cout << ": hasn't a table.\n";
    }

    // 使用基类 TableTennisPlayer 对象的方法
    player1.Name();
    if (player1.HasTable()) {
        cout << ": has a table";
    } else {
        cout << ": hasn't a table.\n";
    }
    cout << endl;

    cout << "Name: ";
    rplayer1.Name();
    cout << "; Rating: " << rplayer1.Rating() << endl;

    // 使用基类 TableTennisPlayer 对象初始化 RatedPlayer 对象
    RatedPlayer rplayer2(1212, player1);
    cout << "Name: ";
    rplayer2.Name();
    cout << "; Rating: " << rplayer2.Rating() << endl;

    return 0;
}
