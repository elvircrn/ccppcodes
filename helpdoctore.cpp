#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#define MAX 505
using namespace std;

long A[MAX][MAX];
char pom[MAX];
int main()
{
    //freopen("o-kliz.txt", "r", stdin);
    long i, j, n, k;
    scanf("%ld", &n);
    for(i=0; i < n; i++)
    {
       scanf("%s", pom);
       for(j=0; j < n; j++)
          A[i][j] = ( isupper( pom[j] ) );
    }

    k = 0;
    for(i=2; i < n; i++)
       for(j=1; j < n-1; j++)
          if( A[i][j] )
          {
             A[i][j] = min( min(A[i-1][j-1], A[i-1][j+1]), min(A[i-1][j], A[i-2][j]) ) + 1;
             k = max(k, A[i][j]);
          }

    k = 2*(k-1)*(k-1) + 2*k-1;
    printf("%ld", k);

    return 0;
}

