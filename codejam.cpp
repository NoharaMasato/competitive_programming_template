// codejam

#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll mod=1e9+7;
#define pa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};

void solve() {
  int N,A[10000];
  cin>>N;
  for (int i(0);i<N;i++) cin>>A[i];
  cout << ans << endl;
}

int main() {
    int T; cin >> T;
    for (int _ = 0; _ < T; ++_) {
        cout << "Case #" << _+1 << ": ";
        solve();
    }
}

