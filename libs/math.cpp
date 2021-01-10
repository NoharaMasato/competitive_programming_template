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

// 約数の個数カウント
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
template <typename T>
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

// ax + by = gcd(a, b) を満たす (x, y) が格納される(dは計算途中に使っているだけ)
// 一次不定方程式 ax + by = cの解(x,y)が存在する必要十分条件はc%gcd(a,b) = 0であること(つまり、cがaとbの最大公約数の倍数であること)
ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

int main(){
  map<int,int> m = prime_factor(100000);
  for(auto mi:m) cout << mi.first << " " << mi.second << endl;

  map<ll,ll> p = prime_factor((ll)1000000000000000);
  for(auto mi:p) cout << mi.first << " " << mi.second << endl;

  cout << isprime(333335) << " " << isprime(37) << endl;

  cout << countDivisors(12) << endl;

  vector<int> t = divisor(12);
  for(auto ti:t) cout << ti << " ";
  cout << endl;

  return 0;
}
