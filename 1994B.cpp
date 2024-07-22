/*
url: https://codeforces.com/problemset/problem/1994/B
solution:
根据题意，对第i个元素的操作需要用到第i-l+1，而后者一定在前者前面。所以考虑从后往前操作，对s[i],如果要变到t[i]，所以需要的元素存在并且在小于等于i即可
*/
#include <iostream>
#include <vector>
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::string s, t;
    std::cin >> s >> t;
    int first_0 = -1, first_1 = -1;
    for (int i = 0; i < n; i++) {
      if (first_0 == -1 && s[i] == '0') first_0 = i;
      if (first_1 == -1 && s[i] == '1') first_1 = i;
      if (first_0 != -1 && first_1 != -1) break;
    }
    auto check = [](int i, int &first_x) -> bool {
      if (first_x == -1) return false;
      if (first_x <= i) {
        if (first_x == i) first_x = -1;
        return true;
      }
      return false;
    };
    int i = n - 1;
    for (i = n - 1; i >= 0; i--) {
      if (s[i] == t[i]) continue;
      if (t[i] == '0') {
        if (s[i] == '0') {
          if (!check(i, first_0)) break;
          continue;
        }
        if (s[i] == '1') {
          if (!check(i, first_1)) break;
          continue;
        }
      } else {
        if (s[i] == '0') {
          if (!check(i, first_1)) break;
          continue;
        }
        if (s[i] == '1') {
          if (!check(i, first_0)) break;
          continue;
        }
      }
    }
    std::cout << ((i >= 0) ? "NO" : "YES") << std::endl;
  }
  return 0;
}