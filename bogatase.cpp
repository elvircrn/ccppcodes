#include <iostream>
using namespace std;

char a[501][501];
int dp[501][501];

int main(){
  int n, i, j, best = 0, first = 0;
  cin >> n;
  if(n == 0){
    cout <<"0"<<endl;
    return 0;
  }
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      cin >> a[i][j];
        if(a[i][j]>= 65 && a[i][j]<=90) {
        first  = 1;
        dp[i][j] = 1;
      }
    }
  }
  for(i = 2; i < n; i++){
    for(j = 1; j < n - 1; j++){
      if(dp[i][j] == 0) continue;
      else dp[i][j] = min(min( dp[i-1][j-1], dp[i-1][j+1]),min( dp[i-2][j], dp[i-1][j]) ) + 1;
      best = max( best, dp[i][j] );
    }
  }

  best = 2 * best - 1;
    int dva = best - 2;
    dva = (dva + 1) / 2;
    dva *= dva;
    best = (best + 1) / 2;
    best *= best;

  cout<<dva + best<<endl;
  /*
  for(i = 1; i < 2*best; i+=2){
    sum += i;
  }*/

  //cout << (sum * 2)-(2*best - 1) << endl;
  //system("pause");
  return 0;
}
