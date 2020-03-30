 // https://atc001.contest.atcoder.jp/tasks/dfs_a
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// start
queue <pair<int,int>> q;
q.push({sx-1,sy-1});

while(!q.empty()){
  pair<int,int> now = q.front();
  q.pop();
  if (s[now.second][now.first]=='#') continue;
  //cout << now.first << " " << now.second<< endl;
  s[now.second][now.first]='#';
  for (int i(0);i<4;i++){
    pair<int,int> next = {now.first + nlx[i],now.second+nly[i]};
    if (next.first < 0 || next.first >= C || next.second < 0 || next.second >= R) continue; //ここでは次のマスに進めるかどうかを見ていない。
    cnt[next.second][next.first] = cnt[now.second][now.first]+1;
    if (next.first == gx - 1 && next.second == gy - 1){
      cout << cnt[next.second][next.first] << endl;
      return 0;
    }
    q.push(next);
  }
}
// end
