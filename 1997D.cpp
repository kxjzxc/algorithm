/*
url: https://codeforces.com/contest/1997/problem/C
solution:
维护每个节点能到达的最大的数x,叶子节点的x为该节点的a。假设节点p，其子节点为s_i，获得y
= min(x[s_i]),如果a_p>y，则x[p]=y,如果a_p<y,则x[p]=(a_p+y)/2(向下取舍)。
考虑数据范围，无法用递归实现，所以要用拓扑排序优化成递推。
*/
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define M 200005
#define oo 1e9 + 7
using namespace std;
vector<int> p;
vector<int> a;
vector<int> degree;
vector<int> ans;
queue<int> Q;

int main() {
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    cin >> n;
    a.clear();
    a.reserve(n + 1);
    p.clear();
    p.reserve(n + 1);
    degree.clear();
    degree.reserve(n + 1);
    ans.clear();
    ans.reserve(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      degree[i] = 0;
    }
    for (int i = 2; i <= n; i++) {
      cin >> p[i];
      degree[p[i]]++;
    }
    while (!Q.empty()) Q.pop();
    for (int i = 1; i <= n; i++) {
      if (degree[i] == 0) {
        Q.push(i);
        ans[i] = a[i];
      } else {
        ans[i] = oo;
      }
    }
    while (!Q.empty()) {
      int son = Q.front();
      Q.pop();
      int parent = p[son];
      ans[parent] = min(ans[parent], ans[son]);
      degree[parent]--;
      if (degree[parent] == 0) {
        if (parent == 1) {
          cout << a[1] + ans[1] << endl;
          break;
        }
        Q.push(parent);
        ans[parent] = (a[parent] > ans[parent] ? ans[parent]
                                               : (a[parent] + ans[parent]) / 2);
      }
    }
  }
  return 0;
}