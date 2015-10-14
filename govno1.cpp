#include <iostream>

using namespace std;

int n, m, r;
int brojnacina;
char matrica [1000] [1000];

void dfs (int x, int y, int depth)
{

    if (x < 0 || y < 0 || x >= n || y >= m)
        return;
    if (matrica [x] [y] == 'T')
        return;
    if (matrica [x] [y] == 'P')
        return;

    if (x == 0 && y == m - 1)
    {
        brojnacina++;
        return;
    }

    if (depth >= r)
        return;

    matrica[x][y]='P';

    dfs (x + 1, y, depth + 1);
    dfs (x - 1, y, depth + 1);
    dfs (x, y + 1, depth + 1);
    dfs (x, y - 1, depth + 1);

    matrica[x][y]='.';

    return;
}

int main()
{
    cin>>n>>m>>r;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>matrica [i] [j];
    dfs(n-1,0, 1);

    cout<<brojnacina <<endl;

    return 0;
}
