#include<iostream>
#include<fstream>
int main()
{   
    using namespace std;
    ofstream outFile;
    char filename[50];
    cin>>filename;
    outFile.open(filename);
    char line[81];
    while(!(cin.get()=='\n'))
    continue;
    cout<<"please input : ";
    cin.getline(line,50);
    outFile<<line<<endl;
    outFile.close();
    return 0;

}
