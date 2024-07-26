/*
url: https://codeforces.com/contest/1996/problem/B
*/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      string grids = "", ans = "";
      cin >> grids;
      if (i % k == 0) {
        for (int j = 0; j < n; j += k) {
          ans += grids[j];
        }
        cout << ans << endl;
      }
    }
  }
  return 0;
}