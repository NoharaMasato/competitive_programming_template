// (参考) https://algo-logic.info/segment-tree/
// 抽象化セグ木(セグメント木にはモノイドがのる)
// モノイド: 1. 結合則 a * (b * c) = (a * b) * c, 2: 単位元が存在する
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define INFint 2e9+1

// start
template <typename T>
struct SegmentTree {
  int n;
  vector<T> node;
  using FX = function<T(T, T)>; // T•T -> T となる関数の型
  FX fx;
  const T ex; // 単位元(RMQの時はex=INFint)

  // 元配列 v をセグメント木で表現する
  SegmentTree(vector<T> v, FX fx_, T ex_): fx(fx_), ex(ex_) {
    int sz = v.size();
    n = 1; while(n < sz) n *= 2; // 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n とおく
    node.resize(2 * n - 1, ex); // セグメント木全体で必要なノード数は 2n-1 個である

    for(int i = 0; i < sz; i++) node[i + n - 1] = v[i]; // 配列そのままが入るのはindex n-1から
    for(int i = n - 2; i >= 0; i--) node[i] = fx(node[2 * i + 1], node[2 * i + 2]); // 下の段から順に初期値を計算していく(根はnode[0])
  }
  void update(int x, T val) {
    x += n - 1; // 最下段のノードにアクセスする
    node[x] = val;
    while(x > 0) {
      x = (x - 1) / 2; // 自分の親ノードに行く
      node[x] = fx(node[2 * x + 1], node[2 * x + 2]);
    }
  }
  T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
  T query_sub(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return ex;
    if (a <= l && r <= b) return node[k];
  
    T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
    return fx(vl, vr);
  }
  T get(int x) { // もとの配列のx番目(0-indexed)の値を返す
    return node[x + n - 1];
  }
  void print(){ // 最下段[n-1,2n-1)のn個を出力する
    for(int i(0); i < n; i++) cout << node[i + n - 1] << " ";
    cout << endl;
  }
  void printall(){ // 全てのノードの値を出力する
    for(int i(0); i<2 * n; i++) cout << node[i] << " ";
    cout << endl;
  }
};
// end

// 一例として、RMQをとく
// https://judge.yosupo.jp/problem/staticrmq
int main() {
  int N,Q;
  cin>>N>>Q;
  vector<int> a(N);
  for(int i(0);i<N;i++){
    cin>>a[i];
  }
  auto fx = [](int x1, int x2) -> int { return min(x1, x2); };
  int ex = numeric_limits<int>::max();
  SegmentTree<int> st(a,fx,ex);
  for(int i(0);i<Q;i++){
    int l,r;
    cin>>l>>r;
    cout << st.query(l,r) << endl;
  }
  return 0;
}
