#include<iostream> 
using namespace std;
#include "Student.cpp"


int main(){

    Student s1;
    Student s2(110);
    s1.setAge(24,123); 
    s1.rollNumber = 101;
  
    cout<<s1.getAge() << endl;
    
    s1.printDetails();
    return 0;
}