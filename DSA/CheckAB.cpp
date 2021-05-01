/*

    a. The string begins with an 'a'
    b. Each 'a' is followed by nothing or an 'a' or "bb"
    c. Each "bb" is followed by nothing or an 'a'
*/
#include<iostream> 

using namespace std;
bool auxFun(char input[],bool firstChar = true){
    
    if(firstChar&&input[0]=='a'){
        return auxFun(input+1,false);
    }

    if((!firstChar)&&(input[0]=='b'&&input[1]=='b'&&(input[2]=='a'||input[2]=='\0'))){
        return auxFun(input+2,firstChar);
    }
    if((!firstChar)&&(input[0]=='a')){
        return auxFun(input+1,firstChar);
    }
    if(input[0]=='\0'){
        return true;
    }
    return false;

}
bool checkAB(char input[]) {
    
    return auxFun(input);
} 
int main(){
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
        
    return 0;
}