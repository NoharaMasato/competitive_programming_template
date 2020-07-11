// ナップサック問題いろんな制約
// https://atcoder.jp/contests/abc032/tasks/abc032_d
#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


ll dp[201][200001] = {0};
int main(){
  ll N,W;
  cin>>N>>W;
  vector<int> v(N),w(N);
  bool vflag(true);
  for(int i(0);i<N;i++){
    cin>>v[i]>>w[i];
    if(v[i] > 1000) vflag = false;
  }
  if(N <= 30){ //半分前列挙
    int n2 = N/2;
    vector<pair<ll,ll>> ps(1<<n2);
    for(int i(0);i<(1<<n2);i++){
      ll sw = 0,sv = 0;
      for(int j(0);j<n2;j++){
        if(i>>j&1){
          sw += w[j];
          sv += v[j];
        }
      }
      ps[i] = {sw,sv};
    }
    sort(ps.begin(),ps.end());

    // 重さが重くなっているのに、価値が小さくなっているものはいらない（二分探索をするときに邪魔になる)
    int m = 1;
    for(int i(0);i<1<<n2;i++){
      if(ps[m-1].second < ps[i].second){
        ps[m++] = ps[i];
      }
    }

    ll ans(0);
    for(int i(0);i<1<<(N-n2);i++){
      ll sw(0),sv(0);
      for(int j(0);j<N-n2;j++){
        if(i>>j&1) {
          sw += w[n2+j];
          sv += v[n2+j];
        }
      }
      if(sw <= W){
        ll tv = (lower_bound(ps.begin(),ps.begin()+m,make_pair(W-sw,INFll)) - 1)->second;
        ans = max(ans,sv+tv);
      }
    }
    cout << ans << endl;
  }else if(vflag){  // dp[i][v] : i,vの時のwの最小値
    for(int i(0);i<=200;i++){
      for(int j(0);j<=200000;j++){
        dp[i][j] = INFll;
      } 
    }
    dp[0][0] = 0;
    for(int i(0);i<N;i++){
      for(int j(0);j<=N*1000;j++){
        dp[i+1][j] = dp[i][j];
        if(j-v[i]>=0){
          dp[i+1][j] = min(dp[i+1][j],dp[i][j-v[i]]+w[i]);
        }
      }
    }
    ll ans(0);
    for(int i(200000);i>=0;i--){
      //cout << dp[N][i] << " ";
      if(dp[N][i] <= W){
        ans = i;
        break;
      }
    }
    cout << ans << endl;
  }else{ // dp[i][w] i,wの時のvの最大値
    for(int i(0);i<N;i++){
      for(int j(0);j<=N*1000;j++){
        dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
        if(j-w[i] >= 0){
          dp[i+1][j] = max(dp[i+1][j],dp[i][j-w[i]]+v[i]);
        }
      }
    }
    ll ans(0);
    for(int i(0);i<=W;i++){
      ans = max(ans,dp[N][i]);
    }
    cout << ans << endl;
  }
  return 0;
}

