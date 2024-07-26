/*
url: https://codeforces.com/contest/1996/problem/C
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define M 200005
using namespace std;
int suma[26][M];
int sumb[26][M];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < 26; i++) {
      suma[i][0] = 0;
      sumb[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 26; j++) {
        suma[j][i] = suma[j][i - 1] + (a[i - 1] == j + 'a');
        sumb[j][i] = sumb[j][i - 1] + (b[i - 1] == j + 'a');
      }
    }
    while (q--) {
      int l, r, same = 0;
      cin >> l >> r;
      for (int j = 0; j < 26; j++) {
        int num_a = suma[j][r] - suma[j][l - 1];
        int num_b = sumb[j][r] - sumb[j][l - 1];
        same += min(num_a, num_b);
      }
      cout << r - l + 1 - same << endl;
    }
  }
  return 0;
}