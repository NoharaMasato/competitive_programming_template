#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
const int MOD=1e9+7;

typedef vector<vector<int>> mat;

// 行列AとBの掛け算
mat mul(mat &A, mat &B){
  mat C(A.size(), vector<int>(B[0].size()));
  for(int i(0);i<int(A.size());i++){
    for(int j(0);j<int(B.size());j++){
      for(int k(0);k<int(B[0].size());k++){
        C[i][k] += A[i][j] * B[j][k];
        C[i][k] %= MOD;
      }
    }
  }
  return C;
}

mat pow(mat A, ll n){
  mat B(A.size(), vector<int>(A.size()));
  for(int i(0);i<int(A.size());i++){
    B[i][i] = 1;
  }
  while(n > 0){
    if(n & 1) B = mul(B, A);
    A = mul(A,A);
    n >>= 1;
  }
  return B;
}
int main(){
  ll n;
  cin>>n;
  mat A(2,vector<int>(2));
  A[0][0] = 1;
  A[0][1] = 1;
  A[1][0]  =1;
  A[1][1] = 0;
  A = pow(A, n);
  cout << A[1][0] << endl;
  return 0;
}
