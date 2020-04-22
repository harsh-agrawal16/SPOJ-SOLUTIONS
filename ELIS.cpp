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
#define fastIO  ios_base::sync_with_stdio(0);\
                cin.tie(NULL);\
                cout.tie(NULL)


int main(){
	fastIO;
	ll n;cin>>n;
	vll arr(n);
	for0(i,n) cin>>arr[i];

	vll dp(n,1);
	for(ll i=1;i<n;i++)
	{
		for(ll j=0;j<i;j++){
			if(arr[i]>arr[j]){
				dp[i] = max(dp[i], 1+dp[j]);
			}
		}
	}

	ll mx = 0;
	for0(i,n){
		mx = (dp[i]>mx)? dp[i] : mx;
	}
	cout<<mx<<ln;
}