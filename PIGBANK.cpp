#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	ll t;
	while(t--){
		ll E,F;
		cin>>E>>F;
		ll weight = F-E;

		ll n; cin>>n; 
		vector<pair<ll,ll>> coins;

		for(ll i=0;i<n;i++){
			cin>>coins[i].first;
			cin>>coins[i].second;
		}

		vector<ll> dp(weight+1,INT_MAX);
		dp[0] = 0;

        for(ll i=0;i<n;i++)
			for(ll j=1;j<=weight;j++){
				if(coins[i].second <= j){
					dp[j] = min(dp[j], dp[j-coins[i].second] + coins[i].first); 
				}
			}

		if(dp[weight]!=INT_MAX) cout<<"The minimum amount of money in the piggy-bank is "<<dp[weight]<<"."<<endl;
		else cout<<"This is impossible."<<endl;	
	}
}