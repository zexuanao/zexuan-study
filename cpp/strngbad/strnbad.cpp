#include<cstring>
#include"strnbad.h"
int Stringbad::num_strings=0;
Stringbad::Stringbad(const char *s)
{
    len=std::strlen(s);
    str=new char[len+1];
    std::strcpy(str,s);
    num_strings++;
    std::cout<<num_strings<<":\""<<str  
            <<"\"object created";

}
Stringbad::Stringbad()
{
    len=4;
    str=new char[4];
    std::strcpy(str,"C++");
    num_strings++;
    std::cout<<num_strings<<"\""<<str
                    <<"\"dafault opject created\n";
    
}
Stringbad::~Stringbad()
{
    std::cout<<"\""<<str<<"\"object deleted,";
    --num_strings;
    std::cout<< num_strings<<"left\n";
    delete[] str;

}
std::ostream & operator <<(std::ostream& os,const Stringbad & st)
{
    os<<st.str;
    return os;
}
Stringbad::Stringbad(const Stringbad & st)
{   
    num_strings++;
    len=st.len;
    str=new char[len+1];
    std::strcpy(str,st.str);
    std::cout<< num_strings<<":\""<<str
    <<"\"object created\n";
}
Stringbad & Stringbad::operator=(const Stringbad & st)
{
    if(this==&st)
    return *this;
    delete[]str;
    len=st.len;
    str=new char [len+1];
    std::strcpy(str,st.str);
    return *this;
    
}