
#include<iostream>
enum class egg{small,medium,large};
enum struct t_shirt{small,midium,large};
int main(){
    egg choice=egg::large;
    t_shirt t=t_shirt::small;
    std::cout<<static_cast<int>(choice)<<std::endl
             <<static_cast<int>(t)<<std::endl;
    return 0;
}