// https://atcoder.jp/contests/abc041/tasks/abc041_d
// https://kkt89.hatenablog.com/entry/2019/08/02/012207(回答参考)

#include <bits/stdc++.h>
using ll = long long;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
using namespace std;

int main(){
  bool bad[16][16] = {0};
  ll dp[1<<16] = {0};
  int n,m; cin >> n >> m;
  for(int i=0;i<m;i++){
    int x,y; cin >> x >> y;
    x--; y--;
    bad[y][x]=true; // bad[y][x] = trueの時はyからxには行ってはいけない
  }
  dp[0]=1;
  for(int i=0;i<(1<<n);i++){
    for(int j=0;j<n;j++){
      if(!(1&(i>>j))){ // iの状態でまだ通っていなければ
        bool ok=true; // iの状態からjに行くことはトポロジカルソートをする上でOKなのか
        for(int k=0;k<n;k++){
          if(1&(i>>k) && bad[k][j]) ok=false; // ノードkがすでに通っているかつ、kからjに行くことはトポロジカルソートに反している場合
        }
        if(ok) dp[i | (1<<j)]+=dp[i]; // iの状態からノードjに行くように配る
      }
    }
  }
  cout << dp[(1<<n)-1] << endl;
} 
