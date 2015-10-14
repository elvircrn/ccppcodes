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

namespace Competiton_ALPHA
{
    template <class T>
    class BIT
    {
    public:
        vector <int> bit;
        int size;

        BIT () { }
        BIT (int size) { (*this).size = size; bit = vector <int> (size + 5); }

        void Set (T val, int ind)
        {
            while (ind <= size)
            {
                bit [ind] += val;
                ind += ind & (-ind);
            }
        }

        int Get (int ind)
        {
            int ret = 0;

            while (ind)
            {
                ret += bit [ind];
                ind -= ind & (-ind);
            }

            return ret;

        }

        int GetRange (int START, int END)
        {
            return Get (END) - Get (START - 1);
        }

    };
}

using namespace Competiton_ALPHA;


int t, q, number = 1, last = 0;
float sum = 0;

BIT <int> Bit (3000);

int main ()
{
    int a, b;

    scanf ("%d", &t);
    while (t--)
    {
        scanf ("%d", &q);
        if (q == 1)
        {
            scanf ("%d %d", &a, &b);
            Bit.Set (a, 1);
            Bit.Set (-a, b + 1);
        }
        else if (q == 2)
        {
            scanf ("%d", &a);
            number++;
            Bit.Set (a, number);
            Bit.Set (-a, number + 1);
        }
        else
        {
            Bit.Set (-a, number);
            number--;
        }

        printf ("%.6f\n", float (float (Bit.Get (number)) / float (number)));
    }


    return 0;
}
