#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int n;
char line[20];

int pizzas [20] [20];

int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf ("%s", &line);
        if (line [0] == '1' && line [2] == '4')
            pizzas [1] [4]++;
        else if (line [2] == '4')
            pizzas [3] [4]++;
        else
            pizzas [1] [2]++;
    }

    int num1 = pizzas[1] [4], num2 = pizzas [1] [2], num3 = pizzas [3] [4];

    int solution = min (num1, num3);

    num1 -= solution;
    num3 -= solution;



    return 0;
}
