#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
  int N = 3;
// start
  /* 0 1 2 
     0 2 1
     1 0 2
     1 2 0
     2 0 1
     2 1 0 */
  vector<int> x(N);
  for(int i(0);i<N;i++){
    x[i] = i;
  }
  do{
    for (int i(0);i<N;i++){
      cout << x[i] << " ";
    }
    cout << endl;
  }while(next_permutation(x.begin(),x.end()));
// end
  return 0;
}
