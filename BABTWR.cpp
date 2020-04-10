#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//AC in one go. Good dp. Box stacking problem.

vector<vector<ll>> cubes(30, vector<ll>(3,-1));
vector<vector<ll>> dp(2501,vector<ll>(2501,-1));
ll n,min_area;

ll dp_rec(ll i, ll j){
	if(dp[i][j]!=-1) return dp[i][j];
	if(i*j < min_area){
		return 0;
	}
    
    dp[i][j] = 0;
	for(ll k=0;k<n;k++){
		if((cubes[k][0] < i && cubes[k][1]< j) || (cubes[k][0] < j && cubes[k][1]< i)){
			dp[i][j] = max(dp[i][j], cubes[k][2] + dp_rec(cubes[k][0], cubes[k][1]));
		}
		if((cubes[k][0] < i && cubes[k][2]< j) || (cubes[k][0] < j && cubes[k][2]< i)){
			dp[i][j] = max(dp[i][j] , cubes[k][1] + dp_rec(cubes[k][0], cubes[k][2]));
		}
		if((cubes[k][1] < i && cubes[k][2]< j) || (cubes[k][1] < j && cubes[k][2]< i)){
			dp[i][j] = max(dp[i][j], cubes[k][0] + dp_rec(cubes[k][1], cubes[k][2]));
		}
	}
	dp[j][i] = dp[i][j];

	return dp[i][j];
}

int main(){
		
	while(true){	
		cin>>n;
		if(n==0) break;
	    
	    min_area = INT_MAX;
		for(ll i=0;i<n;i++){
			for(ll j=0;j<3;j++){
				cin>>cubes[i][j];
			}
	
			if(cubes[i][0]*cubes[i][1] < min_area) min_area =  cubes[i][0]*cubes[i][1];
			if(cubes[i][0]*cubes[i][2] < min_area) min_area =  cubes[i][0]*cubes[i][2];
			if(cubes[i][2]*cubes[i][1] < min_area) min_area =  cubes[i][2]*cubes[i][1];
		}
	
		for(ll i=0;i<2501;i++){
			for(ll j=0;j<2501;j++){
				dp[i][j] = -1;
			}
		}
		dp[0][0] = 0;
	
		ll m=0,ans=0;
	
		for(ll k=0;k<n;k++){
			m = cubes[k][2] + dp_rec(cubes[k][0],cubes[k][1]);
			m = max(m, cubes[k][1] + dp_rec(cubes[k][0],cubes[k][2]));	
			m = max(m, cubes[k][0] + dp_rec(cubes[k][1],cubes[k][2]));
	
			ans = (ans<m)? m:ans;
		}
		
		cout<<ans<<"\n";
	}
	
	return 0;
	
		

}