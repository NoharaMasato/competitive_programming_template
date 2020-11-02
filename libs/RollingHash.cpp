// 蟻本332ページ
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

typedef unsigned long long ull;
const ull B = 100000007; // 1e8+7

// aはbに含まれているか O(|a|+|b|)
bool contain(string a, string b){
  int al = int(a.size()), bl = int(b.size());
  if(al > bl) return false;

  ull t = 1;
  for(int i(0);i<al;i++) t *= B;

  ull ah(0), bh(0);
  for(int i(0);i<al;i++) ah = ah*B + a[i];
  for(int i(0);i<al;i++) bh = bh*B + b[i];
  
  for(int i(0);i+al<=bl;i++){
    if(ah == bh) return true;
    if(i + al < bl) bh = bh*B + b[i+al] - b[i] * t;
  }
  return false;
}

// aの末尾とbの先頭を何文字重ねることができるか O(|a|+|b|)
int overlap(string a, string b){
  int al = int(a.size()), bl = int(b.size());
  int ans = 0;
  ull ah(0), bh(0), t(1);
  for(int i(1);i<=min(al, bl);i++){
    ah = ah + a[al - i] * t;
    bh = bh * B + b[i-1];
    if(ah == bh) ans = i;
    t *= B;
  }
  return ans;
}

int main(){
  cout << contain("aba", "jfksdlabasjkdf") << endl;
  cout << overlap("fadsfasda", "sdajkdsa") << endl;
  return 0;
}
