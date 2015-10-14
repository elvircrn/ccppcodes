#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string dugarijec;
    int brojac=0;
    getline(cin,dugarijec);
    for (int i=0;i<dugarijec.length();i++)
    {
        if (dugarijec.substr(i,3)=="FBI")
        {
            brojac++;
        }
    }
    cout << brojac;
    return 0;
}
