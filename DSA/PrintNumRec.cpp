#include<iostream>

using namespace std;

void print(int n){
    if(n == 1){
        cout << n << " ";
    }else{
        
        print(n - 1);
        cout << n << " ";
    }
 
    
}

int count(int n){
    if(n == 0){
        return 0;
    }else{
 		return count(n / 10)+1 ;       
    }
    
}

int main(int argc, char const *argv[])
{

    cout << count(21095);
    return 0;
}
