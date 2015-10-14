#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string a[n];
    int b[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<b[i];j++)
        {
            cout << a[i] << endl;
        }
    }
    return 0;
}
