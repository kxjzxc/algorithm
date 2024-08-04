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
    int n, ans = 0, k, max_time = 0;
    cin >> n >> k;
    a.clear();
    a.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      max_time = max(max_time, a[i]);
    }
    int L1 = 0, R1 = 2 * k - 1, L2 = 0, R2 = 2 * k - 1;
    for (int i = 0; i < n; i++) {
      int t = (max_time - a[i]) / k;
      bool sts = true;
      if (t % 2) sts = false;
      int switc_time = k - ((max_time - a[i]) % k);
      if (sts) {
        R1 = min(R1, switc_time - 1);
        L2 = max(L2, switc_time + k);
      } else {
        L1 = max(L1, switc_time);
        R2 = min(R2, switc_time + k - 1);
      }
    }
    L2 = max(L2, L1);
    R1 = min(R1, R2);
    if (L1 > R1 && L2 > R2)
      cout << -1 << endl;
    else if (L1 <= R1)
      cout << L1 + max_time << endl;
    else
      cout << L2 + max_time << endl;
  }
  return 0;
}