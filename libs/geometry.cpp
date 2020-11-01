#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 3点が一直線上にあるか
bool one_liner(int x1, int y1, int x2, int y2, int x3, int y3){
  if ((y2-y3)*(x1-x3) - (y1-y3)*(x2-x3) == 0) return true;
  else return false;
}

// (x1,y1), (x2, y2)上に(x, y)が存在するか
bool line_segment(int x1, int y1, int x2, int y2, int x, int y){

}

int main(){
  return 0;
}
