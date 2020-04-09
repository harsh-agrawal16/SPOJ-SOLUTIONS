#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

unordered_map<ll,ll> HashMap;

ll dp_rec(ll n){
	if(HashMap.find(n) != HashMap.end()) return HashMap[n];

	HashMap[n] = dp_rec(n/2) + dp_rec(n/3) + dp_rec(n/4);
	if(HashMap[n]<n) HashMap[n] = n;
	return HashMap[n];
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    HashMap[0] = 0;
    HashMap[1] = 1;
    //HashMap[2] = 2;
  

	ll n;
	while(cin>>n){

    cout<<dp_rec(n)<<endl;
	}
	



}