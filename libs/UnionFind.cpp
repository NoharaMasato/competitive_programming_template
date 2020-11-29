// https://judge.yosupo.jp/problem/unionfind

#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// union findの計算量工夫方法として経路圧縮とランクが大きい方につなげるという二つがあり、これを両方することで
// 一回の計算量がアッカーマンの逆関数になる。これはランクしか行っていない
// start
struct UnionFind{
  vector<int> par;
  vector<int> siz;

  UnionFind(int N){
    par.resize(N);siz.resize(N);
    for(int i=0;i<N;i++) par[i]=i;
    for(int i=0;i<N;i++) siz[i]=1;
  }

  int root(int x){
    if(par[x]==x) return x;
    else return par[x]=root(par[x]);
  }

  bool unite(int x,int y){
    int rx=root(x);
    int ry=root(y);
    if (rx == ry) return false;
    if(siz[rx] < siz[ry]) swap(rx,ry);
    siz[rx] += siz[ry];
    par[ry] = rx;
    return true;
  }

  bool sameroot(int x,int y){
    return root(x)==root(y);
  }

  int size(int x){
    return siz[root(x)];
  }
};
// end

int main() {
  int N,Q;
  cin>>N>>Q;
  UnionFind uf(N);
  for(int i(0);i<Q;i++){
    int t,u,v;
    cin>>t>>u>>v;
    if(t == 0){
      uf.unite(u,v);
    }else if(t == 1){
      if(uf.sameroot(u,v)) cout << 1 << endl;
      else cout << 0 << endl;
    }
  }
  return 0;
}
