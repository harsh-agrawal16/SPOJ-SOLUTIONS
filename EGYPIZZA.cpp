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
	ll n;
	cin>>n;

	ll ans = 1;
	ll three = 0 , two = 0 , one = 0;

	for0(i,n){
		string a;
		cin>>a;

		if(a=="1/2") two++;
		else if(a=="1/4") one++;
		else three++;
	}

	ans+=(three);

	if(one>=three) one-=three;
	else one = 0;

	ans+=(two/2);

	if(two%2==1){
		ans+=1;
		one = max(0ll, one - 2);
	}

	ans+=((ceil) ((double) one/4));
	cout<<ans<<endl;

}

int main(){
	fastIO;
	ll t;
	t=1;
	while(t--){
		solve();
	}
}

