#include <iostream>
using namespace std;

int main() {
    int n,temp,i;
    cout<<"Enter the number of numbers to be compared ";
    cin >>n ;
    int *p = new int[n];
    
    for (i = 0; i<n;i++){
        cin >> p[i];
    }
    temp = p[0];
    
    for(i =  0; i<n ; i++){
        temp = (temp < p[i])?  p[i]: temp;
    }
    
    cout << "\n The largest number is "<<temp<<endl;
    
    return 0;
}
