/*
url: https://codeforces.com/problemset/problem/1994/B
solution:
根据题意，只要从最长的对角线开始放置chips即可，需要注意的是最长的对角线只有一条，而其他长度的对角线都有两条
*/
#include <iostream>
#include <vector>
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    int n, k;
    std::cin >> n >> k;
    int ans = 0;
    auto put_chips = [&]() {
      if (k >= n) {
        k -= n;
        ans++;
      }
    };
    put_chips();
    n--;
    do {
      if (n <= 0) break;
      put_chips();
      put_chips();
      n--;
    } while (k > 0);
    std::cout << ans << std::endl;
  }
  return 0;
}