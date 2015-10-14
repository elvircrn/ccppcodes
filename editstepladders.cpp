#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

int myAbs (int x)
{
    if (x < 0)
        return x * (-1);
    else
        return x;
}

struct Word
{
    char letters [20];

    void Input()
    {
        scanf ("%s", &letters);
    }

    bool operator == (const Word &B) const
    {
        int lA = strlen (letters);
        int lB = strlen (B.letters);

        if (myAbs (lA - lB) > 1)
            return false;

        if (lA == lB)
        {
            int mistakes = 0;
            for (int i = 0; i < lA; i++)
            {
                if (letters [i] != B.letters [i])
                {
                    mistakes++;
                    if (mistakes == 2)
                    {
                        return false;
                    }
                }
            }

            return true;
        }
        else if (lA < lB)
        {
            int l1 = 0, l2 = 0, mistakes = 0;
            while (l2 < lB)
            {
                if (letters [l1] != B.letters [l2])
                {
                    mistakes++;

                    if (mistakes == 2)
                        return false;

                    l1--;
                }
                l1++;
                l2++;
            }

            return true;
        }
        else
        {
            int l1 = 0, l2 = 0, mistakes = 0;
            while (l1 < lA)
            {
                if (letters [l1] != B.letters [l2])
                {
                    mistakes++;

                    if (mistakes == 2)
                        return false;

                    l2--;
                }
                l1++;
                l2++;
            }

            return true;
        }
        return false;
    }
};

Word words [30000];
char line [20];

void dfs (int current_index, )

int main ()
{
    int it = 0;
    while (scanf ("%s", &words [it].letters) == 1)
    {

    }

    return 0;
}
//dog
//dg
/*
300
300
400
450
850
670
600
*/
