// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=jp
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define INFint 2e9+1

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

// クラスカル法(辺を小さい順に並び替え、行き先が、同じ連結成分ではなかったらその辺を追加する。連結成分判定はUnionFindを使う)
// 参考(蟻本p101)
struct edge{int cost, from, to;};
int comp(const edge& e1, const edge& e2){
  return e1.cost < e2.cost;
}
int main(){
  int V,E;
  cin>>V>>E;
  vector<edge> e(E);
  for(int i(0);i<E;i++){
    int s,t,w;
    cin>>s>>t>>w; // 入力のノード番号がすでに0-indexed
    e[i] = {w, s, t};
  }
  ll sum(0);
  UnionFind uf(V);
  sort(e.begin(), e.end(), comp); // コストを基準に並び替え
  for (int i(0);i<E;i++){
    if (uf.sameroot(e[i].from, e[i].to) == false){
      uf.unite(e[i].from, e[i].to);
      sum += e[i].cost;
    }
  }
  cout << sum << endl;
  return 0;
}
