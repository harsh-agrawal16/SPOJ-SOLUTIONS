#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


//recursively solved this dynamic programming problem
//*****



ll n;
ll dp_rec(ll arr[],ll dp[],ll i){
   
   if(dp[i]!=-1) return dp[i];
  
   dp[i] = 0;
   if(arr[i] != 0) dp[i] = dp_rec(arr,dp,i-1);
   if(arr[i-1]!=0 && (arr[i-1]*10+arr[i]) <=26){
   	dp[i] = dp[i] + dp_rec(arr,dp,i-2);
   }

   return dp[i];


}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(1){
		string a;
		cin>>a;

		ll n = a.size();

		if(n==0 || a[0] == '0') break;


        //using dp for memoisation
		ll dp[n],arr[n];

		for(ll i=0;i<n;i++){
			dp[i] = -1;
			arr[i] = a[i] - '0';
		}

        dp[0] = 1;
        if(arr[1] == 0 ) dp[1] = 0;
        else dp[1] = dp[0];
        
        if(arr[0]!= 0 && (arr[0]*10 + arr[1]) <= 26){
        	dp[1] = dp[1]+1;
        }

		//dp_rec(arr,dp,n-1);

		cout<<dp_rec(arr,dp,n-1)<<endl;

	}

}