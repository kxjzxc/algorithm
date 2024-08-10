/*
url: https://codeforces.com/problemset/problem/1998/B
solution:
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> p;
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    cin >> n;
    p.clear();
    p.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
      cout << p[(i + 1) % n] << " ";
    }
    cout << endl;
  }
  return 0;
}