#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main ()
{
    int a,b;
    cin >> a >> b;
    int rez1,rez2;
    rez1=a*a;
    rez2=b*b;
    cout << sqrt(rez1+rez2);
    return 0;
}
