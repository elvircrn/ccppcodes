#include <cstdlib>
#include <cstdio>
#include <memory.h>
#include <vector>

using namespace std;

const int MaxN = 1024;
const int MaxK = 2020;
const int inf = 1000000;

FILE* file;

struct Strip
{
	int ind, row;
	int left, right;
	Strip(int _ind, int _row, int _l, int _r)
	{
		ind = _ind; row = _row; left = _l; right = _r;
	}
	Strip() {}
};

Strip strips[2 * MaxK];
//vector<int> toRemove[MaxN], toInsert[MaxN];
int insertVal[MaxN][MaxN], removeVal[MaxN][MaxN];
int bestField[2 * MaxK][MaxN];
int insertCount[MaxN], removeCount[MaxN];
int currTable[MaxN][MaxN];

bool a[MaxN][MaxN];
int T[MaxN][MaxN], B[MaxN][MaxN], BL[MaxN], left[MaxN];

int n, k, stripCount, sol, mi, mj, boardNum;
int cx[MaxK][8], cy[MaxK][8];

int min(int a, int b)
{
	return (a < b ? a : b);
}

struct SegmentTree {
	int m[2 * MaxN];
	int l[2 * MaxN];
	int r[2 * MaxN];
	int offset;

	void init() {

		offset = MaxN - 1;
		for (int i = 0; i < 2 * MaxN; i++)
			m[i] = inf;
		for (int i = offset + 1; i < 2 * MaxN; i++) {
			l[i] = i;  r[i] = i;
		}
		for (int node = offset; node > 0; node--) {
			l[node] = l[2 * node];
			r[node] = r[2 * node + 1];
		}
	}

	int getMin(int node, int L, int R)
	{
		if (R < l[node] || r[node] < L) return inf;
		if (L <= l[node] && r[node] <= R) return m[node];
		return (min(getMin(2 * node, L, R), getMin(2 * node + 1, L, R)));
	}

	int findMin(int left, int right)
	{
		if (left > right) return inf;
		int L = left + offset;
		int R = right + offset;
		return getMin(1, L, R);
	}

	void update(int pos, int val) {
		int i = pos + offset;
		m[i] = val;
		i = i / 2;
		while (i > 0) {
			m[i] = min(m[2 * i], m[2 * i + 1]);
			i = i / 2;
		}
	}

} tree;

void Input()
{
	FILE* inFile = fopen("spiral.in", "r");
	fscanf(inFile, "%d%d", &n, &k);
	for (int i = 1; i <= k; i++)
		fscanf(inFile, "%d%d", &cx[i][0], &cy[i][0]);

	for (int j = 1; j < 8; j++)
		for (int i = 1; i <= k; i++)
		{
			cx[i][j] = cy[i][j - 1]; cy[i][j] = n + 1 - cx[i][j - 1];
		}
	for (int j = 4; j < 8; j++)
		for (int i = 1; i <= k; i++)
		{
			cx[i][j] = n + 1 - cx[i][j]; //cy[i][j] = n + 1 - cy[i][j];
		}

	memset(a, false, sizeof(a));
	fclose(inFile);
}

void calculateBL()
{
	//memset(BL, 0, sizeof(BL));
	//memset(L, 0, sizeof(L));
	memset(T, 0, sizeof(T));
	memset(B, 0, sizeof(B));
	for (int i = n; i >= 1; i--)
		for (int j = 1; j <= n; j++)
			if (!a[i][j])
			{
				if (i == n || a[i + 1][j]) B[i][j] = 1;
				else B[i][j] = B[i + 1][j] + 1;
			}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (!a[i][j])
			{
				if (i == 1 || a[i - 1][j]) T[i][j] = 1;
				else T[i][j] = T[i - 1][j] + 1;
			}
}

void getStrips()
{
	stripCount = 0;
	for (int i = 1; i <= n; i++)
	{
		int j = 1;
		while (j <= n)
		{
			while (j <= n && a[i][j]) j++;
			if (j <= n)
			{
				int left = j;
				while (j <= n && !a[i][j]) j++;
				int right = j - 1;
				if (right > left)
				{
					strips[++stripCount] = Strip(stripCount, i, left, right);
				}
			}
		}
	}

	memset(bestField, 0, sizeof(bestField));
	for (int i = 1; i <= stripCount; i++)
	{
		int row= strips[i].row;
		int ind = row + 1;
		for (int j = strips[i].left; j <= strips[i].right; j++)
		{
			for (int k = ind; k < row + B[row][j]; k++)
				bestField[i][k] = j;
			if (row + B[row][j] > ind) ind = row + B[row][j];
		}
	}

}

