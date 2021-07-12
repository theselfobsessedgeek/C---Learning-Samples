//THESELFOBSESSEDGEEK'S CODE
// #include<bits/stdc++.h>
#include<iostream>
// #include<ext/pb_ds/assoc_container.hpp>
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
// #define ifor(a,b)         for(int i = a ; i < b ; i++)
// #define dfor(a,b)         for(int i = b-1 ; i >= a ; i--)
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

// int32_t main()
// {
//     fio;
//     test(t)
//     {
//         int a=0,b=0,diff=0;
//         int32_t way=0;
//         cin >> a;
//         cin >> b;
//         diff = (a>=b)? (a-b) : (b-a);
//         way = (diff%10==0)? (diff/10):(diff/10)+1;
//         cout<<way<<endl; 
//     }
// }

int32_t main()
{
    fio;
    test(t)
    {

        int a,b,x,y,n;
        cin>>a>>b>>x>>y>>n;
        int a1=a,b1=b,x1=x,y1=y,n1=n;
        int a2=a,b2=b,x2=x,y2=y,n2=n;

        int ans = INT32_MAX;

        a1 = (n1<=x) ? (a1-n1) : (a1-(n1-x));
        n1 = n1-x;
        if(n1>0) b1-= n1;
        if(b1<y) b1=y;
        ans=min(ans,a1*b1);

        b2 = (n2<=y) ? (b2-n2) : (b2-(n2-x));
        n2 = n2-y;
        if(n2>0) a2-= n2;
        if(a2<x) a2=x;
        ans=min(ans,a2*b2);
        
        cout<< ans<<endl;
        
    }
}