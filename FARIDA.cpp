    #include<iostream>
    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
     
    int main(){
    	ll t;
    	cin>>t;
    	for(int j=1;j<=t;j++){
    		ll n;
    		cin>>n;
     
    		if(n==0){
    			cout<<"Case "<<j<<": "<<0<<endl;
    			continue;
    		}
    		vector<ll> coins(n);
     
     
     
    		for(int i=0;i<n;i++){
    			cin>>coins[i];
    		}
     
    		vector<ll> dp(n,0);
     
    		dp[n-1] = coins[n-1];
     
    		for(int i=n-2;i>=0;i--){
    			if(i+2 <= n-1) dp[i] = max(coins[i] + dp[i+2] , dp[i+1]);
    			else{
    				dp[i] = max(coins[i],dp[i+1]);
    			}
    		}
     
    		cout<<"Case "<<j<<": "<<dp[0]<<endl;
    	}
     
    }