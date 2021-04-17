#include<iostream> 
#include<string.h>

using namespace std;

bool checkNumber(int input[], int size, int x) {
    if (input[0]!=x&&size==1) return false;
    if(input[0]==x) return true;
    return checkNumber(input+1,size-1,x);
}

int main(){
    
     int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    if(checkNumber(input, n, x)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}