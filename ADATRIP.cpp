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
#define pb push_back
#define in(a) cin>>a
#define out(a) cout>>a;
#define vll vector<ll> 
#define vvll vector<vll>
#define qll queue<ll>
#define fastIO  ios_base::sync_with_stdio(0);\
                cin.tie(NULL);\
                cout.tie(NULL)
struct cmpp
{
	bool operator()(pair<ll,ll> a, pair<ll,ll> b){
		return a.second>b.second;
	}
};

void solve(ll s, vector<vector<pair<ll,ll>>> &adj, ll n){
	//Adatrip , do it using priority queue , to avoid TLE;
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>> , cmpp> pq;
	pq.push({s,0});
	vector<bool> u(n,false);
	vll d(n,LLONG_MAX);
	d[s] = 0;

	while(!pq.empty()){
		ll v = pq.top().first;
		pq.pop();
		if(d[v]==LLONG_MAX) break;

		u[v] = true;
		for(auto edge: adj[v]){
			ll len = edge.second;
			ll to = edge.first;

			if(d[v]+len < d[to] && !u[to]){
				d[to] = d[v]+len;
				pq.push({to,d[to]});
			}
		}
	}

    ll count = 1;ll mx = -1;
	for0(i,n){
		if(d[i]>mx && d[i]!=LLONG_MAX){
			count=1;
			mx = d[i];
		}
		else if(d[i]==mx){
			count++;
		}
	}
	cout<<mx<<" "<<count<<endl;
}


int main(){
	fastIO;
	ll n,m,q;
	cin>>n>>m>>q;
	vector<vector<pair<ll,ll>>> adj(n);
	for0(i,m){
		ll u,v,c;cin>>u>>v>>c;
		adj[u].pb({v,c});
		adj[v].pb({u,c});
	}
	for0(i,q){
		ll x; cin>>x;
		solve(x,adj,n);
	}
}
