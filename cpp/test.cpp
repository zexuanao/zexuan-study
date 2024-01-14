#include<iostream>
#include<fstream>
#include<string>
#include<memory>
using namespace std;
const int SIZE =5;
void display(const string sa[],int n);
double cube(double a);
double refcube (double &ra);
void left(const char*,int n=1);
int main()
{   
    using namespace std;
    string *pu0=new string ("nihao");
    unique_ptr<string>pu1(new string ("HI ho!"));
    shared_ptr<string>pu2(pu1);
    shared_ptr<string>pu3(new string ("nihao"));
    pu2=pu3;
    cout<<*pu0;
    cout<<*pu1;
    cout<<*pu2;
    cout<<*pu3;
    delete pu0;

}
void display(const string sa[],int n)
{
    for(int i=0;i<n;i++)
    cout <<i+1<<":"<<sa[i]<<endl;
}
double refcube(double &ra)
{
    ra*=ra*ra;
    return ra;
}
void left(const char* str,int n)
{
    cout<<str[n]<<endl;
}