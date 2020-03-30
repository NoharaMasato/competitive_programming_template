// https://atc001.contest.atcoder.jp/tasks/dfs_a

#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// start
#define MAX_H 500
int H,W;
string s[MAX_H]; // map
int nw[4]={1,-1,0,0},nh[4]={0,0,1,-1};

// gが見つかったら1を返す
bool dfs(int nowh,int noww){
  bool result(false);
  if (s[nowh][noww]=='g') result=true;
  s[nowh][noww]='#';
  for (int i(0);i<4;i++){
    int nextw=noww+nw[i],nexth=nowh+nh[i];
    if (nextw<0||nextw>=W||nexth<0||nexth>=H) continue;
    if (s[nexth][nextw]!='#'){
      result |= dfs(nexth,nextw);
    }
  }
  return result;
}
// end

int main(){
  cin>>H>>W;
  for (int i(0);i<H;i++) cin>>s[i];
  for (int h(0);h<H;h++){
    for (int w(0);w<W;w++){
      if (s[h][w] == 's'){
        cout << (dfs(h,w)? "Yes" : "No") << endl;
      }
    }
  }
  return 0;
}
