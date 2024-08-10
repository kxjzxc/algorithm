/*
url: https://codeforces.com/problemset/problem/1998/A
solution:
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    int center_x, center_y, k, ans = 0;
    cin >> center_x >> center_y >> k;
    if (k % 2) {
      cout << center_x << " " << center_y << endl;
      k--;
      for (int i = 1; k > 0; i++) {
        cout << center_x + i << " " << center_y + i << endl;
        cout << center_x - i << " " << center_y - i << endl;
        k -= 2;
      }
    } else {
      for (int i = 1; k > 0; i++) {
        cout << center_x + i << " " << center_y + i << endl;
        cout << center_x - i << " " << center_y - i << endl;
        k -= 2;
      }
    }
  }
  return 0;
}