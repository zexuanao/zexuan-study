#include<iostream>
struct structur
{   
    int year;
    /* data */
};

main()
{
    structur s01,s02,s03;
    s01.year=1998;
    structur * pa=&s02;
    pa->year=1999;
    structur trio[3];
    trio[0].year=2003;
    (trio+1)->year=2004;
    const structur *arp[3]={&s01,&s02,&s03};
    std::cout<<arp[1]->year<<std::endl;
    const structur **ppa=arp;
    auto ppb=arp;
    //cpp新特性，可以自动识别类型，并自动补全
    std::cout<<(*ppa)->year<<std::endl;
}
