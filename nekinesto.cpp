#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

string strings[1000];
int n;

int main()
{
    cin>>n;
    for (int i = 0; i < n; i++)
        cin>>strings [i];
    sort (strings, strings + n);
    for (int i =  0; i < n; i++)
        cout<<strings [i]<<endl;

    return 0;
}
