// https://atcoder.jp/contests/abc146/tasks/abc146_c
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
  ll A,B,X;
  cin>>A>>B>>X;
// start
  ll l = 0,r = 1e9+1;
  while(l+1<r){
    ll x = (l+r)/2;
    bool ok = [&]{
      ll nedan = A*x + B*int(to_string(x).size());
      if (nedan <= X) return true;
      else return false;
    }();
    if (ok) l = x;
    else r = x;
  }
  cout << l << endl;
// end
  return 0;
}
