#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	ll t;
	cin>>t;
	while(t--){
		ll m,n;
		cin>>m>>n;

		vector<ll> x(m-1),y(n-1);
		for(ll i=0;i<m-1;i++) {cin>>x[i];}
		for(ll i=0;i<n-1;i++) {cin>>y[i];}

		sort(x.begin(),x.end());
		sort(y.begin(),y.end());

		ll i=m-2,j=n-2;
        ll ans=0;
		while((i>=0)&&(j>=0)){

			if(x[i]>y[j]){
				ans+=x[i];
				for(ll k=j;k>=0;k--){
					ans+=y[k];
				}
				i--;
			}

			if(x[i]<=y[j]){
				ans+=y[j];
				for(ll k=i;k>=0;k--){
					ans+=x[k];
				}
				j--;
			}

		}
		
		if(i>=0){
			while(i>=0){
				ans+=x[i];
				i--;
			}
		}
		
		if(j>=0){
			while(j>=0){
				ans+=y[j];
				j--;
			}
		}

		cout<<ans<<endl;


	}
}