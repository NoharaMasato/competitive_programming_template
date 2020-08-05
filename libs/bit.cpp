//https://github.com/atcoder/live_library/blob/master/bit.cpp
#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;

struct BIT {
  int n;
  vector<int> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, int x=1) {
    for (i++; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  int sum(int i) {
    int x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
  int sum(int l, int r) {
    return sum(r-1) - sum(l-1);
  }
};

int main(){
	BIT bit(10);
  cout << bit.sum(1,2) << endl;
  bit.add(1,4);
  cout << bit.sum(1,2) << endl;
  return 0;
}

