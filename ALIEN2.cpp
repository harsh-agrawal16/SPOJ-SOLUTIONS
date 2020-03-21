#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n,k;
	//ll stations,passengers;
	cin>>n>>k;

	vector<ll> A(n);
	vector<ll> B(n);
	for(ll i=0;i<n;i++){
		cin>>A[i];
	}
	for(ll i=0;i<n;i++){
		cin>>B[i];
	}

	vector<ll> dp(n);

	ll a=A[0],b=B[0];
	bool isOnA;
	if(A[0]>B[0] && B[0]<=k){
		isOnA = false;
		dp[0] = B[0];
	}
	else if(A[0]<B[0] && A[0]<=k){
		isOnA = true;
		dp[0] = A[0];
	}
	else{
		dp[0] = 0;
		cout<<0<<" "<<0<<endl;
		return 0;
	}
 
    ll x=0,y=0;
	for(ll i=1;i<n;i++){
		a+=A[i];
		b+=B[i];

		if(isOnA){
			x = dp[i-1] + A[i];
			y = dp[i-1] + B[i-1] + B[i];
		}
		else{
			x = dp[i-1] + B[i];
			y = dp[i-1] + A[i-1] + A[i];
		}

		dp[i] = min(min(a,b),min(x,y));

		if(dp[i]>k){
			//stations = i-1;
			//passengers = dp[n-1];
			cout<<i<<" "<<dp[i-1]<<endl;
			return 0;
		}

		if(dp[i]==a){
			isOnA = true;
		}
		else if(dp[i] == b){
			isOnA = false;
		}
		else if(dp[i] == y){
			isOnA = !isOnA;
		}
	}

	cout<<n<<" "<<dp[n-1]<<endl;
	return 0;
}