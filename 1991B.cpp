/*
url: https://codeforces.com/problemset/problem/1994/A
solution:
*/
#include <iostream>
#include <vector>
#define M 100005
using namespace std;
int b[M];
int a[M];
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n - 1; i++) cin >> b[i];
    a[0] = b[0];
    a[n - 1] = b[n - 2];
    for (int i = 1; i < n - 1; i++) {
      a[i] = b[i - 1] | b[i];
    }
    bool check_ans = true;
    for (int i = 0; i < n - 1; i++) {
      if (b[i] != (a[i] & a[i + 1])) {
        check_ans = false;
      }
    }
    if (check_ans) {
      for (int i = 0; i < n; i++) cout << a[i] << " ";
    } else
      cout << -1;
    cout << endl;
  }
  return 0;
}