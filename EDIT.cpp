#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


//solved

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    while(cin>>s){
    	ll n = s.length();
    	ll lc =0 , uc = 0;

    	for(ll i =0 ;i<n ;i++){
    		if(i%2==0){
    			if(s[i]<'a') lc++ ;
    			if(s[i]>='a') uc++;
    		}
    		else{
    			if(s[i]>='a') lc++;
    			if(s[i]<'a') uc++;
    		}
    	}

    	if(lc<uc) cout<<lc<<endl;
    	else cout<<uc<<endl;
    }
    


}