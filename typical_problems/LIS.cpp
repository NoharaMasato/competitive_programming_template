#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;

#define MAX_V 150001
#define MAX_LOG_V 50

// https://drken1215.hatenablog.com/entry/2019/04/17/231900 (参考) これに復元を加えた
// https://perogram.hateblo.jp/entry/2019/07/27/051604 (復元に関して参考)
// dp[i] := 長さが i の増加部分列として最後尾の要素のとりうる最小値
// is_strong = trueだと、最長増加部分列, is_strong = falseだと最も長い、減少しない部分列
template<class T> vector<T> LIS(vector<T> a,  bool is_strong = true) {
  const T INF = 1<<30; // 適切に設定する
  int N = (int)a.size();
  vector<T> dp(N, INF);
  vector<int> idx(N); // 復元用
  for (int i = 0; i < N; ++i) {
    if (is_strong) idx[i] = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
    else idx[i] = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
    dp[idx[i]] = a[i];
  }
  int len = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
  vector<T> b(len); // 復元された配列
  for(int i(N-1);i>=0;i--){
    if(len-1 == idx[i]){
      b[len-1] = a[i];
      len--;
    }
  }
  return b;
}

int main(){
  vector<int> v = {4,2,3,1,5};
  for(int vi:LIS(v)) cout << vi << " ";
  cout << endl;
  v = {1,1,4,2,3,1,5};
  for(int vi:LIS(v, false)) cout << vi << " ";
  cout << endl;
  return 0;
}
