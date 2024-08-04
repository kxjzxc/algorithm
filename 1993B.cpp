/*
url: https://codeforces.com/problemset/problem/1993/B
solution:
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    int n, ans = 0, max_even = 0, max_odd = 0;
    cin >> n;
    a.clear();
    a.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] % 2)
        max_odd = max(max_odd, a[i]);
      else {
        max_even = max(max_even, a[i]);
        ans++;
      }
    }
    if (max_odd == 0 || max_even == 0) {
      ans = 0;
    } else if (max_even > max_odd) {
      sort(a.begin(), a.end());
      for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
          if (a[i] < max_odd) {
            if (max_odd < max_even) {
              max_odd += a[i];
            }
          } else {
            ans++;
            break;
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}