#include<stdio.h>
class Fruit
{
public:
    virtual void peel(/* args */){
        printf("peel base fruit\n"); 
    };
    
};
class Apple:Fruit
{
    public:
    void peel(){
            printf("peel apple\n");   
    };

};
int main(){
Fruit banana;
banana.peel();
Apple apple;
apple.peel();
}