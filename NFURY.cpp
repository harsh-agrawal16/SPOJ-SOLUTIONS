    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    //pay great attention to input and time limit.
    
    int main(){

    	ll t;
    	cin>>t;
    	
    	vector<ll> dp(1001,INT_MAX);
    	dp[0] = 0;
		for(int i=1;i<32;i++){
			for(int j=i*i;j<=1000;j++){
				dp[j] = min(dp[j], 1 + dp[j-i*i]);
			}
		}
    	
    	
    	
    	while(t--){

            ios::sync_with_stdio(false);
            cin.tie(NULL);
    		ll A;
    		cin>>A;


    		cout<<dp[A]<<endl;

    	}


    }