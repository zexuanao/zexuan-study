#include<iostream>
#include<ctime>
int main()
{
    using namespace std;
    cout<<"Enter delay: ";
    float secs;
    cin >> secs;
    clock_t delay =secs*CLOCKS_PER_SEC;
    cout <<"starting\a\n";
    clock_t start=clock();
    while (clock()-start<delay)
    {
        /* code */;
    }
    cout <<"done \a\n";
    return 0;
    
}