//theselfobsessedgeek'S CODE
// #include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


#define ff                first
#define ss                second
#define int        	  long long
#define ll                long long
#define ddouble           long double  
#define pb 		  push_back
#define mp 		  make_pair
#define pii               pair<int , int>
#define vi                vector<int>
#define mii               map<int,int>
#define gsort             greater<int>
#define pqb               priority_queue<int>
#define pqs               priority_queue<int , vi , greater<int>>
#define setbits(x)        __builtin_popcountll(x)
#define zrobits(x)        __builtin_ctzll(x)
#define mod               1000000007
#define mod1              mod
#define mod2              1000000009
#define inf               1e18
#define ps(x,y)           fixed<<setprecision(y)<<x
#define mk(arr,n,type)    type *arr = new type[n] ;
#define test(t)           int t ; cin >> t ; while(t--)
#define ifor(a,b)         for(int i = a ; i < b ; i++)
#define dfor(a,b)         for(int i = b-1 ; i >= a ; i--)
#define fio               ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0) ;


// check odd even : n & 1
// check power of 2 : n & n - 1 == 0
//flip xor
//set or
//unset and
//for -ve no.s mod ( a % mod + mod ) % mod ; 

/*
ll power(ll x, ll y, ll p) 
{ 
	if(x==0 && y==0)
	{
		return 1;
	}
	ll res = 1;	 
	x = x % p;  

	if (x == 0) return 0; 

	while (y > 0) 
	{ 
		if (y & 1) 
			res = (res*x) % p; 
		y = y>>1;
		x = (x*x) % p; 
	} 
	return res; 
} 
*/

int32_t main()
{
    fio;
    test(t){
        int k=0;
        int n=0;
        int m=0;
        int nl=0,flag=0;
        cin>>k>>n>>m;
        // int nW[n],mW[m];
        // for(int i = 0 ; i<n;i++){ 
        //     cin>>nW[i];
        //     if(nW[i]==0){
        //         nl++;
        //     }
        // }
        // for(int i = 0 ; i<m;i++) { 
        //     cin>>mW[i];
        //     if(mW[i]==0){
        //         nl++;
        //     }
        // }
        vector<int> allWork;
        int temp;
        for(int i = 0;i<m+n;i++){
            cin>>temp;
            allWork.push_back(temp);
            if(allWork[i]==0) ++nl;
        }
        if ((nl+k)<(n+m))
        {
            cout<<"-1"<<endl;
            continue;       
        }
        
        sort(allWork.begin(),allWork.end());
        vector<int> finalwork;
        for(int i = 0;i<(m+n);i++){
            if(allWork[i]>0){
                flag = i;
                break;
            }
        }
        bool wd=true;
        while(flag<m+n){
            while(allWork[flag]>k&&nl!=0){
                finalwork.push_back(0);
                nl--;
                k++;
            }
            if(allWork[flag]>k&&nl==0){
                wd = false;
                break;
            }else{
                finalwork.push_back(allWork[flag]);
            }
        }
        if(wd){
            for(int i = 0;i<(m+n);i++){
                cout<<finalwork.at(i)<<" ";
            }
            cout<<endl;
        }else{
            cout<<"-1"<<endl;
        }
        

    }
}