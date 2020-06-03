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

void solve(){
	ll n,k;
	cin>>n>>k;

	vll arr(n);
	ll sum = 0;
	for0(i,n){cin>>arr[i];sum+=arr[i];}
	sort(arr.begin(),arr.end());

	ll low = 1;
	ll ans = 0;
	ll high = 1000000000;

	while(low<=high){
		ll mid = (low+high)/2;

        ll count = 0;
		for0(i,n){
			if(mid!=0 && mid<=arr[i]) count+=(arr[i]/mid);
		}

		if(count>=k){
			ans = max(ans, mid);
		}

		if(count>=k){
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}

	}

	cout<<ans<<endl;
}

int main(){
	fastIO;
	ll t;
	cin>>t;
	while(t--){
		solve();
	}
}

