// https://judge.yosupo.jp/problem/point_add_range_sum
//https://github.com/atcoder/live_library/blob/master/bit.cpp (コード参考)
// feneck treeとも呼ばれる
#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;

template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, T x=1) {
    for (i++; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
  T sum(int l, int r) { // r-1からlの和を求める
    return sum(r-1) - sum(l-1);
  }
};

int main(){
  int N,Q;
  cin>>N>>Q;
	BIT<ll> bit(N);
  for(int i(0);i<N;i++){
    ll a;
    cin>>a;
    bit.add(i,a);
  }
  for(int i(0);i<Q;i++){
    int x;
    cin>>x;
    if(x == 0){
      ll p,x;
      cin>>p>>x; // a[p] += x
      bit.add(p,x);
    }else if(x == 1){
      int l,r;
      cin>>l>>r; // sum [l, r) 半開区間
      cout << bit.sum(l,r) << endl;
    }
  }
  return 0;
}
