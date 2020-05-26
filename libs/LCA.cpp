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

void dfs(int v,int p,int d){ //v : 現在の頂点, p : 親の頂点, d : vの深さ
  parent[0][v] = p;
  depth[v] = d;
  for(int i(0);i<int(G[v].size());i++){
    if(p != G[v][i]) dfs(G[v][i], v, d+1);
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
    if(p == -1){
      root = i;
    }else{
      p--;
      G[p].push_back(i);
      G[i].push_back(p);
    }
  }

  // init parent

  dfs(root, -1, 0);
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
