#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define INFint 1e9+7

// start

int main(){
// start
  struct edge {int to,cost;};
  int N;
  cin>>N;
  vector<vector<edge>> G(N,vector<edge>());

  vector<int> d(N); //各頂点の最小値を入れる配列
  // first: cont, second: node number 
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

  d[s] = 0;
  q.push({0,s});

  while(!q.empty()){
    pair<int,int> p = q.top();q.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    for (int i(0);i<int(G[v].size());i++){
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        q.push({d[e.to],e.to});
      }
    }
  }
//end
}
