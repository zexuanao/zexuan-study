// Using the second draft of the Time class
// 使用 Time 类的第二个草案

#include <iostream>
#include "mytime.h"

int main() {
    using std::cout;
    using std::endl;

    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;
    cout<<coding;
    /*cout << "planning time = ";
    planning.Show();
    cout << endl;

    cout << "coding time = ";
    coding.Show();
    cout << endl;

    cout << "fixing time = ";
    fixing.Show();
    cout << endl;

    total = coding + fixing; // operator notation
    cout << "coding + fixing = ";
    total.Show();
    cout << endl;

    Time morefixing(3, 28);
    cout << "more fixing time = ";
    morefixing.Show();
    cout << endl;

    total = morefixing.operator+(total); // function notation
    cout << "morefixing.operator+(total) = ";
    total.Show();
    cout << endl;
*/
    return 0;
}
