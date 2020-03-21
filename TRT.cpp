#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


//Good Question. You need to have good insights to solve these questions.
int main(){
	ll n;
	cin>>n;

	vector<ll> values(n);
	for(ll i=0;i<n;i++){
		cin>>values[i];
	}

	vector<vector<ll>> dp (n, vector<ll> (n,-1));
    ll i,j;
	for(ll gap =0 ;gap<n;gap++){
		for(j=gap,i=0;j<n;j++,i++){
			if(i==j) dp[i][j] = values[i]*(n);
			else{
				//n - (j-i) + 1
				int x = values[i]*(n - (j-i)) + dp[i+1][j];
				int y = values[j]*(n - (j-i)) + dp[i][j-1];
				dp[i][j] = max(x,y);
			}

		}
	}

	cout<<dp[0][n-1]<<endl;
}