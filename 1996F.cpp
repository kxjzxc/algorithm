/*
url: https://codeforces.com/contest/1996/problem/F
*/
#include <algorithm>
#include <iostream>
#include <string>
#define M 200005
#define N 1000000007
using namespace std;
int a[M];
int b[M];
int n, k;
bool check(int x) {
  int op = k;
  for (int i = 0; i < n; i++) {
    if (a[i] < x) continue;
    int c = (a[i] - x) / b[i];
    if ((a[i] - x) % b[i]) c++;
    if (op < c) return false;
    op -= c;
  }
  return true;
}
long long get(int x) {
  long long ans = 0;
  int op = k;
  for (int i = 0; i < n; i++) {
    if (a[i] < x) continue;
    int c = (a[i] - x) / b[i];
    if ((a[i] - x) % b[i]) c++;
    int m = a[i] - (c - 1) * b[i];
    ans += ((long long)(a[i] + m) * c) / 2;
    if (op < c) return 0;
    op -= c;
  }
  ans = ans + (long long)op * x;
  return ans;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    int L = 0, R = N;
    while (L < R) {
      int mid = (L + R) >> 1;
      if (check(mid)) {
        R = mid;
      } else {
        L = mid + 1;
      }
    }
    cout << get(R) << endl;
  }
  return 0;
}