#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 照準にソートされたAとそのサイズ、ターゲットの数字xを渡すとtarget以上の数字でもっともindexが小さいものを返す
int my_lower_bound(vector<int> A, int size, int target){
  int l = 0, r = size;
  while (r - l > 0){
    int x = (r + l) / 2;
    if (A[x] < target) l = x + 1;
    else r = x;
  }
  return l;
}

int my_upper_bound(vector<int> A, int size, int target){
  int l = 0, r = size;
  while (r - l > 0){
    int x = (r + l) / 2;
    if (A[x] <= target) l = x + 1;
    else r = x;
  }
  return l;
}

int main(){
  vector<int> a = {1, 2, 2, 3, 5, 8, 10};
  cout << my_lower_bound(a, 7, 0) << endl; // 0
  cout << my_lower_bound(a, 7, 2) << endl; // 2以上で最初のindexなので1
  cout << my_lower_bound(a, 7, 5) << endl; // 5以上なので4
  cout << my_lower_bound(a, 7, 11) << endl; // 11以上はないので配列より外である7

  cout << my_upper_bound(a, 7, 0) << endl; // 0
  cout << my_upper_bound(a, 7, 2) << endl; // 2より大きい最初のindexなので3
  cout << my_upper_bound(a, 7, 5) << endl; // 5
  cout << my_upper_bound(a, 7, 11) << endl; // 11以上はないので配列より外である7

  return 0;
}
