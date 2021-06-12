#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
const int MOD=1e9+7;

// (参考) https://ei1333.github.io/library/dp/cumulative-sum-2d.cpp.html
template< class T >
struct CumulativeSum2D {
  vector< vector< T > > data;

  CumulativeSum2D(int W, int H) : data(W + 1, vector< int >(H + 1, 0)) {}

  // 初期化に使える
  void add(int x, int y, T z) {
    ++x, ++y;
    if(x >= (int)data.size() || y >= (int)data[0].size()) return;
    data[x][y] += z;
  }

  // 累積和を計算する
  void build() {
    for(int i = 1; i < (int)data.size(); i++) {
      for(int j = 1; j < (int)data[i].size(); j++) {
        data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
      }
    }
  }

  // 左下(sx, sy),右上(gx, gy)の矩形和を求める(半開区間で与えることに注意すること.具体的には列gxと行gyは含まない)
  T query(int sx, int sy, int gx, int gy) const {
    return (data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy]);
  }
};

int main()
{
  int N;
  cin>>N;
  CumulativeSum2D<int> sum(100, 100);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int a;
      cin>>a;
      sum.add(i, j, a);
    }
  }
  sum.build();
  cout << sum.query(0, 0, 1, 1) << endl; // (0,0)の点だけの和
  cout << sum.query(0, 0, 2, 2) << endl; // (0,0),(0,1),(1,0),(1,1)の4点の和
}
