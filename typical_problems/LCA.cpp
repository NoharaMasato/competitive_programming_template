// https://atcoder.jp/contests/past201912-open/tasks/past201912_k
#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;

#define MAX_V 150001
#define MAX_LOG_V 50

vector<int> G[MAX_V];
int root;
int N;

int parent[MAX_LOG_V][MAX_V]; //parent[k][v] : vから親を2^k回辿って到達する頂点
int depth[MAX_V];

void dfs(int now, int par, int d){ //now: 現在の頂点, par: 親の頂点, d: nowの深さ
  parent[0][now] = par; // nowから親を2の0乗回たどるとpになる
  depth[now] = d;
  for(int next:G[now]){
    if(par != next) dfs(next, now, d+1);
  }
}

int lca(int u, int v){ //uとvのlca
  if(depth[u] > depth[v]) swap(u,v);
  for(int k(0);k<MAX_LOG_V;k++){
    if((depth[v] - depth[u]) >> k&1){
      v = parent[k][v];
    }
  }
  if(u == v) return u;
  for(int k = MAX_LOG_V -1 ;k>= 0;k--){
    if(parent[k][u] != parent[k][v]){
      u = parent[k][u];
      v = parent[k][v];
    }
  }
  return parent[0][u];
}

int main(){
  cin>>N;
  for(int i(0);i<N;i++){
    int p;
    cin>>p;
    if(p == -1){ //親が-1のものは木の根となる
      root = i;
    }else{
      p--;
      G[p].push_back(i);
      G[i].push_back(p);
    }
  }
  dfs(root, -1, 0); // 各ノードの深さを求める
  for(int k(0);k+1<MAX_LOG_V;k++){
    for(int v(0);v<N;v++){
      if(parent[k][v] < 0) parent[k+1][v] = -1;
      else parent[k+1][v] = parent[k][parent[k][v]];
    }
  }

  int Q;
  cin>>Q;
  for(int i(0);i<Q;i++){
    int a,b;
    cin>>a>>b;
    a--;b--;
    if(lca(a,b) == b){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
  return 0;
}
