#include <iostream>
#include <algorithm>

using namespace std;

int n, maxX, maxY, minX, minY;
int x[50005], y[50005];
bool field[50005][50005];
int moveX[4] = {0, 1, 0, -1};
int moveY[4] = {1, 0, -1, 0};

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        if (!i) {
            minX = x[i];
            minY = y[i];
        }

        maxX = max(x[i], maxX);
        maxY = max(y[i], maxY);
        minX = min(x[i], minX);
        minY = min(y[i], minY);
    }

    for (int i = 0; i < n; i++)
        field[x[i] - minX + 1][y[i] - minY + 1] = 1;

    int rez = 0;
    for (int i = 1; i < maxX - minX + 2; i++)
    {
        for (int j = 1; j < maxY - minY + 2; j++)
        {
            if (field[i][j] == 1) {
                for (int k = 0; k < 4; k++)
                    if (field[i + moveX[k]][j + moveY[k]] == 0)
                        rez++;
            }
            else {
                bool four = 1;
                for (int k = 0; k < 4; k++) {
                    if (field[i + moveX[k]][j + moveY[k]] == 0)
                        four = 0;
                }

                if (four)
                    rez -= 4;
            }
        }
    }

    cout << rez << endl;

    return 0;
}
