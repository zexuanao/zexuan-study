#include<iostream>
int main()
{
    long *fellow;
    //*fellow=223323不能直接赋值,因为不知道地址在哪里,只是
    //定义了而已。
    fellow=(long*)malloc(sizeof(long));
    *fellow=223323;
    using namespace std;
    cout << *fellow;
    /*int * pt;
    pt=(int *)0xB8000000;
    *pt=3333;*/
    int * pt=new int;
    *pt=10;
    cout << endl <<pt <<endl << *pt; 
    delete pt;
}