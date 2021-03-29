// このサイトの解説が良い
// https://ferin-tech.hatenablog.com/entry/2017/01/24/184750

#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


int N,M;
vector<int> G[100001];
vector<int> d(100001,-1);

int main(){
  cin>>N>>M;
  vector<int> h(N+1,0); //頂点の入次数をカウント
  for(int i(0);i<N+M-1;i++){
    int a,b;
    cin>>a>>b;
    G[a].push_back(b);
    h[b]++;
  }

  stack<int> st; //入次数が0の頂点の集合
  for(int i(1);i<=N;i++){
    if(h[i] == 0){
      st.push(i);
    }
  }
  vector<int> dag; //dagは一意に定まらない(パターン数はbitDPで数えられる)
  while(st.size() != 0){
    int now = st.top();st.pop();
    dag.push_back(now);
    for(int j: G[now]) {
      h[j]--; //隣接する頂点の入次数をマイナス1
      if(h[j] == 0) st.push(j); //これによって入次数が0になればstに追加
    }
  }
  // dagのサイズがノード数と同じであれば、DAGであり、閉路が存在しない
  for(int v:dag) cout << v << " ";
  cout << endl;
  cout << endl;
  return 0;
}
