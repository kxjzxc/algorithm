/*
url: https://codeforces.com/contest/1997/problem/B
solution:
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];
    auto check = [s, n](int i, int j) {
      if (s[i][j] == 'x') return 0;
      if (j == 0 || j == n - 1) return 0;
      int k = (i + 1) % 2;
      if (s[k][j] == 'x') return 0;
      if (s[k][j - 1] == '.' || s[k][j + 1] == '.') return 0;
      if (s[i][j - 1] == 'x' || s[i][j + 1] == 'x') return 0;
      return 1;
    };
    int ans = 0;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        ans += check(i, j);
      }
    }
    cout << ans << endl;
  }
  return 0;
}