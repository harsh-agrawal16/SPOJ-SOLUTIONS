#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[1000][22][80];
int o2[1000],n2[1000],wt[1000];



int dp_rec(int x, int o, int n){

    for(j=0;j<=o;j++){
    	for(k=0;k<=n;k++){
    		if(j==0&&k==0){
    			dp[0][j][k] = 0;
    		}
    		else{
    			if(j<=o2[0] && k<=n2[0]){
    				dp[0][j][k] = wt[0];
    			}
    		}
    	}
    } 
    
	for(int i=1;i<x;i++){
		for(int j=0;j<=o;j++){
			for(int k=0;k<=n;k++){
				if(j==0 && k==0) {dp[i][j][k] = 0;continue;}
				dp[i][j][k] = min(dp[i-1][j][k], wt[i]+dp[i-1][max(0,j-o2[i])][max(0,k-n2[i])]);					    
			}
		}
	}

	return dp[x-1][o][n];
}


int main(){
	//memset(dp,0,sizeof(dp));
	int t;
	cin>>t;
	while(t--){
		ll o,n;
		cin>>o>>n;
		ll x;
		cin>>x;

		memset(dp,INT_MAX,sizeof(dp));
		//memset(o2,0,sizeof(o2));
		//memset(wt,0,sizeof(wt));
		//memset(n2,0,sizeof(n2));
	
		for(int i=1;i<=x;i++){
			cin>>o2[i]>>n2[i]>>wt[i];
		}

		cout<<dp_rec(x,o,n)<<endl;

	}


}