#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int convert(string number, int base)
{
    int ret = 0;
    int power = 1;

    for (int i = number.length() - 1; i > -1; i--)
    {
        ret += ((number [i] - '0') * power);
        power *= base;
    }

    return ret;
}



int main()
{
    string asd;

    cin>>asd;

    cout<<convert(asd, 3)<<endl;

    return 0;
}
