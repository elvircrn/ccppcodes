#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

class Bit
{
    public:
    vector <int> tree;
    int max_size;

    Bit () { }
    Bit (int size) { max_size = size; tree = vector <int> (max_size + 5); }

    void Set (int index, int value)
    {
        while (index <= max_size)
        {
            tree [index] += value;
            index += (index & -index);
        }
    }

    int Sum (int index)
    {
        int sum = 0;

        while (index)
        {
            sum += tree [index];
            index -= (index & -index);
        }

        return sum;
    }

    int GetElementAt (int index)
    {
        return Sum (index) - Sum (index - 1);
    }

    int GetRange (int start, int end)
    {
        return Sum (end) - Sum (start - 1);
    }
};

Bit bit;

int main ()
{

    bit = Bit (20);

    bit.Set (1, 10);

    printf ("%d\n", bit.Sum (15));

    return 0;
}
