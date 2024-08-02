/*
url: https://codeforces.com/contest/1997/problem/C
solution:
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define M 200005
using namespace std;
queue<int> Q;
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int l_r_num = 0;
    for (int i = 0; i < n; i += 2) {
      if (s[i + 1] == ')') l_r_num--;
      if (l_r_num > 0) {
        s[i] = ')';
        l_r_num--;
      } else {
        s[i] = '(';
        l_r_num++;
      }
      if (s[i + 1] == '(') l_r_num++;
    }
    int ans = 0;
    while (!Q.empty()) Q.pop();
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') Q.push(i);
      if (s[i] == ')') {
        int x = Q.front();
        Q.pop();
        ans += i - x;
      }
    }
    cout << ans << endl;
  }
  return 0;
}