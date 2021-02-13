// https://atcoder.jp/contests/abc137/tasks/abc137_e
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
const int MOD=1e9+7;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};

vector<int> G[2500], Gr[2500];
bool flag[2500]={0}, flagr[2500]={0}; // flagはノード0から到達できるかどうか, flagrはノードN-1から逆方向に移動して到達できるかどうか
void dfs(int now){
  for(int next:G[now]){
    if(!flag[next]){
      flag[next] = true;
      dfs(next);
    }
  }
}
void dfsr(int now){
  for(int next:Gr[now]){
    if(!flagr[next]){
      flagr[next] = true;
      dfsr(next);
    }
  }
}
int main(){
  int N,M,P;
  cin>>N>>M>>P;
  struct edge {int from, to, cost;};
  vector<edge> E(M);
  for(int i(0);i<M;i++){
    int a,b,c; cin>>a>>b>>c; a--;b--;
    E[i] = {a, b,-(c-P)};
    G[a].push_back(b);
    Gr[b].push_back(a);
  }
  dfs(0);
  dfsr(N-1);
  vector<ll> d(N, INFll); // 最短距離を入れる
  d[0] = 0; // 0をスタートとする
  bool update(false);
  for(int i(0);i<=N;i++){
    update = false;
    for(int j(0);j<M;j++){
      edge e = E[j];
      if(d[e.from] != INFll && d[e.to] > d[e.from] + e.cost){
        d[e.to] = d[e.from] + e.cost;
        if(flag[e.to] && flagr[e.to]) update = true; // i==Nの時,最短経路がアップデートされているかつ、アップデートされている点が0からもN-1からも到達可能である
      }
    }
  }
  if(update) cout << -1 << endl;
  else cout << max(-d[N-1], 0ll) << endl;
  return 0;
}
