#include<bits/stdc++.h> 
#define ll long long
#define vi vector<long long>
using namespace std;
ll largest(ll n){
    vi v;
    while(n!=0){
       v.push_back(n%10);
       n/=10; 
    }
    sort(v.begin(),v.end(),greater<ll>());

    return v.front();
}
int main(){
    ll n = 0,steps=0;
    cin>>n;

    while(n>0){
        n = n-largest(n);
        steps++;
    }

    cout<<steps<<endl;


    return 0;
}