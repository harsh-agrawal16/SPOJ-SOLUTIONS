/*Author :- Harsh Agrawal
  Question:- SPOJ ELEVTRBL
  */

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll f,s,g,u,d,curr;
  cin>>f>>s>>g>>u>>d;

  ll clicks[f+1]; //to keep count of the no of button presses to reach the respective floor
  bool visited[f+1]; // to keep track of visited nodes
  memset(visited,false,sizeof(visited));
  queue<ll> q;

  clicks[s]=0;
  q.push(s);
  visited[s]=true;
  while(!q.empty()){
    curr = q.front();
    q.pop();

    if(curr==g){
      found = true;
      break;
    }

    if(curr+u<=f && !visited[curr+u]){
      visited[curr+u] = true;
      clicks[curr+u] = clicks[curr]+1;
      q.push(curr+u);
    }

    if(curr-d>=1 && !visited[curr-d]){
      visited[curr-d] = true;
      clicks[curr-d] = clicks[curr]+1;
      q.push(curr-d);
    }
    }
  }

  if(found){
    cout<<clicks[g]<<endl;
  }
  else{
  	cout<<"use the stairs"<<endl;
  }

}
