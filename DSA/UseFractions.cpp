#include<iostream> 
#include"Fractions.cpp"
using namespace std;

int main(){

   Fractions f1(2,3);
   Fractions f2(4,3);
   Fractions f3 = f1+f2;
   
    cout<<f3.getNum()<<"/"<<f3.getDen()<<endl;

    return 0;
}