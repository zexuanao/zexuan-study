#include<vector>
using namespace std;
vector<int> vi;
int n=10;
vector<double>vd(n);
//vector<typeName>vt(n_elem)

#include<array>
using namespace std;
array<int,5>ai;
array<double,4>ad={1.2};
array<int,5>ao{3};
//array<typeName,n_elem>arr
#include<iostream>
int main()
{
    ai=ao;
    ai.at(1)=2;
    //at可以运行期间捕获非法索引
    using namespace std;
    cout<<ai[0]<<ai[1];
    //32
    cout.setf(ios_base::boolalpha);
    cout<<(ai[0]<3)<<endl;
    return 0;
}

