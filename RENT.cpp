#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool compare(const vector<ll> &a, const vector<ll> &b){
	return a[0]<b[0];
}

ll bsearch(vector<vector<ll>> &orders, ll low, ll high, ll x){

	ll mid = (high+low)/2;

	if(low>high) return low;
    
    if(orders[mid][0] == x) return mid;

    if(orders[mid][0] > x) return bsearch(orders,low,mid-1,x);

    if(orders[mid][0] < x) return bsearch(orders,mid+1,high,x);

}

int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;

		vector<vector<ll>> orders(n,vector<ll>(3,-1));
		for(ll i=0;i<n;i++){
			for(ll j=0;j<3;j++){
				cin>>orders[i][j];
			}
		}

		sort(orders.begin(),orders.end(), compare);

		vector<ll> dp(n+1,0);
        
        dp[n-1] = orders[n-1][2];
		for(ll i=n-2;i>=0;i--){
			dp[i] = max(dp[i+1], orders[i][2] + dp[bsearch(orders,0,n-1,orders[i][0] + orders[i][1])]);
		}

		cout<<dp[0]<<endl;
}
	}