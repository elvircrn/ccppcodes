#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;



int get_area (float a, float b, float c)
{
    float s = (a + b + c) / 2.0f;
    float area;

    area = sqrt (s * (s - a) * (s - b) * (s - c));

    return int (area);
}

int NajveciTrougao (int n)
{
    n -= (n % 3);
    float N = n;
    float s = N / 2.0f;
    float area;

    float a, b, c;

    if (n % 3 == 0)
    {
        a = N / 3.0f;
        b = a;
        c = a;
    }

    //cout<<a<<' '<<b<<' '<<c<<endl;

    long long int asd = sqrt (s * (s - a) * (s - b) * (s - c));

    return asd % 10;
}

