#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

using namespace std;

const int N = 200010;

int n[3];
vector <int> g[3][N];
int size[3][N];
long long sum[3][N];

bool good[3][N];

void dfs(int r, int v, int pr, bool need_sum) {
  int sz = g[r][v].size();
  size[r][v] = 1;
  if (need_sum) {
    sum[r][v] = 0;
  }
  for (int j = 0; j < sz; j++)
    if (g[r][v][j] != pr && good[r][g[r][v][j]]) {
      dfs(r, g[r][v][j], v, need_sum);
      size[r][v] += size[r][g[r][v][j]];
      if (need_sum) {
        sum[r][v] += sum[r][g[r][v][j]] + size[r][g[r][v][j]];
      }
    }
}

void push(int r, int v, int pr) {
  int sz = g[r][v].size();
  for (int j = 0; j < sz; j++)
    if (g[r][v][j] != pr) {
      sum[r][g[r][v][j]] = sum[r][v] - size[r][g[r][v][j]] + (n[r] - size[r][g[r][v][j]]);
      push(r, g[r][v][j], v);
    }
}

long long MAX;

void calc(int r, int v, int pr, int dist, long long x, long long y) {
  long long cur = sum[r][v] * x + dist * y;
  if (cur > MAX) {
    MAX = cur;
  }
  int sz = g[r][v].size();
  for (int j = 0; j < sz; j++)
    if (g[r][v][j] != pr && good[r][g[r][v][j]]) {
      calc(r, g[r][v][j], v, dist + 1, x, y);
    }
}

long long add;

long long a[N], b[N];

void solve(int r, int v, long long n1, long long n2) {
  dfs(r, v, -1, false);
  {
    int tn = size[r][v];
    int pr = -1;
    bool dd = true;
    while (dd) {
      dd = false;
      int sz = g[r][v].size();
      for (int j = 0; j < sz; j++)
        if (g[r][v][j] != pr && good[r][g[r][v][j]]) {
          if (2 * size[r][g[r][v][j]] >= tn) {
            pr = v;
            v = g[r][v][j];
            dd = true;
            break;
          }
        }
    }
  }
  {
    good[r][v] = false;
    int sz = g[r][v].size();
    for (int j = 0; j < sz; j++)
      if (good[r][g[r][v][j]]) {
        MAX = sum[r][v] * n1;
        calc(r, g[r][v][j], -1, 1, n1, n1 * n2);
        a[j] = MAX;
        MAX = sum[r][v] * n2;
        calc(r, g[r][v][j], -1, 1, n2, n1 * n2);
        b[j] = MAX;
      }
    for (int j = 0; j < sz; j++) {
      long long cur = sum[r][v] * n1 + b[j];
      if (cur > add) add = cur;
      cur = sum[r][v] * n2 + a[j];
      if (cur > add) add = cur;
    }
    int k1 = -1, k2 = -1;
    for (int j = 0; j < sz; j++) {
      if (k1 == -1) {
        k1 = j;
      } else
      if (a[j] > a[k1]) {
        k2 = k1;
        k1 = j;
      } else
      if (k2 == -1) {
        k2 = j;
      } else
      if (a[j] > a[k2]) {
        k2 = j;
      }
    }
    for (int j = 0; j < sz; j++) {
      long long cur = b[j];
      if (k1 == j) {
        if (k2 != -1) cur += a[k2];
      } else {
        if (k1 != -1) cur += a[k1];
      }
      if (cur > add) add = cur;
    }
  }
  {
    good[r][v] = false;
    int sz = g[r][v].size();
    for (int j = 0; j < sz; j++)
      if (good[r][g[r][v][j]]) {
        solve(r, g[r][v][j], n1, n2);
      }
  }
}

long long sum_all[3];
long long tot[3];
long long cntn[3];

int main() {
  scanf("%d %d %d", n + 0, n + 1, n + 2);
  for (int r = 0; r < 3; r++) {
    for (int i = 1; i <= n[r] - 1; i++) {
      int foo, bar;
      scanf("%d %d", &foo, &bar);
      g[r][foo].push_back(bar);
      g[r][bar].push_back(foo);
    }
    for (int i = 1; i <= n[r]; i++) good[r][i] = true;
    dfs(r, 1, -1, true);
    push(r, 1, -1);
    sum_all[r] = 0;
    for (int i = 1; i <= n[r]; i++) {
      sum_all[r] += sum[r][i];
    }
    sum_all[r] /= 2;
  }
  long long ans = 0;
  for (int m = 0; m < 3; m++) {
    int x = 0;
    for (int r = 0; r < 3; r++) {
      if (r == m) {
        continue;
      }
      tot[x] = 0;
      for (int i = 1; i <= n[r]; i++)
        if (sum[r][i] > tot[x]) {
          tot[x] = sum[r][i];
        }
      cntn[x] = n[r];
      x++;
    }
    long long s1 = tot[0];
    long long n1 = cntn[0];
    long long s2 = tot[1];
    long long n2 = cntn[1];
    long long out = n[m] * s1 + n[m] * n1;
    out += n[m] * s2 + n[m] * n2;
    out += n1 * s2 + n2 * s1;
    out += n1 * n2 * 2;
    add = 0;
    {
      solve(m, 1, n1, n2);
    }
    if (out + add > ans) {
      ans = out + add;
    }
  }
  cout << ans + sum_all[0] + sum_all[1] + sum_all[2] << endl;
  return 0;
}
