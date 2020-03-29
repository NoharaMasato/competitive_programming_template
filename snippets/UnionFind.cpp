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
