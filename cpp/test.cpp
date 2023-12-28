#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const int SIZE =5;
void display(const string sa[],int n);
double cube(double a);
double refcube (double &ra);
void left(const char*,int n=1);
int main()
{   
    char str[SIZE]="niha";
    left(str);
    left(str,2);
    return 0;
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