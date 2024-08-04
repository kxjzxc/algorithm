/*
url: https://codeforces.com/problemset/problem/1993/A
solution:
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    int n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    int num[4] = {0};
    for (int i = 0; i < 4 * n; i++) {
      if (s[i] == '?') continue;
      num[s[i] - 'A']++;
    }
    for (int i = 0; i < 4; i++) ans += min(n, num[i]);
    cout << ans << endl;
  }
  return 0;
}