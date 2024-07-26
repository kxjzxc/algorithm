/*
url: https://codeforces.com/contest/1996/problem/E
*/
#include <algorithm>
#include <iostream>
#include <string>
#define M 200005
#define mod 1000000007
using namespace std;
int sum[M];
long long num[M * 2];
int main() {
  int T;
  cin >> T;
  while (T--) {
    string str;
    cin >> str;
    sum[0] = 0;
    num[M] = 1;
    long long ans = 0;
    int len = str.size();
    for (int i = 1; i <= len; i++) {
      sum[i] = sum[i - 1];
      if (str[i - 1] == '1') sum[i]++;
      if (str[i - 1] == '0') sum[i]--;
      long long cur_num = (num[M + sum[i]] * (len - i + 1)) % mod;
      ans = (ans + cur_num) % mod;
      num[M + sum[i]] = (num[M + sum[i]] + i + 1) % mod;
    }
    cout << ans << endl;
    for (int i = 1; i <= len; i++) {
      num[M + sum[i]] = 0;
    }
  }
  return 0;
}