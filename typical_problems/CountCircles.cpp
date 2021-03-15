// https://atcoder.jp/contests/arc114/tasks/arc114_b (この問題は2**(cyecle数)-1が答え)
// 有向グラフに置いて、閉路の数をカウントする
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// ある一回のdfsにおいて、同じ場所に戻ってくるということは閉路があるということ
vector<int> G[200000];
bool pathed[200000] = {0}; // 一回でも通ったノード
bool pathed_now[200000] = {0}; // ある一回のdfsに置いて通った場所
int cycles_cnt = 0;

void dfs(int now){
  if (pathed[now]) return;
  pathed[now] = true;
  pathed_now[now] = true;
  for (int next:G[now]) {
    if (pathed_now[next]) cycles_cnt++;
    else if (pathed[next] == false) dfs(next);
  }
  pathed_now[now] = false;
}


int main(){
  int N; // ノード数
  cin>>N;
  for(int i(0);i<N;i++){
    int f; cin>>f; f--;
    G[i].push_back(f);
  }
  for (int i = 0; i < N; i++) {
    dfs(i);
  }
  cout << cycles_cnt << endl;
  return 0;
}
