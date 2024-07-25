/*
url: https://codeforces.com/problemset/problem/1/A
solution: 注意longlong
*/
#include <iostream>
int main() {
  int T;
  int n, m, a;
  std::cin >> n >> m >> a;
  long long ans = 0;
  ans = (long long)(n / a) * (long long)(m / a);
  if (n % a != 0) ans += m / a;
  if (m % a != 0) ans += n / a;
  if (m % a != 0 && n % a != 0) ans++;
  std::cout << ans << std::endl;
  return 0;
}