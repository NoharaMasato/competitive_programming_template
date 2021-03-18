// https://atcoder.jp/contests/abc013/tasks/abc013_4 (阿弥陀くじを縦にD個繋げて、最終的に行く場所を求める問題)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lld = long double;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
const int MOD=998244353;

int main(){
  int N,M,D;
  cin>>N>>M>>D;
  vector<int> A(M);
  for(int i(0);i<M;i++){
    cin>>A[i];
    A[i]--;
  }
  vector<int> X(N);
  for(int i(0);i<N;i++) X[i] = i;
  for(int i(0);i<M;i++){
    swap(X[A[i]], X[A[i]+1]);
  }
  // 全写像のような有効グラフにおいて、全地点からD回(D < 1e9)進んだところを求めるためにダブリングを行う
  vector<vector<int>> next(30, vector<int>(N, 0)); // next[i][j]: 点jから(1<<i)進んだ地点
  for(int i(0);i<N;i++) next[0][X[i]] = i;
  for(int i(1);i<30;i++){
    for(int j(0);j<N;j++){
      next[i][j] = next[i-1][next[i-1][j]];
    }
  }
  for(int i(0);i<N;i++){
    int j = 0, now = i;
    while (D>>j > 0){
      if (D>>j & 1) now = next[j][now]; // D回進みたいので、Dの右からj桁目にbitが立っていれば、nowを進める
      j++;
    }
    cout << now + 1 << endl;
  }
}
