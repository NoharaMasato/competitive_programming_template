// https://judge.yosupo.jp/problem/staticrmq

#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define INFint 2e9+1

// start
struct SegmentTree {
private:
  int n;
  vector<int> node;

public:
  // 元配列 v をセグメント木で表現する
  SegmentTree(vector<int> v) {
    // 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n とおく
    // セグメント木全体で必要なノード数は 2n-1 個である
    int sz = v.size();
    n = 1; while(n < sz) n *= 2;
    node.resize(2*n-1, INFint);

    // 最下段に値を入れたあとに、下の段から順番に値を入れる
    // 値を入れるには、自分の子の 2 値を参照すれば良い
    for(int i=0; i<sz; i++) node[i+n-1] = v[i]; // 配列そのままが入るのはindex n-1から
    for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
  }
  void update(int x, int val) {
    // 最下段のノードにアクセスする
    x += (n - 1);

    // 最下段のノードを更新したら、あとは親に上って更新していく
    node[x] = val;
    while(x > 0) {
      x = (x - 1) / 2;
      node[x] = min(node[2*x+1], node[2*x+2]);
    }
  }
  int getmin(int a, int b, int k=0, int l=0, int r=-1) {
    // 最初に呼び出されたときの対象区間は [0, n)
    if(r < 0) r = n;

    // 要求区間と対象区間が交わらない -> 適当に返す
    if(r <= a || b <= l) return INFint;
    // 要求区間が対象区間を完全に被覆 -> 対象区間を答えの計算に使う
    if(a <= l && r <= b) return node[k];

    // 要求区間が対象区間の一部を被覆 -> 子について探索を行う
    // 左側の子を vl ・ 右側の子を vr としている
    // 新しい対象区間は、現在の対象区間を半分に割ったもの
    int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
    int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
    return min(vl, vr);
  }
};
// end

int main() {
  int N,Q;
  cin>>N>>Q;
  vector<int> a(N);
  for(int i(0);i<N;i++){
    cin>>a[i];
  }
  SegmentTree st(a);
  for(int i(0);i<Q;i++){
    int l,r;
    cin>>l>>r;
    cout << st.getmin(l,r) << endl;
  }
  return 0;
}
