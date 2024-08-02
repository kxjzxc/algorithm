/*
url: https://codeforces.com/contest/1997/problem/C
solution:
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define M 200005
#define oo 1e9 + 7
using namespace std;

int main() {
  int T = 1;
  cout << T << endl;
  while (T--) {
    int n = M - 5;
    cout << n << endl;
    for (int i = 0; i < n; i++) cout << oo - 7 << " ";
    cout << endl;
    for (int i = 1; i < n; i++) cout << 1 << " ";
    cout << endl;
  }
  return 0;
}