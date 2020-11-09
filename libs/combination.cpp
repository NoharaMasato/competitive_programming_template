// https://algo-logic.info/combination/
#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;

#define MAXN (int)1e7
long long fac[MAXN], finv[MAXN], inv[MAXN];
ll modcombi[2001][2001]={0}; //[i][j] iCj

void COMinit(){
  // 逆元を使ったフェルマー(MODが素数)
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAXN; i++){
      fac[i] = fac[i - 1] * i % MOD;
      inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
      finv[i] = finv[i - 1] * inv[i] % MOD;
  }

  // 二項定理で求める(i < 5000 && j < 5000) (MODが素数ではなくても良い)
  modcombi[0][0]=1;
  for(int i=1;i<=5000;i++){
    modcombi[i][0]=1;
    for(int j=1;j<=5000;j++){
      modcombi[i][j]=(modcombi[i-1][j-1]+modcombi[i-1][j])%MOD;
    }
  }
}

ll combination(int n,int k){// nCk
  if(n<=1e7){ // 逆元を使ったフェルマー(nが1e7以下の場合でMODが素数の場合は基本これ)
    if (n < k || n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
  }else if(n>1e7 && k <= 1e7){ // 上の参照ページをみるべし
    if (n < k || n < 0 || k < 0) return 0;

  }
}

int main(){
  COMinit();
  return 0;
}
