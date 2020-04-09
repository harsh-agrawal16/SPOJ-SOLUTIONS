#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll k,l,m;
string ans = "";

ll dp_rec(ll coins, vector<vector<ll>> &dp, ll isA){
	if(coins==0){
	  return 1;
    }
	if(dp[coins][isA]!=-1) return dp[coins][isA];

    if(isA==0){
   		if(coins-k>=0 && coins-l>=0){
		   dp[coins][isA] = dp_rec(coins-k,dp,!isA) || dp_rec(coins-l,dp,!isA) || dp_rec(coins-1,dp,!isA);
		}

		else if(coins-k>=0){
				dp[coins][isA] = dp_rec(coins-k,dp,!isA) || dp_rec(coins-1,dp,!isA);
			
		}

		else{
			    dp[coins][isA] = dp_rec(coins-1,dp,!isA);
		}

		return !dp[coins][isA];
	}

}


int main(){
	cin>>k>>l>>m;
	vector<ll> coins(m);
	ll isA = 1;

	for(ll i=0;i<m;i++){
		cin>>coins[i];
	} 

	for(ll i=0;i<m;i++){
		vector<vector<ll>> dp(coins[i],vector<ll>(2,-1));
		if(dp_rec(coins[i]-k,dp,0) || dp_rec(coins[i]-l,dp,0) || dp_rec(coins[i]-1,dp,0)){
			ans+="A";
		}
		else{
			ans+="B";
		}
	}

	cout<<ans<<endl;

	




}