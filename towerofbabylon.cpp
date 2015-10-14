#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <string>
#include <cstring>

using namespace std;

int dimensions [3], dp [100000];

struct box
{
    int x, y, z;

    box() { }
    box(int _x, int _y, int _z) { x = _x; y = _y; z = _z; }

    bool operator< (const box &B) const
    {
        return (x < B.x && y < B.y);
    }

    void print()
    {
        printf ("x: %d y: %d z: %d\n", x, y, z);
    }
};

int maximum, n, test_id = 1;

vector <box> boxes;

int main()
{
    freopen ("in.txt", "r", stdin);

    while (scanf ("%d", &n) == 1 && n)
    {
        memset (dp, 0, sizeof dp);
        maximum = 0;
        boxes.clear();

        while (n--)
        {
            for (int i = 0; i < 3; i++)
                scanf ("%d", &dimensions [i]);

            sort (dimensions, dimensions + 3);

            boxes.push_back (box (dimensions [0], dimensions [1], dimensions [2]));
            boxes.push_back (box (dimensions [0], dimensions [2], dimensions [1]));
            boxes.push_back (box (dimensions [1], dimensions [2], dimensions [0]));
        }

        sort (boxes.begin(), boxes.end());

        for (int i = 0; i < boxes.size(); i++)
            boxes [i].print();

        int solution = 0;

        for (int i = 0; i < boxes.size(); i++)
        {
            dp [i] = boxes [i].z;
            for (int j = 0; j < i; j++)
                if (boxes [j] < boxes [i])
                    dp [i] = max (dp [i], dp [j] + boxes [i].z);

            solution = max (dp [i], solution);
        }

        printf ("Case %d: maximum height = %d\n", test_id, solution);

        test_id++;
    }

    return 0;
}




























