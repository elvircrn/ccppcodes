#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    if (getchar() == 'Y')
        system ("unhide.bat");
    else
        system ("hide.bat");

    system ("CLS");

    return 0;
}
