#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
    int ia[6]={27,210,12,10,109,83};
    vector<int,allocator<int>>vi(ia,ia+6);
    //vector是容器,aalocator是分配器

    cout<< count_if(vi.begin(),vi.end(),not1(bind2nd(less<int>(),40)));
    //cout_if是算法,not1和bind2nd都是函数适配器,less是仿函数
    return 0;
}