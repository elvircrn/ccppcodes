
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

char s[4242];
int f[4242];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    f[i] = 1;
    for (int j = i - 1; j >= 0; j -= 2)
      if (s[i] == s[j] && f[j] + 1 > f[i]) f[i] = f[j] + 1;
    if (f[i] > mx) mx = f[i];
  }
  printf("%d\n", mx);
  return 0;
}
/*
abcaa
*/
