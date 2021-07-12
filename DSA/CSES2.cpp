//GODLEON'S CODE
// #include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
#include<iostream>
using namespace std;
// using namespace __gnu_pbds;

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
// mt19937                   rng(chrono::steady_clock::now().time_since_epoch().count());


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
// void soln(int n){
//     if(n==1){ 
//             cout<< "1"<<endl;
//             return;
//         }
//         cout =
//         if(n%2==0){ 
//             soln(n/2);
//         }
//         if(n%2!=0){
//             soln(n*3+1);
//         }
// }

int32_t main()
{
fio;

    int n ;
    cin>>n;
    int sumToN = (n*(n+1))/2;
    int temp = 0;
    for(int i = 1; i<n;i++){
        cin>>temp;
        sumToN-=temp;
        temp = 0;
    }
    cout<<sumToN;

}