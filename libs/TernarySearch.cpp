// https://atcoder.jp/contests/arc054/tasks/arc054_b
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};

double P;
double f(double x){
  return x + P/pow(2, x/1.5);
}

// ３分探索(狭義の凸点, 凹点を正確に見つけることができる。(水平な部分があってはいけない）以下のコードは凹点)
// 候補の範囲を3分割して、ありえない一つを消していく。つまり、操作ごとに、探索範囲が2/3になっていく
int main(){
  cin>>P;
  double l = 0, r = P;
  while(r - l > 1/1e9){
    double c1 = (r-l)/3+l, c2 = (r-l)/3*2+l;
    if(f(c1) > f(c2)) l = c1;
    else r = c2;
  }
  cout << setprecision(10) << f(l) << endl;
  return 0;
}
