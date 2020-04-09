#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//accepted. AC in one go.


ll rbn(vector<ll> &arr,ll low , ll high){
	vector<ll> dp(high-low+1, 1);

	for(ll i=low+1;i<=high;i++){
		for(ll j=low;j<i;j++){
			if(arr[i]<arr[j]){
				dp[i] = max(dp[i], 1+dp[j]);
			}
		}
	}

	return dp[high];
}


pair<ll,ll> lds(vector<ll> &arr, ll low,ll high, vector<ll> &dp){

	for(ll i=high-1;i>=0;i--){
		for(ll j=high;j>i;j--){
			if(arr[i]>arr[j]){
				dp[i] = max(dp[i], 1 + dp[j]);
			}
		}
	}
    
    pair<ll,ll> temp;
    ll m=dp[0];
    ll max_index = 0;
	for(ll i=1;i<=high;i++){
		if(dp[i]>=m){
			m = dp[i];
			max_index = i;
		}
	}

    temp.first = m;
    temp.second = max_index;
	return temp;
}


int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;

		ll robin;
		cin>>robin;
        
        vector<ll> dp(n,1);
		vector<ll> peaks(n);
		for(ll i=0;i<n;i++){
			cin>>peaks[i];
		}
        
        pair<ll,ll> x = lds(peaks,0,n-1,dp);
        ll a1 = x.first;
		if(x.second>robin){
			a1++;
		}
        
       ll lds_robin = rbn(peaks,0,robin);
       ll mx=0; ll index;
       for(ll i=robin+1;i<n;i++){
       	   if(dp[i]>=mx){
       	   	mx = dp[i];
       	   	index = i;
       	   }
       }

       lds_robin+=mx;
       

       cout<<max(a1,lds_robin)<<"\n";


	}

}