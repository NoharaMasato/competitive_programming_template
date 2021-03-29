#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;
#define printa(x,n) for(int i = 0; i < n; i++){ cout << (x[i]) << " \n"[i==n-1];};

// T = doubleのときは加算を誤差を考慮して行わなければいけない(蟻本p226参照)
template <typename T>
class P {
public:
  T x, y;
  // コンストラクタ
  P(){};
  P(T x, T y): x(x), y(y) {};
  // 演算子
  P operator + (P p) {
    return P(x + p.x, y + p.y);
  }
  P operator - (P p) {
    return P(x - p.x, y - p.y);
  }
  P operator * (T d) {
    return P(x*d, y*d);
  }
  P operator / (T d) {
    return P(x/d, y/d);
  }
  bool operator == (P p) {
    return (x == p.x && y == p.y);
  }
  T dot(P p) { //内積
    return x*p.x + y*p.y;
  }
  T det(P p) { //外積
    return x*p.y - y*p.x;
  }
};

// 線分p1-p2に点qがあるか判定
bool on_seg(P<int> p1, P<int> p2, P<int> q){
  return (p1-q).det(p2-q) == 0 && (p1-q).dot(p2-q) <= 0;
}

// p1, p2, p3が同一線上にあるかどうか
bool on_one_line(P<int> p1, P<int> p2, P<int> p3){
  return (p1-p3).det(p2-p3) == 0;
}

// 直線p1, p2と直線q1, q2の交点
P<int> intersection(P<int> p1, P<int> p2, P<int> q1, P<int> q2){
  return p1 + (p2 - p1)*((q2 - q1).det(q1 - p1) / (q2 - q1).det(p2 - p1));
}

// p1とp2の距離
double point_to_point_distance(P<int> p1, P<int> p2) {
  return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

// 点p1,p2を通る直線と点pの距離
double point_to_line_distance(P<int> p1, P<int> p2, P<int> p){ // point to line distance
  if(p1 == p2) return 0; //線分が点となる場合は例外

  // https://mathtrain.jp/tentotyokusen （点と直線の公式参照)
  int a = p2.y - p1.y, b = p1.x - p2.x, c = p2.x*p1.y - p2.y*p1.x;
  double dist = abs(a*p.x + b*p.y + c)/sqrt(a*a+b*b);
  return dist;
}

// https://www.geeksforgeeks.org/minimum-distance-from-a-point-to-the-line-segment-using-vectors/
// 点p1,p2を結ぶ線分と点pの最短距離
double point_to_line_segment_distance(P<int> p1, P<int> p2, P<int> p){

}

// 点pを原点を中心に時計回りにang(ラジアン)回転させる
P<double> rotate(P<double> p, double ang) {
  return P<double>(p.x * cos(ang) - p.y * sin(ang), p.x * sin(ang) + p.y * cos(ang));
}

int main(){
  return 0;
}
