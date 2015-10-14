#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <string>
#include <cstring>

using namespace std;

int dimensions [3], dp [3000000];

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

bool cmp(const box &A, const box &B)
{
    if (A.x != B.x)
        return A.x < B.x;
    else if (A.y != B.y)
        return A.y < B.y;
    else
        return A.z < B.z;
}

int solution, n, test_id = 0;
vector <box> boxes;

int main()
{
    //freopen ("in.txt", "r", stdin);

    while (scanf ("%d", &n) == 1 && n)
    {
        memset (dp, 0, sizeof dp);
        solution = 0;
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

        sort (boxes.begin(), boxes.end(), cmp);

        //for (int i = 0; i < boxes.size(); i++)
        //    boxes [i].print();

        for (int i = 0; i < boxes.size(); i++)
        {
            dp [i] = boxes [i].z;
            for (int j = 0; j < i; j++)
                if (boxes [j] < boxes [i])
                    dp [i] = max (dp [i], dp [j] + boxes [i].z);

            solution = max (dp [i], solution);
        }

        printf ("Case %d: maximum height = %d\n", ++test_id, solution);
    }

    return 0;
}




























