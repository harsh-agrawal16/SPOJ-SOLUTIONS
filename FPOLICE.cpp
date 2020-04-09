#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//dp[i][j] is the min cost to reach ith station from 0th station within time j.
vector<vector<ll>> dp(100,vector<ll>(251,-1));

vector<vector<ll>> ti(100,vector<ll>(100,-1));
vector<vector<ll>> risk(100,vector<ll>(100,-1));

ll n;

ll dp_rec(ll nn,ll t){
	if(t<0) return INT_MAX;
	if(dp[nn][t]!=-1) return dp[nn][t];

	dp[nn][t] = dp_rec(nn,t-1);
	for(ll i=0;i<n;i++){
		if(t-ti[i][nn]>=0){
			dp[nn][t] = min(dp[nn][t], dp_rec(i,t-ti[i][nn]) + risk[i][nn]);
		}
	}

	return dp[nn][t];

}

int main(){
	ll k;
	cin>>k;
	while(k--){
		ll t;
		cin>>n>>t;

		for(ll i=0;i<n;i++){
			for(ll j=0;j<n;j++){
				cin>>ti[i][j];
			}
		}

		for(ll i=0;i<n;i++){
			for(ll j=0;j<n;j++){
				cin>>risk[i][j];
			}
		}
        
        //resetting dp after each iteration
        for(ll i=0;i<100;i++){
        	for(ll j=0;j<251;j++){
        		dp[i][j] = -1;
        	}
        }
        
        //A base case.
        for(ll i=0;i<251;i++){
        	dp[0][i] = 0;
        }


        ll ans = dp_rec(n-1,t);
        if(ans==INT_MAX){
        	cout<<"-1"<<endl;
        	continue;
        }
        ll ans2=0;
        for(ll i=0;i<=t;i++){
        	if(dp[n-1][i]==ans){
        		ans2=i;
        		break;
        	}
        }

        cout<<ans<<" "<<ans2<<endl;
	}
}