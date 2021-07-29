#include<bits/stdc++.h> 
#define ll long long
using namespace std;

int main(){
    ll n = 0,target = 0;
    cin>>n>>target;

    vector<ll> v;

    for(ll i = 0; i<n;i++) {
        ll k;
        cin>>k;
        v.push_back(k);
    }
    vector<ll> vorg = v;

    sort(v.begin(),v.end());

    ll i = 0,j= v.size()-1;
    bool found = false;
    while(i<j){
        ll sum = v.at(i)+v.at(j);
        if(sum==target){
            // cout<<v[i]<<" "<<v[j]<<endl;
            i  = v[i] ;
            j = v[j];
             found = true;
            break;
        }else if (sum<target){
            i++;
        }else if(sum>target){
            j--;
        }
    }
    v.clear();
    if(found){
        for(ll m  = 0; m<n;m++){
            if (vorg[m]==i) v.push_back(m+1);
            else if (vorg[m]==j)v.push_back(m+1);
        }
        cout<<v.at(0)<<" "<<v.at(1)<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    
    

    return 0;
}