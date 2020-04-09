#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

//solved.

int main(){
	ll d;
	cin>>d;
	while(d--){
		ll a;
	
		vector<ll> agnes;
		cin>>a;
		while(a){
			agnes.push_back(a);
			cin>>a;
			//cout<<a<<" ";
		}
        ll n = agnes.size();  
      

		vector<vector<ll>> tom;
		vector<ll> t;
		while(1){
			
			cin>>a;
			if(a==0) break;
			
			
			while(a) {t.push_back(a); cin>>a;}
			tom.push_back(t);
			t.clear();
		}
        
        ll ans = 0;

		for(int i=0;i<tom.size();i++){
			vector<vector<ll>> temp(tom[i].size(), vector<ll>(n,-1));

			for(int j=0;j<temp.size();j++){
				for(int k =0;k<n;k++){
					if(tom[i][j] == agnes[k]){
						//temp[j][k] = ((j-1)>=0 && (k-1)>=0)? 1+temp[j-1][k-1] : 1;
						if((j-1)>=0 && (k-1)>=0) temp[j][k] = temp[j-1][k-1] + 1;
						else temp[j][k] = 1;
					}
					else{
						if(j-1>=0 && k-1>=0){
							temp[j][k] = max(temp[j-1][k-1], max(temp[j][k-1], temp[j-1][k]));
						}
						else if(j-1>=0){
							temp[j][k] = temp[j-1][k];
						}
						else if(k-1>=0){
							temp[j][k] = temp[j][k-1];
						}
						else temp[j][k] = 0;
					} 
				}
			}
            
            ans = max(ans, temp[temp.size()-1][n-1]);           

		}


		cout<<ans<<endl;

	}
}
