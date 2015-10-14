#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

char str[] = "This is a string";

int main()
{
    cout<<strstr(str, "string") - str<<endl;

    return 0;
}
