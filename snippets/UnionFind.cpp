// https://atcoder.jp/contests/abc157/tasks/abc157_d

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
  int N,M,K; cin>>N>>M>>K;
  UnionFind uf=UnionFind(N);
  vector<int> root_cnt(N,0),friend_cnt(N,0),bad_cnt(N,0);
  int a,b;
  for (int i = 0; i < M; ++i) {
    cin>>a>>b; --a; --b;
    uf.unite(a,b);
    friend_cnt[a]++; friend_cnt[b]++;
  }
  for(int i=0;i<N;++i){
    root_cnt[uf.root(i)]++;
  }
  for (int i = 0; i < K; ++i) {
    cin>>a>>b; --a; --b;
    if(uf.sameroot(a,b)){
      bad_cnt[a]++;
      bad_cnt[b]++;
    }
  }
  for (int i = 0; i < N; ++i) {
    cout<<root_cnt[uf.root(i)]-1-friend_cnt[i]-bad_cnt[i]<<" ";
  }
  cout<<endl;
  return 0;
}
