// https://qiita.com/pinokions009/items/1e98252718eeeeb5c9ab (参考)
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
const int MOD=1e9+7;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};

// 桁dp風にN以下の数の個数を出力するプログラム(答えはNに決まってるが)
int main(){
  string s;
  cin>>s;
  int N = int(s.size());
  int dp[1000][2] = {0};
  dp[0][0] = 1;
  for(int i = 0; i < N; i++){ // 配るdp
    int num = s[i]-'0';
    // for(int smaller = 0; smaller < 2; smaller++){
    //   for(int x = 0; x <= (smaller ? 9 : num); x++){
    //     dp[i + 1][smaller || x < num] += dp[i][smaller];
    //   }
    // }
    // 上みたいにsmallerをまとめない方がわかりやすいのでは
    for(int x = 0; x <= 9; x++){
      dp[i + 1][1] += dp[i][1]; // もうすでにsmallerの時は次の桁はなんでもsmallerになる
    }
    for(int x = 0; x < num; x++){
      dp[i + 1][1] += dp[i][0]; // smallerではない時は、次の桁はnumより小さいとsmallerになる
    }
    dp[i + 1][0] += dp[i][0]; // 現在smallerでもなく、次の桁もぴったしの時はsmallerではない
  }
  for(int i(0);i<=N;i++){
    cout << dp[i][0] << " " << dp[i][1] << endl;
  }
  cout << dp[N][0] + dp[N][1] - 1 << endl;
  return 0;
}
