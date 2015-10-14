#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int mod = 2012;

vector <char> brackets;
vector <int> height;

int cnt, O[1010], solution = 1, dp[1010] [1010];

int solve(int current_index, int H)
{
    int G = O [current_index] - H;
    if (current_index == (int)brackets.size() && H == 0 && G == 0)
        return 1;
    else if (dp [current_index] [H] != -1)
        return dp [current_index] [H] % mod;

    if (brackets[current_index] == '(')
        return dp [current_index] [H] = (solve (current_index + 1, H + 1) % mod + solve (current_index + 1, H) % mod) % mod;
    else
        return dp [current_index] [H] = ((H ? solve(current_index + 1, H - 1) : 0) % mod + (G ? solve(current_index + 1, H) : 0) % mod) % mod;
}

int main()
{
    char c;
    while ((c = getchar()) == '(' || c == ')')
        brackets.push_back(c);

    memset(dp, -1, sizeof dp);

    O [0] = 0;

    for (int i = 0; i < brackets.size(); i++)
    {
        cnt += ((brackets[i] == '(') ? 1 : -1);
        O [i + 1] = O [i] + ((brackets[i] == '(') ? 1 : -1);
    }

    printf ("%d\n", solve(0, 0) % mod);

    return 0;
}
/*
(((())()))

*/

































