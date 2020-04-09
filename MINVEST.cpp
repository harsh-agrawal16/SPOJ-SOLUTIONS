#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//knapsack based
//solved . Good Problem.

ll dp_rec(ll amount, vector<pair<ll,ll>> &bonds){
	ll n = bonds.size();
	ll x = amount/1000;
	vector<ll> dp(x+1);
	vector<ll> f(x);

	for(ll i=0;i<x;i++){
		f[i] = amount - (x-(i+1))*1000; 
	}

	for(ll i =1;i<=n;i++){
		for(ll j=1;j<=x;j++){
			if(bonds[i-1].first > f[j-1]){continue;}
			dp[j] = max(dp[j], dp[(f[j-1]-(bonds[i-1].first))/1000] + bonds[i-1].second);
		}
	}

	amount+=dp[x];

	return amount;

}

int main(){
	ll t;
	cin>>t;
	while(t--){

		ll amount,years;
		cin>>amount>>years;
		ll n;
		cin>>n;
		vector<pair<ll,ll>> bonds(n);

 

		for(ll i=0;i<n;i++){
			cin>>bonds[i].first;
			cin>>bonds[i].second;
		}

		for(ll i=0;i<years;i++){
			amount = dp_rec(amount, bonds);
		}

		cout<<amount<<endl;
	}
}