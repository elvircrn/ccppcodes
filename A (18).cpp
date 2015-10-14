#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int n, A, B;
string input [101];
int matrix [101] [101];

vector <pair <int, int> > solution [101];

int main()
{
    //freopen ("in.txt", "r", stdin);
    cin>>n;
    for (int i = 0; i < n; i++)
        cin>>input [i];

    for (int i = 0; i < n; i++)
    {
        for (int a = 1; a <= 12; a++)
        {
            for (int b = 1; b <= 12; b++)
            {
                if (a * b == 12)
                {
                    A = a;
                    B = b;
                    int counter(0);
                    for (int ii = 0; ii < A; ii++)
                    {
                        for (int jj = 0; jj < B; jj++)
                        {
                            matrix [ii] [jj] = input [i] [counter];
                            counter++;
                        }
                    }

                    bool Nasao(false);

                    for (int ii = 0; ii < B; ii++)
                    {
                        bool nasao = true;
                        for (int jj = 0; jj < A; jj++)
                        {
                            if (matrix [jj] [ii] == 'O')
                            {
                                nasao = false;
                                break;
                            }
                        }

                        Nasao |= nasao;
                    }

                    if (Nasao)
                        solution [i].push_back (make_pair (a, b));
                }
            }
        }
        printf ("%d", solution [i].size());
        for (int j = 0; j < solution [i].size(); j++)
            printf (" %dx%d", solution [i] [j].first, solution [i] [j].second); printf ("\n");
        solution [i].clear();
    }

    return 0;
}
