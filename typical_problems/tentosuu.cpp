// https://atcoder.jp/contests/abc190/tasks/abc190_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
const int MOD=1e9+7;

template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, T x=1) {
    for (int idx(i+1); idx <= n; idx += idx&-idx) { // iを２進数にした時の、最下位に立っているbitに１を足す
      d[idx] += x;
    }
  }
  T sum(int i) {
    T x = 0;
    for (int idx(i+1); idx > 0; idx -= idx&-idx) {
      x += d[idx];
    }
    return x;
  }
  T sum(int l, int r) { // r-1からlの和を求める
    return sum(r-1) - sum(l-1);
  }
};

int main(){
  int N; cin>>N;
  vector<int> A(N);
  for(int i(0);i<N;i++) cin>>A[i]; // Aは順列である(順列でない場合は、何番目に大きいかを入れれば良い)
  ll ans = 0;
  BIT<int> b(N);
  for (int i = 0; i < N; i++) {
    ans += i - b.sum(A[i]);
    b.add(A[i]);
  }
  cout << ans << endl;

  // abc190 f用
  // for(int i(0);i<N;i++){
  //   cout << ans << endl;
  //   ans -= A[i];
  //   ans += N-A[i]-1;
  // }
  return 0;
}
