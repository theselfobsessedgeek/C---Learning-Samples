#include<iostream> 

using namespace std;
long long digitalSum(string input){
    if (input.empty()){
        return 0;
    }
    return (input[0]-'0')+digitalSum(input.substr(1));
}
int superDigit(string n, int k) {
    int partialSum = digitalSum(n);
    int sum = k * partialSum;
    if (sum<10){
        return sum;
    }else{
        return superDigit(to_string(sum),1);
    }

}


int main(){

    
    

    return 0;
}