void calculateP(int num)
{

	//for (int i = 1; i <= n; i++) top[i] = (a[1][i] ? 0 : 1);
	left[0] = 0;
	for (int i = 1; i <= n; i++) left[i] = (a[n][i] ? 0 : left[i - 1] + 1);
	for (int i = 1; i <= n; i++) BL[i] = (left[i] <= 1 ? 0 : left[i]);

	for (int X = n - 1; X > 1; X--)
	{
		for (int i = 1; i <= n; i++)
		{
			//if (!toInsert[i].empty()) toInsert[i].resize(0);
			//if (!toRemove[i].empty()) toRemove[i].resize(0);
			insertCount[i] = 0; removeCount[i] = 0;
		}

		for (int i = 1; i <= stripCount && strips[i].row < X; i++)
			if (strips[i].row < X && bestField[i][X] != 0)
			{
				//toInsert[ bestField[i][X] ].push_back(i);
				//toRemove[ strips[i].right ].push_back(i);
				insertCount[ bestField[i][X] ]++;
				insertVal[ bestField[i][X] ][ insertCount[ bestField[i][X] ] ] = i;
				removeCount[ strips[i].right ]++;
				removeVal[ strips[i].right ][ removeCount[ strips[i].right ] ] = i;
			}

		tree.init();
		for (int i = 1; i <= n; i++)
		{
			if (i > 1 && !a[X][i])
			{
				int P = 1 + 2 * X + i - tree.findMin(1, T[X][i] - 1);
				if (BL[i] != 0 && BL[i] + P > sol)
				{ sol = BL[i] + P; mi = X; mj = i; boardNum = num; }
			}
			for (int k = 1; k <= insertCount[i]; k++)
			//for (int k = 0; k < (int)toInsert[i].size(); k++)
			{
				int ind = insertVal[i][k];
				tree.update(X - strips[ind].row, (bestField[ind][X] == 0 ? inf : bestField[ind][X] + 2 * strips[ind].row));
			}
			for (int k = 1; k <= removeCount[i]; k++)
			//for (int k = 0; k < (int)toRemove[i].size(); k++)
			{
				int ind = removeVal[i][k];
				tree.update(X - strips[ind].row, inf);
			}
		}

		for (int i = 1; i <= n; i++) left[i] = (a[X][i] ? 0 : left[i - 1] + 1);
		for (int i = 1; i <= n; i++)
		{
			if (a[X][i]) BL[i] = 0;
			if (BL[i] != 0) BL[i] = BL[i] + 1;
			if (BL[i] < left[i] && left[i] > 1) BL[i] = left[i];
		}

	}

}

void CheckBoard(int num)
{
	memset(currTable, 0, sizeof(currTable));
	for (int i = 1; i <= k; i++)
	{
		a[ cx[i][num] ][ cy[i][num] ] = true;
		currTable[ cx[i][num] ][ cy[i][num] ] = 1;
	};

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%d ", currTable[i][j]);
		printf("\n");
	}
	printf("\n\n");

	calculateBL();
	getStrips();
	calculateP(num);

	/*for (int i = 2; i < n; i++)
		for (int j = 2; j <= n; j++)
			if (!a[i][j] && ! a[i + 1][j] && P[i][j] != inf && BL[i + 1][j] != 0)
			{
				if (P[i][j] + BL[i + 1][j] > sol)
					sol = P[i][j] + BL[i + 1][j];
				mi = i; mj = j; boardNum = num;
			}*/

	for (int i = 1; i <= k; i++)
		a[ cx[i][num] ][ cy[i][num] ] = false;
}

void Output()
{
	printf("%d\n", sol);
}

int main()
{
	Input();
	sol = 0;
	for (int i = 0; i < 8; i++)
		CheckBoard(i);
	Output();

	return 0;
}
