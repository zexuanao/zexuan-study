#include<iostream>
template <typename T>
void Swap(T &a,T &b);
 int main()
 {
    using namespace std;
    int i=10;
    int j=20;
    cout << "i,j = "<<i<<", "<<j<<".\n";
    cout<<"Using compiler-gen...\n";
    Swap(i,j);
    cout << i <<j <<endl;
    double a=1.0;
    double b=2.0;
    cout <<a<<b<<endl;
    Swap(a,b);
    cout <<a<<b<<endl;
    return 0;

 }
template <typename T>
void Swap(T &a,T &b)
{
    T temp;
    temp=a;
    a=b;
    b=temp;
    
}