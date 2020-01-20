
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define pa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};

using ll = long long;
using namespace std;
using P = pair<int,int>;
ll mod=1e9+7;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; } //最大公約数
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; } //最大公倍数

int main(){
  int N,A[(int)2e5];
  cin>>N;
  for (int i(0);i<N;i++) cin>>A[i];
  return 0;
}
