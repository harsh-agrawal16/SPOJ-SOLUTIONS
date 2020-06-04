/**
        *AUTHOR:Harsh Agrawal*
        *Birla Institute of Technology,Mesra*    
**/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=2e5+1;
#define for0(i,e) for(ll i=0;i<e;i++)
#define for1(i,e) for(ll i=1;i<e;i++)
#define forx(i,x,e) for(ll i=x;i<e;i++)
#define ln "\n"
#define in(a) cin>>a
#define out(a) cout>>a;
#define pb push_back
#define vll vector<ll> 
#define vvll vector<vll>
#define vi vector<int>
#define vvi vector<vi>
#define qll queue<ll>
#define fastIO  ios_base::sync_with_stdio(0);\
                cin.tie(NULL);\
                cout.tie(NULL)

vll arr;
ll n;         

ll bsearch(ll low , ll high, ll x){
	ll ans = -1;
	while(low<=high){
		ll mid = (low+high)/2;

		if(arr[mid]>x){
			high = mid - 1;
			ans = mid;
		}

		else{
			low = mid + 1;
		}
	}

	return ans;
}       

void solve(){
	
	while(true){
		cin>>n;
		if(n==0) return;

		arr.resize(n);
		for0(i,n) cin>>arr[i];

		sort(arr.begin(),arr.end());

		ll ans = 0;

		for(ll i=0;i<n;i++){
			for(ll j=i+1;j<n;j++){
				ll index = bsearch(0,n-1,arr[i]+arr[j]);
				//get the upperbound.
			    if(index == -1) break;

			    ans+=(n-index);
			}
		}

		cout<<ans<<endl;

	}

}

int main(){
	fastIO;
	ll t;
	t=1;
	while(t--){
		solve();
	}
}

