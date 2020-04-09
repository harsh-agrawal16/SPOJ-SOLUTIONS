#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//accepted. AC in One Go.

ll n,min_area;
vector<pair<ll,ll>> slabs(200);
vector<vector<ll>> dp(601,vector<ll>(601));

ll dp_rec(ll w, ll h){
	
	if(w*h < min_area) return w*h;
	
	if(dp[w][h]!=-1) return dp[w][h];
    
    dp[w][h] = INT_MAX;
    
	for(ll i=0;i<n;i++){
		
		if(slabs[i].first == w && slabs[i].second == h){
			dp[w][h] = 0;
			return dp[w][h];
		}
		
    	if(slabs[i].first < w) dp[w][h] = min(dp[w][h], dp_rec(w-slabs[i].first,h) + dp_rec(slabs[i].first,h));
     	if(slabs[i].second< h) dp[w][h] = min(dp[w][h], dp_rec(w,h-slabs[i].second) + dp_rec(w,slabs[i].second));
   } 

   return dp[w][h];

}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin>>t;
	while(t--){
		ll W,H;
		cin>>W>>H>>n;
		min_area = INT_MAX;
		for(ll i=0;i<n;i++){
			cin>>slabs[i].first>>slabs[i].second;
			if(slabs[i].first*slabs[i].second < min_area){
				min_area = slabs[i].first*slabs[i].second;
			}
        }

        for(ll i=0;i<601;i++)
        	for(ll j=0;j<601;j++)
        		dp[i][j] = -1;


        cout<<dp_rec(W,H)<<"\n";


	}

}

