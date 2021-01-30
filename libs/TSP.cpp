// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A&lang=ja
// 回答参考　http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2020816
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
  int V,E;
  cin>>V>>E;
  // dpは一個目が現在の通ったところのbit情報、２個目が現在の位置
  vector<vector<int>> dp(1<<V,vector<int>(V,1e9)), dst(V, vector<int>(V, 1e9));
  for(int i(0);i<E;i++){ //有向グラフなので、いけないパターンが存在する
    int s,t,d;
    cin>>s>>t>>d;
    dst[s][t] = d;
  }

  /* スタート地点に最後に戻らない場合(最短ハミルトン路問題)
    for(int i(0);i<V;i++) dp[1<<i][i] = 0; // と初期化する(全ての１点目は距離0でいけるという意味)
    // 答えは for(int i(0);i<V;i++) ans = min(ans, dp[(1<<V)-1][i]); // となる
  */
  int start = 0;
  dp[0][start] = 0; // 頂点0をスタートとする(どこも通っていない状態で0にいる)
  for(int i(1);i<(1<<V);i++){
    for(int j(0);j<V;j++){
      if(i&(1<<j)){ // iのなかにjが入っている時のみ考える(jが通過していないパターンは矛盾しているのであり得ない)
        for(int k(0);k<V;k++){
          dp[i][j] = min(dp[i][j], dp[i-(1<<j)][k]+ dst[k][j]); //集めるdpでkからjにくるパターンを考えている
        }
      }
    }
  }
  if(dp[(1<<V)-1][start] == 1e9) cout << -1 << endl; //1111....が初めの点をスタート時を含めて２回通った状態で頂点startにいる状況
  else cout << dp[(1<<V)-1][start] << endl;
  return 0;
}
