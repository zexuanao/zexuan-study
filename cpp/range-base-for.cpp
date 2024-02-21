#include<iostream>
double prices[5]{4.33,4.55,6.66,7.66,5.44};
using namespace std;

int main()
{
    
    for(double x:prices)
    {
        cout << x << endl;
    }
    int i=0;
    for (double &x:prices)
    {
        x=x*0.8;
        cout<<prices[i++]<<endl;
    }
    for(int x:{3,5,2,8,6})
        cout<<x<<"";
    cout <<'\n';
    return 0;

}