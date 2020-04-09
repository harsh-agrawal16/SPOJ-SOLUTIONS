#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

//solved.

int main() {
	//ull temp = (ull) pow(2,49);
	
	vector<ull> b(51);
	b[1] = 1;
	b[2] = 4;

	for(int i=3;i<51;i++){
		b[i] =  (ull) pow(2,i-1) + 2*b[i-1]; 
	}

    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;

    	cout<<(ull) pow(2,n-1)<<" "<<(ull) pow(2,n-1) + b[n-1]<<endl; 
    }


	return 0;
}