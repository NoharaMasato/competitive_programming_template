// start
#define MAX_N 100
int N;
int d[MAX_N]; //各頂点の最小値を入れる配列
struct edge {int to,cost;};
vector<edge> G[MAX_N];

void dijkstra(int s){ //頂点sからの最短距離を配列dに入れる
  priority_queue<P,vector<P>,greater<P>> q;//値を小さい順に出すpairは一つ目がコスト、２つ目が頂点番号
  fill(d,d+N,INF);
  d[s] = 0;
  q.push(P(0,s));

  while(!q.empty()){
    P p = q.top();q.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    for (int i(0);i<G[v].size();i++){
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost){
        cout << e.to << "番目の頂点を" << d[e.to] << "から" << d[v] + e.cost << "に変更しました" << endl;
        d[e.to] = d[v] + e.cost;
        q.push(P(d[e.to],e.to));
      }
    }
  }
}

//end
