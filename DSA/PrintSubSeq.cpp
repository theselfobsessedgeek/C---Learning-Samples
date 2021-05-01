#include<iostream> 

using namespace std;
void subseq(string input,string output){
    if(input.empty()){

        cout<< output<<endl;
        return;
    }
    subseq(input.substr(1),output);
    subseq(input.substr(1),output+input.substr(0,1));
}
int main(){

    string input;
    string output;
    cin >> input;
    subseq(input,output);

    return 0;
}