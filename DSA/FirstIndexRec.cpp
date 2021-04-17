#include<iostream> 

using namespace std;

int firstIndex(int input[], int size, int x,int pos=-1,int c=0) {
    if(size==0) return pos;
    if(input[0]==x) pos = c ;
    return firstIndex(input+1,size-1,x,pos,++c);
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
    
    cout << firstIndex(input, n, x) << endl;

    return 0;
}