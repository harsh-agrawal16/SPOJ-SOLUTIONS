#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll max_weight;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    ll t;
    cin>>t;

    while(t--){
    	ll m;
    	cin>>max_weight>>m;

    	vector<pair<ll,ll>> bags;

    	for(ll i=0;i<m;i++){
    		ll a,b;
    		cin>>a>>b;

    		bags.push_back({a,b});
    	}


    	vector<vector<ll>> dp(m+1, vector<ll> (max_weight+1,-1));
    	for(ll i=0;i<m+1;i++){
    		dp[i][0] = 0;
     	}
     	for(ll i=0;i<=max_weight;i++){
    		dp[0][i] = 0;
     	}


     	for(ll i=1;i<=m;i++){
     		for(ll j=1;j<=max_weight;j++){
     			if(bags[i-1].first > j) dp[i][j] = dp[i-1][j];
     			else{
     				dp[i][j] = max(bags[i-1].second + dp[i-1][j-bags[i-1].first], dp[i-1][j]);
     			}
     		}
     	}


        /*Hey stupid robber, you can get 8.
		Hey stupid robber, you can get 25.
		Hey stupid robber, you can get 99.*/

     	cout<<"Hey stupid robber, you can get "<<dp[m][max_weight]<<"."<<endl;
         
    }
}