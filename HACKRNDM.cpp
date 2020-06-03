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
ll n,k,ans=0;
vll arr;

void bsearch(ll low , ll high, ll x){

	while(low<=high){
		ll mid = (low + high)/2;

		if(arr[mid] == x){
			ans++;
			return;
		}
		else if(arr[mid] < x){
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}

	return;
}


void solve(){
	cin>>n>>k;
	arr.resize(n);
	for0(i,n) cin>>arr[i];
	sort(arr.begin(),arr.end());
    
    for0(i,n){
    	bsearch(0,n-1,arr[i]+k);
    	//bsearch(0,n-1,arr[i]-k);
    }

    cout<<ans<<endl;
}

int main(){
	ll t=1;//cin>>t;
	while(t--){
		solve();
	}
}

