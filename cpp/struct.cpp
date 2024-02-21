#include<iostream>
struct inflatable
{
    /* data */
    char name[20];
    float volume;
    double price;
    union 
    {
        long id_num;
        char id_char[20];
        /* data */
    };
    
};
enum specture {red,orange,yellow,green,blue,violet};
inflatable hat;
//可以省略struct,不用typedef了
int main() {
    using namespace std;
    inflatable duck {"Daphne",0.12,9.98};
    inflatable myyor;
    inflatable arry[20];
    arry[0]={"Daphne",0.12,9.98};
    int i=arry[0].volume;
    //不可以直接使用*arry.volume 因为arry的第一个成员不是单纯的
    //一个名称，而是一整个结构。
    // Initializing structure variables
    inflatable guest = {"Glorious Gloria", 1.88, 29.99};
    inflatable pal = {"Audacious Arthur", 3.12, 32.99};

    // Printing the name member of the guest variable
    cout << "Guest's name: " << guest.name << endl;

    // Printing the name member of the pal variable
    cout << "Pal's name: " << pal.name << endl;

    // Calculating and printing the total price of guest and pal
    cout << "You can have both for $" << guest.price + pal.price << "!" << endl;
    cout << "please put in duck's id _num\n";
    cin >> duck.id_num;
    //共用体(union)是匿名的所以id_num和id_char被视为duck的两个成员
    int color=blue;
    color=3+red;
    //enum是整形,可以自动提升为int,但int不能自动转换为
    //枚举类型
    return 0;
}
