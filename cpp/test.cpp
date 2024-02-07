#include<iostream>

void print(){}

template<typename T,typename... Types>
void print(const T& firstArg,const Types&... args)
{
    cout << firstArg<<endl;
    print(args...);
}
int main()
{
    std::cout<< __cplusplus;
    print(7.5,"hello",42);
}