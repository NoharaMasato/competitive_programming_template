// (参考) https://algo-logic.info/segment-tree/
// https://atcoder.jp/contests/practice2/tasks/practice2_l
// 遅延抽象化セグ木
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define INFint 2e9+1

template <typename T>
struct SegmentTree {
  int n;
  vector<T> node;
  const T INF = numeric_limits<T>::max();

  // 元配列 v をセグメント木で表現する
  SegmentTree(vector<T> v) {
    int sz = v.size();
    n = 1; while(n < sz) n *= 2; // 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n とおく
    node.resize(2*n-1, INF); // セグメント木全体で必要なノード数は 2n-1 個である

    for(int i=0; i<sz; i++) node[i+n-1] = v[i]; // 配列そのままが入るのはindex n-1から
    for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]); // 下の段から順に初期値を計算していく(根はnode[0])
  }
  void update(int x, T val) {
    x += n - 1; // 最下段のノードにアクセスする
    node[x] = val;
    while(x > 0) {
      x = (x - 1) / 2; // 自分の親ノードに行く
      node[x] = min(node[2*x+1], node[2*x+2]);
    }
  }
  T getmin(int a, int b, int k=0, int l=0, int r=-1) { // 再帰を用いて、根から降りていき、[a,b)に完全にかぶっていると、その区間の値を返す
    if(r == -1) r = n; // 最初に呼び出されたときの対象区間は [0, n)。デフォルト引数にしたいが、デフォルト引数として、メンバ変数は使えないのでこういう実装になっている
    if(r <= a || b <= l) return INF; // 要求区間と対象区間が交わらない -> 適当に返す
    if(a <= l && r <= b) return node[k]; // 要求区間が対象区間を完全に被覆 -> 対象区間を答えの計算に使う

    T vl = getmin(a, b, 2*k+1, l, (l+r)/2); // 左側の子にアクセス
    T vr = getmin(a, b, 2*k+2, (l+r)/2, r); // 右側の子にアクセス
    return min(vl, vr);
  }
  void print(){ // 最下段[n-1,2n-1)のn個を出力する
    for(int i(0);i<n;i++) cout << node[i+n-1] << " ";
    cout << endl;
  }
  void printall(){ // 全てのノードの値を出力する
    for(int i(0);i<2*n;i++) cout << node[i] << " ";
    cout << endl;
  }
};

int main(){

}
