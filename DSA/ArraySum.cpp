#include<iostream> 

using namespace std;

int sum(int input[],int n){
    if(n==1) return input[0];
    return input[0]+sum(input+1,n-1);
}

int main(){

    int testcase1[]={1,2,3,4,5,6,7,8};
    
    cout << sum(testcase1,8)<<endl;

    return 0;
}