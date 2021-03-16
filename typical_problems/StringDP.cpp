// 文字列関係のDPまとめ
// LCS (Longest Common Subsequence) 連続していなくても良い
// LCS (Longest Common Substring) 連続している必要がある
// EditDistance(レーベンシュタイン距離)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;

// N*Mの文字列に対して、common suffixを計算している(それの最大値が答え)
int LongestCommonSubstring(string s, string t){
  int N = int(s.size()), M = int(t.size());
  vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
  for(int i(1);i<=N;i++){
    for(int j(1);j<=M;j++){
      if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
      else dp[i][j] = 0;
    }
  }
  int ret(0);
  for(int i(1);i<=N;i++)
    for(int j(1);j<=M;j++)
      ret = max(ret, dp[i][j]);
  return ret;
}

int LongestCommonSubsequence(string s, string t){
  int N = int(s.size()), M = int(t.size());
  vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
  for(int i(1);i<=N;i++){
    for(int j(1);j<=M;j++){
      if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
      else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
  }
  return dp[N][M];
}

// https://qiita.com/drken/items/a5e6fe22863b7992efdb (参考)
// https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_E (答え確認)
int EditDistance(string s, string t){
  int N = int(s.size()), M = int(t.size());
  vector<vector<int>> dp(N+1, vector<int>(M+1, INFint));
  dp[0][0] = 0;
  for(int i(0);i<=N;i++){
    for(int j(0);j<=M;j++){
      if (i > 0 && j > 0) {
        if (s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
        else dp[i][j] = dp[i-1][j-1] + 1;
      }
      if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
      if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
    }
  }
  return dp[N][M];
}

int main(){
  string s = "abcdefg";
  string t = "cdeg";
  cout << "Substring: " << LongestCommonSubstring(s, t) << endl;
  cout << "Subsequence: " << LongestCommonSubsequence(s, t) << endl;
  cout << "EditDistance: " << EditDistance(s, t) << endl;
}
