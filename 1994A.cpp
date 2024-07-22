/*
url: https://codeforces.com/problemset/problem/1994/A
solution: 只有1*1矩阵才是无解的，其他输入只要交换相邻两个值就行
*/
#include <iostream>
#include <vector>
std::vector<int> matrix;
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    int n, m, a;
    std::cin >> n >> m;
    matrix.clear();
    matrix.reserve(n * m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        std::cin >> a;
        matrix.emplace_back(a);
      }
    }
    int sz = n * m;
    if (sz == 1) {
      std::cout << -1 << std::endl;
      continue;
    }
    for (int cur = 0; cur < sz; cur += 2) {
      int next = (cur + 1) % sz;
      std::swap(matrix[cur], matrix[next]);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        std::cout << matrix[i * m + j] << " ";
      }
      std::cout << std::endl;
    }
  }
  return 0;
}