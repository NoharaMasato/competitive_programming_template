// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_12_B
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define INFint 1e9+1

int main(){
// start
  struct edge {int to,cost;};
  int N;
  cin>>N;
  vector<vector<edge>> G(N,vector<edge>());
  for(int i(0);i<N;i++){
    int k,u;
    cin>>k>>u;
    for(int j(0);j<u;j++){
      int v,c;
      cin>>v>>c;
      G[k].push_back({v,c});
    }
  }
  vector<int> d(N); //各頂点の最小値を入れる配列
  fill(d.begin(),d.end(),INFint);
  // first: cont, second: node number 
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
  int start = 0;
  d[start] = 0;
  q.push({0,start});

  while(!q.empty()){
    pair<int,int> p = q.top();q.pop();                                                  
    int v = p.second;
    for (int i(0);i<int(G[v].size());i++){
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        q.push({d[e.to],e.to});
      }
    }
  }
// end
  for(int i(0);i<N;i++){
    cout << i <<" " << d[i] << endl;
  }
  return 0;
}

