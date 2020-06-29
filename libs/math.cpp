#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 【素因数分解】一つ目の値が素因数、２つ目の値がその個数
template <typename T>
map<T,T> prime_factor(T n){
  map<T,T> res;
  for (T i(2);i*i<=n;i++){
    while(n%i==0){
      ++res[i];
      n/=i;
    }
  }
  if (n!=1) res[n]=1;
  return res;
}

// 素数かどうか判定
template <typename T>
bool isprime(T n) {
  if (n == 1)return false;
  for (T i = 2; i * i <= n; i++) {
    if (n % i == 0)return false;
  }
  return true;
}

template <typename T>
T countDivisors(T n){
  T cnt = 0;
  for (T i = 1; i*i<=n; i++) {
    if (n % i == 0) {
      if (n / i == i) cnt++;
      else cnt = cnt + 2;
    }
  }
  return cnt;
}

// 約数列挙
vector<T> divisor(T n){
  vector<T> res;
  for (T i(1);i*i<=n;i++){
    if (n%i==0){
      res.push_back(i);
      if (i != n/i) res.push_back(n/i);
    }
  }
  return res;
}

int main(){
  map<int,int> m = prime_factor(100000);
  for(auto mi:m) cout << mi.first << " " << mi.second << endl;

  map<ll,ll> p = prime_factor((ll)1000000000000000);
  for(auto mi:p) cout << mi.first << " " << mi.second << endl;

  cout << isprime(333335) << " " << isprime(37) << endl;
  return 0;
}
