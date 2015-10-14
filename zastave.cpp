#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

const int height = 6;
const int width = 9;

char field [100] [100];

int solution = 100000;

int main ()
{
    for (int i = 0; i < height; i++)
        scanf ("%s", &field [i]);

    for (int mid = 0;  mid < 26;  mid++)
        for (int top = 0; top < 26; top++)
         {
            int cnt = 0;
            for (int bot = 0; bot < 26; bot++)
            {
                if (mid == top || mid == bot)
                    continue;

                for (i = 0; i < 2; i++)
                    for (int j = 0; j < width; j++)
                        if (field [i] [j] != (top + 'A'))
                            cnt++;
            }
         }

    return 0;
}








