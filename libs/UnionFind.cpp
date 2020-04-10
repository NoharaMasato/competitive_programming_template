// https://judge.yosupo.jp/problem/unionfind

#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// start
struct UnionFind{
  vector<int> par;

  UnionFind(int N): par(N){
    for(int i=0;i<N;i++) par[i]=i;
  }

  int root(int x){
    if(par[x]==x) return x;
    else return par[x]=root(par[x]);
  }

  void unite(int x,int y){
    int rx=root(x);
    int ry=root(y);
    if(rx!=ry) par[rx]=ry;
  }

  bool sameroot(int x,int y){
    return root(x)==root(y);
  }
};
// end

int main() {
  int N,Q;
  cin>>N>>Q;
  UnionFind uf=UnionFind(N);
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
