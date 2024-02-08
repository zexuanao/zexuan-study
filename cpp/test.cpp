#include<iostream>



int main()
{
    std::cout<< __cplusplus;
    print(7.5,"hello",42);
}
void print(){}

template<typename T,typename... Types>
void print(const T& firstArg,const Types&... args)
{
    std::cout << firstArg<<std::endl;
    print(args...);
}