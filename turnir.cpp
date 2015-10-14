/*
    ID : Al3kSaNdaR
    TASK : turnir
*/
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int lld;

const int MaxN = 1 << 20;

int N, M, A[MaxN], B[MaxN];
lld DP[MaxN];

int main ( void )
{
    scanf ( "%d", &N );

    N = 1 << N;
    for ( int i = 0; i < N; i++ ) scanf ( "%d", &A[i] );

    if ( N == 1 )
    {
        printf ( "0\n" );
        printf ( "%d\n", A[0] );

        return 0;
    }

    sort ( A, A + N );
    reverse ( A, A + N );

    DP[0] = 1LL * A[0];
    for ( int i = 1; i < N; i++ ) DP[i] = DP[i - 1] + 1LL * A[i];

    int M = N;
    lld Popularity = 0LL;

    while ( M != 1 )
    {
        Popularity += DP[M - 1];

        M >>= 1;
    }

    printf ( "%lld\n", Popularity );

    for ( int i = 1; i < N; i += 2 ) B[i] = A[N - 1 - i / 2];

    int idx = 0, Step = N >> 1;

    while ( idx != N / 2 )
    {
        for ( int i = 0; i < N; i += Step ) if ( ! B[i] ) B[i] = A[idx++];

        Step >>= 1;
    }

    for ( int i = 0; i < N; i++ ) printf ( "%d%c", B[i], ( i + 1 == N ) ? '\n' : ' ' );

    return 0;
}
