#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

 int main(){
 	ll t;
 	cin>>t;
 	while(t--){
 		ll n;
 		cin>>n;

 		if(n==0){
 			cout<<0<<endl;
 			continue;
 		}

 		vector<ll> toys(n);
 		for(ll i=0;i<n;i++){
 			cin>>toys[i];
 		}

 		if(n==1){
 			cout<<toys[0]<<endl;
 			continue;
 		}

 		if(n==2){
 			cout<<toys[0] + toys[1]<<endl;
 			continue;
 		}

 		vector<ll> dp(n);
 		dp[n-1] = toys[n-1];
 		dp[n-2] = toys[n-2] + dp[n-1];
 		dp[n-3] = toys[n-3] + dp[n-2];

 		for(ll i=n-4;i>=0;i--){
 			ll x,y,z;
 			x = toys[i] + dp[i+2];
 			y = ((i+4)<n)? (toys[i] + toys[i+1] + dp[i+4]) : (toys[i] + toys[i+1]) ;
            z = ((i+6)<n)? (toys[i] + toys[i+1] + toys[i+2] + dp[i+6]) : (toys[i] + toys[i+1] + toys[i+2]);
            dp[i] = max(x,max(y,z));  

 		}

 		cout<<dp[0]<<endl;
 	}

 }