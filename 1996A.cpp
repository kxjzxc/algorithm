/*
url: https://codeforces.com/contest/1996/problem/A
*/
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int ans = n / 4 + (n % 4) / 2;
    cout << ans << std::endl;
  }
  return 0;
}