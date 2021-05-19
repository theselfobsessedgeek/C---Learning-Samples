#include<iostream> 
#include<string>
using namespace std;
void printPermutations(string input,string output=""){
    if(input.empty()){
        cout<<output<<endl;
        return ;
    }
    for (int i = 0; i < input.length(); i++){
        printPermutations(input.substr(0,i)+input.substr(i+1),output+input[i]);  
    }  
}

int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}