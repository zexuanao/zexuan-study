#include<iostream>
struct inflatable
{   
    char name[20];
    float volume;
    double price;
    
    /* data */
};

int main()
{
    int *psome=new int [10];
    //data
    
    char* ps=new char [20];
    ps="fox";
    std::cout<<ps<<" at "<<(int * )ps<<"  dizhi "<<&ps<<std::endl;
    psome[0]=1;
    std::cout<<psome<<" at "<<(int *)psome<<"  dizhi "<<&psome<<std::endl;
    //如果cout接收到char*类型，那么会自动输出到\0为止
    inflatable *pi= new inflatable;
    std::cin.get(pi->name,20);
    std::cout<<pi->name<<std::endl;
    
    
    
    
    delete [] ps;
    delete [] psome;
    //[]不可省略
}  