#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll dp[6101][6101][2];

int main()
{
	ll t;
	cin>>t;
	while(t--){
		string a;
		cin>>a;
		memset(dp,1,sizeof(dp));
        
        ll n = a.length();
        ll left=-1,right=-1;
        ll max = 1;
		for(ll gap=1;gap<=n;gap++){
			for(j=gap,i=1;j<=n;i++,j++){
				if(i==j) {
					dp[i][j][0] = 1;
					dp[i][j][1] = 1;
					continue;
				}
				if(a[i-1]==a[j-1]){
					if(dp[i+1][j-1][1]) {
						dp[i][j][0] = dp[i+1][j-1][0] + 2;
						dp[i][j][1]=1;
						if(dp[i][j][0]>max)
						left = i;
						right =j;
					}
					else
					{
					 dp[i][j][1] = 0;
					 dp[i][j][0] = max(dp[i+1][j][0],dp[i][j-1][0]);
					}
				}
				else{
					 dp[i][j][1] = 0;
					 dp[i][j][0] = max(dp[i+1][j][0],dp[i][j-1][0]);
				}

			}
		}
	}
	



}