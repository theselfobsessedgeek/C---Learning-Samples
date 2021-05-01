#include<iostream> 

using namespace std;
string keyvalpair[]={".",".","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void keypad(int num,string output){
    if(num==0||num==1){
        cout<<output<<endl;
        return;
    }
    int currnum = num%10;
    for(int i = 0; i<keyvalpair[currnum].size();i++){
        keypad(num/10,keyvalpair[currnum].substr(i,1)+output);
    }
}

int main(){

    int input;
    string output;
    cin >> input;
    keypad(input,output);

    return 0;
}