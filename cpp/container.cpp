#include<iostream>
#include<array>
#include<cstdlib>
#include<ctime>
#include<string>

#define ASIZE 500000

using namespace std;
namespace np_array 
{
    void test_array();
    long get_a_target_long();
    int compareLongs(const void*a,const void* b);
}
namespace np_vector
{
    void test_vector(const long& value);
    string get_a_target_string();
}
namespace np_list
{
    void test_list();
} // namespace np_list




int main()
{   
    
    np_list::test_list();
    return 0;
}




namespace np_array
{
    void test_array()
    {
        srand(time(NULL));
        cout<<"\ntest_array().........\n";
    array<long,ASIZE> c;
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
    int compareLongs(const void*a,const void* b)
    {
        return (*(long*)a-*(long*)b);
    }
}
#include<vector>
#include<algorithm>
namespace np_vector
{
    void test_vector(const long& value)
    {
        srand(time(NULL));
        cout<<"\ntest_vector()......\n";
    vector<string>c;
    clock_t timestart=clock();
        for(long i=0;i<value;i++)
        {
            c.push_back(to_string(rand()));
        }
        cout<<"m-deconds:"<<clock()-timestart<<endl<<"size:"<<c.size()
            <<endl<<"front:"<<c.front()<<endl<<"back"<<c.back()<<endl<<"data"<<c.data()<<endl<<
            "capacity"<<c.capacity()<<endl;
    string target=get_a_target_string();
        timestart=clock();
    auto pItem=::find(c.begin(),c.end(),target);
        cout<<"::find(),m-s:"<<clock()-timestart<<endl;
        if(pItem!=c.end())
            cout<<"found "<<*pItem<<endl;
        else
            cout<<"not found"<<endl;
        
        timestart=clock();
        sort(c.begin(),c.end());
    string* pItem2=(string*)bsearch(&target,c.data(),c.size(),sizeof(string),[](const void* a, const void* b) -> int {
        return (*(string*)a).compare(*(string*)b);
    });
        cout <<"sort()+bsearch(),m-s:"<<(clock()-timestart)<<endl;
        if(pItem2 !=NULL)
            cout<<"found,"<<*pItem2<<endl;
        else
            cout<<"not found!"<<endl;

    }
    string get_a_target_string()
    {
    string target;
        cin>>target;
        return target;
    }
      
}
#include<list>
namespace np_list
{
    void test_list()
    {
        cout<<"\ntest_list()......\n";
    list<string>c;
    clock_t timestart=clock();
        srand(time(NULL));
        for(long i=0;i<ASIZE;i++)
            c.push_back(to_string(rand()));
        cout<<"m-s: "<<(clock()-timestart)<<endl<<"list.size:"<<c.size()<<endl<<"list.max_size:"<<c.max_size()
        <<endl<<"list.front"<<c.front()<<endl<<"list.back:"<<c.back()<<endl;
    string target=np_vector::get_a_target_string();
        timestart=clock();
    auto pItem=::find(c.begin(),c.end(),target);
        cout<<"::find m-s:"<<clock()-timestart<<endl;
        if (pItem != c.end())
        cout << "found " << *pItem << endl;
    else
        cout << "not found" << endl;
    }
}