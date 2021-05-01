#include<iostream> 
#include <math.h>

using namespace std;

int subseq(string input, string output[]){
    if(input.empty()){
        output[0] = "";
        return 1;
    }
    string smallString = input.substr(1);
    int SizeofArr = subseq(smallString,output);
    for (int i = 0 ; i<SizeofArr;i++){
        output[i+SizeofArr]=input[0]+output[i];
    }
    return 2*SizeofArr;

}

int main(){

    string input;
    cin >> input;

    int n = pow(2,input.size());
    string* output= new string[n];
    int len = subseq(input,output);
    for(int i = 0;i<len;i++){
        cout << output[i] <<endl;
    }

    return 0;
}