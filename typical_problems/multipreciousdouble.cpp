// https://atcoder.jp/contests/abc191/tasks/abc191_d

/* 少数を使う時で、誤差が無視できない時の方法
1. 整数になるように、1000とかをかける(少数点以下がある決まったところまでしか与えられない時に有効)
2. EPS(1e-10)を使う (少数は表現できない部分は切り捨てられるので、少し足す)
3. boostの多倍長整数を使う(計算時間も長くなるので注意)
ローカルでのboostを入れたコンパイル方法
g++ -I /usr/local/Cellar/boost/1.74.0/include a.cpp
*/
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using namespace std;
using ll = long long;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
const int MOD=1e9+7;

int main(){
  mp::cpp_dec_float_100 X,Y,R = 4.0f;
  cin>>X>>Y>>R;
  ll ans(0);
  for(int y(Y-R-1);y<=Y+R+1;y++){
    if(R*R-(y-Y)*(y-Y) >= 0){
      mp::cpp_dec_float_100 xl, xr;
      xl = X - mp::sqrt(R*R-(y-Y)*(y-Y));
      xr = X + mp::sqrt(R*R-(y-Y)*(y-Y));
      ans += max(0, (int)mp::floor(xr) - (int)mp::ceil(xl) + 1);
    }
  }
  cout << ans << endl;
  return 0;
}
