#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll LIS(vector<ll> &arr, ll n){
	vector<ll> dp(n,1);
    
    ll m = 1;
	for(ll i=1;i<n;i++){
		for(ll j=0;j<i;j++){
			if(abs(arr[i]) > abs(arr[j]) && ((arr[i]>0 && arr[j]<0) || (arr[j]>0 && arr[i]<0))){
				dp[i] = max(dp[i], 1+dp[j]);
				if(dp[i]>m){
					m = dp[i];
				}
			}
		}
	}

	return m;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin>>n;

	vector<ll> arr(n);
	for(ll i=0;i<n;i++) cin>>arr[i];

    cout<<LIS(arr,n)<<"\n";		
}