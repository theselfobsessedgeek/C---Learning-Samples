#include<iostream> 

using namespace std;

int main(){
    int t;
    cin>>t;
    
    while (t>0){
        t--;
        int n;
        cin>>n;
        int arr[n];
        long long count=0, avg=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            avg+=arr[i];
        }
        avg/=n;
        for(int i=0;i<n;i++){
            if(arr[i]>avg) count++;
        }
        cout<<count<<endl;
    }
    return 0;
}