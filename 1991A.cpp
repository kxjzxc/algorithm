/*
url: https://codeforces.com/problemset/problem/1991/A
solution:
*/
#include <iostream>
#include <vector>
using namespace std;
int a[100];
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (i % 2 == 0) ans = max(a, ans);
    }
    cout << ans << endl;
  }
  return 0;
}