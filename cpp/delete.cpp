#include<iostream>
#include<cstring>
using namespace std;
char*getname(void);
int main()
{
    char *name;
    name=getname();
    cout<<name<<" at "<<(int *)name<<endl<<sizeof(name)<<endl;
    delete[] name;
    //虽然new的是pn，但是这里name=pn，指向了同一个地方，那么
    //delete就会释放那个地方的内存。
    /*
    name=getname();
    cout<<name<<" at "<<(int *)name<<endl;
    delete[]name;
    return 0;
    */

}
char*getname()
{
    char temp[80];
    cout << "Enter name";
    cin>>temp;
    char*pn=new char[strlen(temp)+1];
    strncpy(pn,temp,strlen(temp));
    pn[strlen(temp)]='\0';
    cout<<"strlen(temp)+1 :"<<strlen(temp)+1<<endl;
    cout<<"temp size: "<<sizeof(temp)<<endl;
    cout<<"pn size: "<<sizeof(pn)<<endl;
    //注意，这里是指针的大小，而不是内部内容的大小，
    //指针大小一般都是8byte
    return pn;

}