#include<iostream> 
#include<sstream>
using namespace std;

/*
 * Complete the 'superDigit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */
int strtoNum(char c){
    int n;
    switch (c) {
    case '1':
    n=1;
    break;
    case '2':
    n = 2;
    break;
    case '3':
    n = 3;
    break;
    case '4':
    n= 4;
    break;
    case '5':
    n= 5;
    break;
    case '6':
    n = 6;
    break;
    case '7':
    n=7;
    break;
    case '8':
    n = 8;
    break;
    case '9':
    n = 9;
    break;
    case '0':
    n = 0;
    break;
    
    }
    return n;
}

string stringMaker(string n,int k){
    if (k==0) {
        return "";
    }
    return n+stringMaker(n, --k);
} 

// int SupDig(string n){
//     if(n.empty()){
//        return 0;
//    } 
//    string smallarString = n.substr(1);
//    return strtoNum(n[0])+SupDig(smallarString);
// }
int digsum(int m){
    int sum=0;
    while (m>0){
        sum += (m%10);
        m=m/10;
    }
    return sum;
}
int superDigit(string n, int k) {
   string p =stringMaker(n, k);
   int m;
   stringstream i(p);
   i >> m;
   cout << m<<endl;
   while (m>=10){
     m = digsum(m);  
   }
   return m;
}

int main(){
    int k;
    cin >> k;
    string n;
    cin >> n;
    int m = superDigit(n,k);   
    cout << m << endl;
    return 0;
}
