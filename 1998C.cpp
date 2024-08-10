/*
url: https://codeforces.com/problemset/problem/1998/C
solution:
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> a;
int n, k;
bool check(int mid, int max_0, int times) {
  int lower_num = 0;
  bool flag = false;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i].first >= mid) continue;
    if (a[i].second == 0) {
      if (!flag && a[i].first == max_0) {
        flag = true;
        continue;
      }
      lower_num++;
    } else {
      if (times >= mid - a[i].first) {
        times -= mid - a[i].first;
      } else
        lower_num++;
    }
  }
  return lower_num < (n / 2);
}
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    cin >> n >> k;
    a.clear();
    a.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
      cin >> a[i].second;
    }
    int max_num[2] = {0};
    for (int i = 0; i < n; i++) {
      if (max_num[a[i].second] < a[i].first) {
        max_num[a[i].second] = a[i].first;
      }
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    if (max_num[0] != 0) {
      int L = 1, R = 1e9;
      while (L < R) {
        int mid = (L + R) >> 1;
        if (check(mid, max_num[0], k)) {
          L = mid + 1;
          ans = max_num[0] + mid;
        } else {
          R = mid;
        }
      }
    }
    if (max_num[1] != 0) {
      int mid = n / 2 - 1;
      if (a[mid].first >= max_num[1]) mid++;
      ans = max(ans, (long long)max_num[1] + k + a[mid].first);
    }
    cout << ans << endl;
  }

  return 0;
}