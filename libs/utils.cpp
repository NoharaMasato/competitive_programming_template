#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// abs(A[i]-x)が最小のもののindexを返す（つまりはAの要素の中で、xに最も近い値のindexを返す。返り値は0から|A|-1の範囲)
// (注) Aは昇順にソート済みであるべき
int nearest(const vector<int> &A, int x){
  int N = int(A.size());
  int i = upper_bound(A.begin(), A.end(), x) - A.begin();
  if(i == N) return N-1;
  else if(i == 0) return 0;
  else{
    if(abs(A[i]-x) <= abs(A[i-1]-x)) return i;
    else return i-1;
  }
}

int main(){
  return 0;
}
