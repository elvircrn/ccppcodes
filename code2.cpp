#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int reverse (int number)
{
    int cnt(0);

    while (number)
    {
        cnt = (cnt * 10) + number % 10;
        number /= 10;
    }

    return cnt;
}

int rec (int current_number)
{
    if (current_number == 0)
        return ;
    if (current_number / 10 == 0)
    {

    }
}

int main()
{

    return 0;
}
