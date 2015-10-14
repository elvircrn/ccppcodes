#include <iostream>

using namespace std;

string r;

int main()
{
    cin >> r;

    int d = r.length(), res;
    for (int i = 0; i < d; i++)
        if (r [i] = 'F' && r [i + 1] = 'B' && r [i + 2] = 'I')
            res++;

    cout << res << endl;

    return 0;
}
