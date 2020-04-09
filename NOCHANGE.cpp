#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

	ll amount;
	cin>>amount;
	ll a,sum=0;
	vector<ll> coins(5)
	while(cin>>a){
		coins.push_back(a);
		sum+=a;
	}

	if(sum>amout){
		cout<<"NO"<<endl;
		return 0;
	}

	
}