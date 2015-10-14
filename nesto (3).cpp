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

BIT <int> A;

int main ()
{

    A = BIT<int>(100);

    A.Set (5, 5);
    printf ("%d\n", A.Get (10));

    return 0;
}
