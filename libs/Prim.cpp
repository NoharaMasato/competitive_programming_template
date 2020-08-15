//https://atcoder.jp/contests/abc065/tasks/arc076_b
#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;

int main(){
  int N;
  cin>>N;
  vector<pair<int,int>> x,y;
  vector<int> X,Y;
  vector<pair<int,int>> G[100000];
  for(int i(0);i<N;i++){
    int xi,yi;
    cin>>xi>>yi;
    X.push_back(xi);
    Y.push_back(yi);
    x.push_back({xi,i});
    y.push_back({yi,i});
  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  for(int i(0);i<N-1;i++){
    G[x[i].second].push_back({x[i+1].first - x[i].first, x[i+1].second});
    G[x[i+1].second].push_back({x[i+1].first - x[i].first, x[i].second});

    G[y[i].second].push_back({y[i+1].first - y[i].first, y[i+1].second});
    G[y[i+1].second].push_back({y[i+1].first - y[i].first, y[i].second});
  }

  // ここからがプリム法(重み付きグラフGに関して)
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
  vector<int> used(N);
  q.push({0,0});
  ll ans(0); //全域最小コスト
  while(!q.empty()){
    pair<int,int> now = q.top();q.pop();
    int v = now.second;
    if(used[v] == 1) continue;
    used[v] = 1;
    ans += now.first;
    for(auto next:G[v]){
      int nv = next.second;
      if(used[nv] == 0){
        q.push({min(abs(X[nv]-X[v]),abs(Y[nv]-Y[v])),nv}); //コストの計算が独特(本来であれば、next.firstがコストとなる)
      }
    }
  }
  cout << ans << endl;
  return 0;
}
