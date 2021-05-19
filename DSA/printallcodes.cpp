#include <iostream>
#include <string.h>

using namespace std;
int toNum(string val){
    int num = 0;
    if(val.length()==1){
        num = val[0]-'0';
    }
    if(val.length()==2){
        int tens = (val[0]-'0')*10;
        int ones = (val[1]-'0');
        num = tens+ones;
    }
    return num;
}
char toChar(int num){
    return num+'a'-1;
}

void printAllPossibleCodes(string input,string output="") {
    if(input.empty()){
		cout<<output<<endl;
        return;
    }
    
    printAllPossibleCodes(input.substr(1),output+toChar(toNum(input.substr(0,1))));
    if(input.size()>1){
        if(toNum(input.substr(0,2))<27&&toNum(input.substr(0,2))>=10){
            
            printAllPossibleCodes(input.substr(2),output+toChar(toNum(input.substr(0,2))));
        }
    }
}


int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
