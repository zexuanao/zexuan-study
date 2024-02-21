#include<iostream>
#ifndef STRNG_H_
#define STRNG_H_
class Stringbad
{
    private:
        char * str;
        int len;
        static int num_strings;
    public:
        Stringbad(const char *s);
        Stringbad();
        ~Stringbad();
        Stringbad(const Stringbad & st);
        //使Stringbad()=...不会出现问题
        Stringbad& operator=(const Stringbad&st);
        friend std::ostream & operator <<(std::ostream& os,const
                                            Stringbad & st);
};
#endif