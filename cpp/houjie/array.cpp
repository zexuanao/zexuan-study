#include<iostream>
#include<array>
#include<cstdlib>
#include<ctime>
#include<string>
#define ASIZE 500000
using namespace std;
long get_a_target_long();
int compareLongs(const void*a,const void* b);
int main()
{   
    srand(time(NULL));
    cout<<"\ntest_array().........\n";
    array<long,ASIZE>c;
    clock_t timestart=clock();
    for(long i=0;i<ASIZE;++i)
    {
        c[i]=rand();
    }
    cout<<"m-second:"<<(clock()-timestart)<<endl;
    cout<<c.size()<<endl<<c.front()<<endl<<c.back()<<endl<<c.data()<<endl;
    long target=get_a_target_long();
    timestart=clock();
    qsort(c.data(),ASIZE,sizeof(long),compareLongs);
    long* pItem=(long*)bsearch(&target,c.data(),ASIZE,sizeof(long),compareLongs);
    cout<<"qsort+bsearch:"<<(clock()-timestart)<<endl;
    if(pItem!=NULL)
        cout<<"foud"<<*pItem<<endl;
    else   
        cout<<"not found"<<endl;
}

long get_a_target_long()
{
    long target=0;
    cout<<"target:";
    cin>>target;
    return target;

}
string get_a_target_string()
{
    string target;
    cin>>target;
    return target;
}
int compareLongs(const void*a,const void* b)
{
    return (*(long*)a-*(long*)b);
}