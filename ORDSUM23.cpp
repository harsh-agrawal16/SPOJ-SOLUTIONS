#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//based on padovan sequence.

vector<ll> dp(1000000,0);


int main(){
	ll d =  1000000007;
	dp[2]=1;
	dp[3]=1;
	for(ll i=4;i<=1000000;i++){
		dp[i] = (dp[i-2] + dp[i-3])%d;
	}
	
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		cout<<dp[n]<<"\n";
	}
	
	return 0;
}