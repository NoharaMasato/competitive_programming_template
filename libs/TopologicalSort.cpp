// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=ja
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> ans; //トポロジカルソートされた値が入る
vector<int> G[100000], Gr[100000]; //DAGとなる, Grは根を判別するために逆向きで入れておく
bool pathed[100000] = {0};

void dfs(int now){
  pathed[now] = true;
  for(auto next:G[now]){
    if(pathed[next] == false) dfs(next);
  }
  ans.push_back(now);
}

int main(){
  int N, M;
  cin>>N>>M;
  for(int i(0);i<M;i++){
    int s,t;
    cin>>s>>t;
    // s--;t--;
    G[s].push_back(t);
    Gr[t].push_back(s);
  }
  for(int i(0);i<N;i++){ //連結だとしてもDAGは一点をスタートして全ての点を訪れられるわけではないので、この部分は必ずいる
    if(int(Gr[i].size()) == 0){
      dfs(i);
    }
  }
  for(int i(N-1);i>=0;i--){ //逆順で出力する
    cout << ans[i] << endl;
  }
  return 0;
}
