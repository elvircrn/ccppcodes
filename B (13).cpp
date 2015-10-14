#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

class Jumping
{
public:

    float distance(int x1, int y1, int x2, int y2)
    {
        return sqrt ((x1 - x2) * (x1 - x2) + (float)(y1 - y2) * (y1 - y2));
    }

    string ableToGet(int x, int y, vector <int> jumpLengths)
    {
        float total = distance(0, 0, x, y);

        float t = 0.0f;

        for (int i = 0; i < jumpLengths.size(); i++)
        {
            if (i == 0)
                t += jumpLengths [i];
        }

        if (t < total)
            return "Not able";

        if (jumpLengths.size() == 1 && t > total)
            return "Not able";

        return "Able";
    }
};

int main()
{


    return 0;
}










































