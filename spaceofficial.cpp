#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

ll ox, oy;

struct point {
	ll x, y;
	point() : x(0), y(0) {}
	point(const ll x, const ll y) : x(x), y(y) {}

	bool operator < ( const point & Q ) const {
		if (x != Q.x) return x < Q.x;
		return y < Q.y;
	}
} A[500], B[500], C[500], D[500];

inline bool compare( const point & P, const point & Q ) {
	point A( P.x - ox, P.y - oy ), B( Q.x - ox, Q.y - oy );
	return A.x * B.y > A.y * B.x;
}

int main() {
    freopen ("in.txt", "r", stdin);
	int n, m, num = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> A[i].x >> A[i].y;
	for (int i = 0; i < m; i++) cin >> B[i].x >> B[i].y;
	sort( A, A + n );
	sort( B, B + m );
	for (int i = 0, zomg = 0; i < n - 2; i++) {
		while ( zomg < m && B[zomg] < A[i] ) zomg++;
		memcpy( C + i + 1, A + i + 1, sizeof(point) * (n - i - 1) );
		memcpy( D + zomg, B + zomg, sizeof(point) * (m - zomg) );
		ox = A[i].x;
		oy = A[i].y;
		sort( C + i + 1, C + n, compare );
		sort( D + zomg, D + m, compare );

		for (int j = i + 1; j < n - 1; j++) {
			ll VX = C[j].x - A[i].x;
			ll VY = C[j].y - A[i].y;

			int k1 = j + 1;
			int k2 = zomg;
			while ( k1 < n && k2 < m ) {
				if ( compare( C[k1], D[k2] ) ) {
					ll TX = C[k1].x - C[j].x;
					ll TY = C[k1].y - C[j].y;
					if (TX * VY < TY * VX) num++;
					k1++;
				}
				else {
					ll TX = D[k2].x - C[j].x;
					ll TY = D[k2].y - C[j].y;
					if (TX * VY < TY * VX) {
						VX = TX;
						VY = TY;
					}
					k2++;
				}
			}
			while ( k1 < n ) {
				ll TX = C[k1].x - C[j].x;
				ll TY = C[k1].y - C[j].y;
				if (TX * VY < TY * VX) num++;
				k1++;
			}
		}
	}
	cout << num << endl;
	return 0;
}
