/*
url: https://codeforces.com/contest/1996/problem/D
*/
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    long long ans = 0;
    cin >> n >> x;
    for (int b = 1; b < x; b++) {
      for (int c = 1; c <= b; c++) {
        if (b * c >= n || (n - b * c) < b + c || b + c >= x) break;
        bool different = (b != c);
        ans += min(x - b - c, (n - b * c) / (b + c)) * (1 + different);
      }
    }
    cout << ans << endl;
  }
  return 0;
}