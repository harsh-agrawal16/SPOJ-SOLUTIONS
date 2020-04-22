/**
        *AUTHOR:Harsh Agrawal*
        *Birla Institute of Technology,Mesra*    
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+1;
#define for0(i,e) for(ll i=0;i<e;i++)
#define forx(i,x,e) for(ll i=x;i<e;i++)
#define ln "\n"
#define in(a) cin>>a
#define out(a) cout>>a;
#define vll vector<ll> 
#define vvll vector<vll>
#define fastIO  ios_base::sync_with_stdio(0);\
                cin.tie(NULL);\
                cout.tie(NULL)

            

ll dp_rec(ll low, ll high, vll &arr, vvll &dp){
	if(dp[low][high]!=-1) return dp[low][high];
	if(high - low == 1){
		dp[low][high] =  max(arr[low],arr[high]);
		return dp[low][high];
	}
	if(low==high) {dp[low][high] = arr[low]; return dp[low][high];}

	ll x = (arr[low+1]>=arr[high])? dp_rec(low+2,high,arr,dp) : dp_rec(low+1,high-1,arr,dp);
	x+=arr[low];
	ll y = (arr[low]>=arr[high-1])? dp_rec(low+1,high-1,arr,dp) : dp_rec(low,high-2,arr,dp);
	y+=arr[high];

	dp[low][high] = max(x,y);
	return dp[low][high];
}

int main(){
	fastIO;
	ll n;
	ll t=1;
	while(cin>>n){
		if(n==0)return 0;
		vvll dp(n,vll(n,-1));   
		vll arr(n);for0(i,n)cin>>arr[i];
		ll total = accumulate(arr.begin(),arr.end(),0);
		ll x = dp_rec(0,n-1,arr,dp);
		cout<<"In game "<<t<<", the greedy strategy might lose by as many as "<<x - (total-x)<<" points."<<ln;
		t++;
	}
	

	//In game 1, the greedy strategy might lose by as many as 7 points.


}