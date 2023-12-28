#include<fstream>
#include<iostream>
#include<cstdlib>
int main()
{
    using namespace std;
    ifstream inFile;
    char filename[20];
    cin>>filename;
    inFile.open(filename);
    if(!inFile.is_open())
        exit(EXIT_FAILURE);
    char ch;
    string line;
    while (inFile.get(ch)) {
        line += ch;
    }
    if(inFile.eof())
    cout<<"End of file reached.\n";
    else if(inFile.fail())
    cout<<"Input terminated by data masmatch.\n";
    else
    cout<<"unknown reason.\n";
    cout<<line;
    inFile.close();
    return 0;
}