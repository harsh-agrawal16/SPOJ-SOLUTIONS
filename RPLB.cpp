#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> dp(1000,vector<ll>(1001,-1));
ll n;
vector<ll> arr(1000);

ll dp_rec(ll i,ll limit){

    if(dp[i][limit]!=-1) return dp[i][limit];

    if(i==n-1){
    	if(arr[n-1]<=limit) dp[i][limit] = arr[n-1];
    	else dp[i][limit] = 0;
    	return dp[i][limit];
    }  
    
    if(i==n-2){
    	if(arr[n-2]<=limit) dp[i][limit] = arr[n-2];
    	else dp[i][limit] = 0;
    	
    	if(arr[n-1]>dp[i][limit] && arr[n-1]<=limit){
    		dp[i][limit] = arr[n-1];
    	}
    	
    	return dp[i][limit];
    }

    ll x, y;
    
    if(arr[i]<=limit) x =  arr[i] + dp_rec(i+2,limit-arr[i]);
    else x = 0;
    
    y = dp_rec(i+1,limit);
    dp[i][limit] = max(x,y);
    return dp[i][limit];
}


int main(){
	ll t;
	cin>>t;
   
   
   //if limit is zero   
	for(ll i=0;i<1000;i++){
		dp[i][0] = 0;
	}


	for(ll j=1;j<=t;j++){
		ll k;
		cin>>n>>k;

		for(ll i=0;i<n;i++){
			cin>>arr[i];
		}


        //Scenario #1: 90

		cout<<"Scenario #"<<j<<": "<<dp_rec(0,k)<<endl;

	}
}