#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#incldue <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;

int sx1 [100], sy1 [100], sx2 [100], sy2 [100];
int n;

map <int, int> x_hash, y_hash;

class PenLift
{
public:
    int encode(int x, int y)
    {
        return x<<7|y;
    }

    int numTimes(vector<string> segments, int N)
    {
        n = N;
        for (int i = 0; i < segments.size(); i++)
        {
            stringstream ss(segments [i]);
            ss>>sx1 [i]>>sy1 [i]>>sx2 [i]>>sy2 [i];

        }
    }
};

int main()
{


    return 0;
}
