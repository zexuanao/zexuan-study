#include<fstream>

#include<string>

#include<cstdlib>

#include<iostream>

int main()

{

using namespace std;

std::ofstream fout("test.txt",ios::out|ios::app);

if(!fout.is_open())

{

cerr<<"can't open"<<"test.txt";

exit(EXIT_FAILURE);

}

string name;

while(getline(cin,name)&&(name.size()>0))

{

fout<<name<<std::endl;

}

fout.close();

return 0;

}


