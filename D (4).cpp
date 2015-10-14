#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

char word [1000000];
int len, solution;
vector <int> numbers;
char prvi;

int main()
{
    scanf ("%s", &word);

    prvi = word [0];

    int counter = 1;

    for (int i = 1; i < len; i++)
    {
        if (word [i - 1] == word [i])
        {
            counter++;
        }
        else
        {

        }
    }

    return 0;
}
