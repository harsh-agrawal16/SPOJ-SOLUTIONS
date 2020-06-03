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
ll n,m,ans=0;
vll arr;
vll pref;

ll bsearch(ll low , ll high, ll x){
    
    ll a = high;
	while(low<=high){
		ll mid = (low + high)/2;
		
		if(arr[mid] <= x){
			low = mid + 1;
		}
		else{
			high = mid - 1;
			a = mid;
		}
	}

	return a;
}


void solve(){
	cin>>n>>m;
	arr.resize(n+1);
	pref.resize(n+1,0);
	for0(i,n) cin>>arr[i+1];
	arr[0] = 0;
	sort(arr.begin(),arr.end());

	for(ll i=1;i<=n;i++){
		pref[i] = pref[i-1] + arr[i];
	}
    
    ll hlow = 1;
    ll hhigh = arr[n];

    while(hlow<=hhigh){
    	ll mid = (hlow + hhigh)/2;
    	ll index = bsearch(1,n,mid); //getting the strict upper_bound here.
    	ll temp = (pref[n] - pref[index-1]) - (mid*((n+1) - index));
    	if(temp>=m){
    		if(ans < mid) ans = mid;
    	}

    	if(temp >= m){
    		hlow = mid + 1;
    	}
    	else{
    		hhigh = mid - 1;
    	}
    }
    cout<<ans<<endl;

}

int main(){
	ll t=1;
	while(t--){
		solve();
	}
}

