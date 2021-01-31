#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
  int N = 4;
// start
/*  0000
    1000
    0100
    1100
    0010 */
for(int bit(0);bit<(1<<N);bit++){
  for(int i(0);i<N;i++){
    if (((bit>>i) & 1)){
      cout << 1;
    }else{
      cout << 0;
    }
  }
  cout << endl;
}
// end
  return 0;
}
