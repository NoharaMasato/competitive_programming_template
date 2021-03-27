// 階乗前列挙(NextPermutation)(N!), 順列列挙(nPk), 組み合わせ列挙(nCk)
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void nextPermutation(){
  int N = 3; // O(N!)
  /* 0 1 2 
     0 2 1
     1 0 2
     1 2 0
     2 0 1
     2 1 0 */
  vector<int> x(N);
  for(int i(0);i<N;i++) x[i] = i;
  do{
    for (int i(0);i<N;i++) cout << x[i] << " ";
    cout << endl;
  }while(next_permutation(x.begin(),x.end()));
}

void combination(const vector<int> &A, int k){ // 配列Aからk個選んだ組み合わせを出力する
  int N = (int)A.size();
}

void permutation(const vector<int> &A, int k){ // 配列Aからk個選んだ順列を出力する
  int N = (int)A.size();
}


int main(){

}