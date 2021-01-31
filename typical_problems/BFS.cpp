 // https://atc001.contest.atcoder.jp/tasks/dfs_a
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
  int H,W;
  string s[500];
  cin>>H>>W;
  int sx,sy;
  for (int i(0);i<H;i++) cin>>s[i];
  for (int h(0);h<H;h++){
    for (int w(0);w<W;w++){
      if (s[h][w] == 's'){
        sy = h;
        sx = w;
      }
    }
  }

// start
  // sx ,sy : start
  int nx[] = {1,-1,0,0};
  int ny[] = {0,0,-1,1};
  queue <pair<int,int>> q;
  q.push({sy,sx});
  s[sy][sx] = '#';
  while(!q.empty()){
    pair<int,int> now = q.front();q.pop();
    for (int i(0);i<4;i++){
      pair<int,int> next = {now.first + ny[i],now.second+nx[i]};
      if (next.first < 0 || next.first >= H || next.second < 0 || next.second >= W) continue;
      if (s[next.first][next.second] != '#'){
        q.push(next);
        if (s[next.first][next.second] == 'g'){
          cout << "Yes" << endl;
          return 0;
        }
        s[next.first][next.second]='#';
      }
    }
  }
  cout << "No" << endl;
// end
}
