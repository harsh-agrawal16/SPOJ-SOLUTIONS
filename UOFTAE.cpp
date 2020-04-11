#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//accepted

vector<vector<ll>> dp(200, vector<ll> (201,-1));
vector<vector<ll>> fox(200, vector<ll>(2));
ll n,m;

ll dp_rec(ll i, ll j){
	if(dp[i][j]!=-1) return dp[i][j];
	if(j==0) return 0;
	if(j<fox[i][0]) return 0;
	if(i==n-1 && j>=fox[i][0] && j<=fox[i][1]) return 1;
	if(i==n-1 && j>fox[i][1]) return 0;

	dp[i][j] = 0;
	for(ll k=fox[i][0];k<=fox[i][1];k++){
		if(j>=k) dp[i][j]+=dp_rec(i+1,j-k);
	}

	return dp[i][j];
}

int main(){
	ll t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(ll i=0;i<n;i++){
			cin>>fox[i][0]>>fox[i][1];
		}

		for(ll i=0;i<200;i++){
			for(ll j=0;j<201;j++){
				dp[i][j] = -1;
			}
		}

		dp[0][0] = 0;

		cout<<dp_rec(0,m)<<endl;
	}
}
