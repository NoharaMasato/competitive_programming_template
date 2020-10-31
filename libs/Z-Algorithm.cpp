// https://judge.yosupo.jp/problem/zalgorithm
#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


int main(){
  string s;
  cin>>s;
  int N = int(s.size());
  vector<int> A(N);
  A[0] = N;
  int i = 1, j = 0;
  while (i < N) {
    while (i+j < N && s[j] == s[i+j]) ++j;
    A[i] = j;
    if (j == 0) { ++i; continue;}
    int k = 1;
    while (i+k < N && k+A[k] < j) A[i+k] = A[k], ++k;
    i += k; j -= k;
  }
  for(int i(0);i<N;i++){
    cout << A[i] << " ";
  }
  cout << endl;
  return 0;
}

