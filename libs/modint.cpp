// https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a#8-modint けんちょんさんのqiita
// https://noshi91.hatenablog.com/entry/2019/03/31/174006 noshiさんのハテナ
#include <bits/stdc++.h>
const int MOD=1e9+7;
using namespace std;
using ll = long long;

// constexprを使っているのでMODを動的に決めることはできない(modを同的に決めたい時はnoshiさんのブログ↑を参考にする)
// start
template<int MOD> struct Fp {
  long long val;
  constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
    if (val < 0) val += MOD;
  }
  constexpr Fp operator - () const noexcept { // -bのように-1をかけるときに呼び出される
    return val ? MOD - val : 0;
  }
  constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; } // 引数にint型を入れてもcastされてFp型になる
  constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
  constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
  constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
  constexpr Fp& operator += (const Fp& r) noexcept {
    val += r.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }
  constexpr Fp& operator -= (const Fp& r) noexcept {
    val -= r.val;
    if (val < 0) val += MOD;
    return *this;
  }
  constexpr Fp& operator *= (const Fp& r) noexcept {
    val = val * r.val % MOD;
    return *this;
  }
  constexpr Fp& operator /= (const Fp& r) noexcept { // rの逆元を拡張Euclidの控除法により求めて、valと掛け算を行っている
    long long a = r.val, b = MOD, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    val = val * u % MOD;
    if (val < 0) val += MOD;
    return *this;
  }
  constexpr bool operator == (const Fp& r) const noexcept {
    return this->val == r.val;
  }
  constexpr bool operator != (const Fp& r) const noexcept {
    return this->val != r.val;
  }
  friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
    return os << x.val;
  }
  friend constexpr istream& operator >> (istream &is, Fp<MOD>& x) noexcept {
    is >> x.val;
    x.val %= MOD;
    return is;
  }
  friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept { //aのn乗O(log(n)), friend関数なので、引数を入れると勝手に呼ばれる
    if (n == 0) return 1;
    auto t = modpow(a, n / 2);
    t = t * t;
    if (n & 1) t = t * a;
    return t;
  }
};
using mint = Fp<MOD>;
// end

int main() {
  mint a = 423343;
  mint b = 74324;
  mint c = 13231;
  mint d = 8432455;
  mint e;
  cin>>e;
  cout << e << endl;
  cout << (a * b + c) / d << endl;
}
