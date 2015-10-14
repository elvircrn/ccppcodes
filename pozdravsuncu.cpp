#include <iostream>
#include <string>

using namespace std;

int main ()
{
    int h;
    cin >> h;
    int b[h];
    string a[h];
    for (int i=0;i<h;i++)
    {
        cin >> a[i] >> b[i];
    }
    for (int i=0;i<h;i++)
    {
        for (int j=0;j<b[i];j++)
        {
            cout << a[i] << endl;
        }
    }
    return 0;
}
