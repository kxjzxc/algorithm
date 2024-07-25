/*
url: hhttps://codeforces.com/contest/1995/problem/B1
solution:
首先统计每个花瓣数量的花有多少束，得到(x,c_x)
根据题意，我们选择的花束的花瓣之差不能大于1，所以只有x花瓣和x-1的花瓣可以选择。
对于x花瓣的花，我们最多选择min(m/x,c_x)束花朵，因此我们可以枚举选取x花瓣的花朵数量i，得到剩余的硬币数m'=m-x*i
如果存在x-1花瓣的花束，那么我们最多选择j=min(m'/(x-1),c_{x-1})朵花束，此时我们的花束最多有ans=x*i+(x-1)*j片花瓣
如果不存在x-1花瓣的花束，那么我们的花束最多有ans=x*i片花瓣
最大的ans就是我们的答案
PS：注意longlong
*/
#include <algorithm>
#include <iostream>
#include <vector>
std::vector<int> flowers;
std::vector<std::pair<int, int>> petals;
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    long long m;
    std::cin >> n >> m;
    flowers.clear();
    for (int i = 0; i < n; i++) {
      int petal;
      std::cin >> petal;
      flowers.emplace_back(petal);
    }
    std::sort(flowers.begin(), flowers.end());
    long long ans = 0;
    int L = n - 1, R = n - 1;
    petals.clear();
    while (L >= R && R >= 0) {
      while (R >= 0 && flowers[R] == flowers[L]) R--;
      petals.emplace_back(flowers[L], L - R);
      L = R;
    }
    for (int i = 0; i < petals.size(); i++) {
      long long max_i =
          std::min((m / petals[i].first), (long long)petals[i].second);
      for (int j = 0; j <= max_i; j++) {
        long long coins = m;
        coins -= j * petals[i].first;
        if (i + 1 < petals.size() &&
            petals[i].first - petals[i + 1].first == 1) {
          coins -= std::min((coins / petals[i + 1].first),
                            (long long)petals[i + 1].second) *
                   petals[i + 1].first;
        }
        ans = std::max(ans, m - coins);
      }
    }
    std::cout << ans << std::endl;
  }
  return 0;
}