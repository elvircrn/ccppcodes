#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

#define MOD 2012
#define MAXN 1010

int A[MAXN];

int main() {

  int L = A[1] = 1;
  for(int ch = cin.get(); L > 0 && ch == '(' || ch == ')'; ch = cin.get()) {
    int dir = ch == '(' ? 1 : -1;
    L += dir;
    for(int j = dir < 0 ? 1 : L; 1 <= j && j <= L; j -= dir) {
      A[j] += A[j - dir];
      if(A[j] >= MOD) A[j] -= MOD;
    }
    A[L + 1] = 0;
  }

  cout << (L == 1 ? A[1] : 0) << endl;
}
