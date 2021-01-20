// https://algo-logic.info/coordinate-compress/
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

template <typename T>
vector<T> compress2d(vector<T> &C1, vector<T> &C2) {
    // ソートした結果を vals に(これは座圧した結果を元の値に戻すために使える)(座圧した結果はC1, C2に入る)
    vector<T> vals;
    int N = (int)C1.size();
    for (int i = 0; i < N; i++) {
        for (T d = 0; d < 1; d++) {  // その位置と、一つ隣を確保(隣を確保しないと空白が埋まってしまうことがある)
            T tc1 = C1[i] + d;
            T tc2 = C2[i] + d;
            vals.push_back(tc1);
            vals.push_back(tc2);
        }
    }
    // ソート
    sort(vals.begin(), vals.end());
    // 隣り合う重複を削除(unique), 末端のゴミを削除(erase)
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 0; i < N; i++) {
        C1[i] = lower_bound(vals.begin(), vals.end(), C1[i]) - vals.begin();
        C2[i] = lower_bound(vals.begin(), vals.end(), C2[i]) - vals.begin();
    }
    return vals;
}

template <typename T>
vector<T> compress1d(vector<T> &X) {
    // ソートした結果を vals に(これは座圧した結果を元の値に戻すために使える)(座圧した結果はXに入る)
    vector<T> vals = X;
    sort(vals.begin(), vals.end());
    // 隣り合う重複を削除(unique), 末端のゴミを削除(erase)
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    // 各要素ごとに二分探索で位置を求める
    for (int i = 0; i < (int)X.size(); i++) {
        X[i] = lower_bound(vals.begin(), vals.end(), X[i]) - vals.begin();
    }
    return vals;
}
int main(){
  vector<ll> a = {10000000, 10, 3, 30000000000000};
  compress1d(a);
  for(ll ai:a) cout << ai << " ";
  cout << endl;
}