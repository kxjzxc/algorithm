/*
url: https://codeforces.com/contest/1997/problem/A
solution:
*/
#include <iostream>
#include <vector>
using namespace std;
int a[100];
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int len = s.size();
    int x = 0;
    for (int i = 1; i < len; i++) {
      if (s[i] == s[i - 1]) {
        x = i;
      }
    }
    for (int i = 0; i < len; i++) {
      if (i == x) {
        cout << char((s[i] - 'a' + 1) % 26 + 'a');
      }
      cout << s[i];
    }
    cout << endl;
  }
  return 0;
}