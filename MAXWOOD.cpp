#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//https://ideone.com/PVJDVM

ll dp[209][209][2];
char trees[209][209];
ll m, n;
ll dp_rec(ll i, ll j, ll face){
    ll x, y;
	if(i>=m || j>=n) return 0;
    if(dp[i][j][face] != -1) return dp[i][j][face];

    dp[i][j][face] = 0;
    if(trees[i][j]=='T') dp[i][j][face] = 1;

    if(face==1){
    	x = 0; y = 0;
    	if(j+1<n){
    		if(trees[i][j+1]!='#'){
    		x = dp_rec(i,j+1,1);
    	   }
    	}

    	if(i+1<m){
    		if(trees[i+1][j]!='#'){
    			y = dp_rec(i+1,j,0);
    		}
   		}  

    	dp[i][j][face] += max(x,y);
    	return dp[i][j][face]; 
    }

    else{

    	x = 0; y = 0;
    	if(j-1>=0){
    		if(trees[i][j-1]!='#'){
    			x = dp_rec(i,j-1,0);
    		}
    	}

    	if(i+1<m){
	    	if(trees[i+1][j]!='#'){
    			y = dp_rec(i+1,j,1);
    		}
    	}

    	dp[i][j][face] += max(x,y);
    	return dp[i][j][face];

    }
}

int main(){
	ll t;
	ll x,y;
	cin>>t;
	while(t--){
		cin>>m>>n;
		
		for(ll i = 0;i<m;i++){
			for(ll j=0;j<n;j++){
				cin>>trees[i][j];
			}
		}

	    memset(dp,-1,sizeof(dp));    
	    
		ll ans = 0;
        ans += dp_rec(0,0,1);
        cout<<ans<<endl;
        
	}
}