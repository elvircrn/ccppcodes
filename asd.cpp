#include <algorithm>
#include <iostream>
using namespace std;
int main ()
{
unsigned long long int a,b,c,d,e,f,g,h;
cin >> a>>b>>c>>d;
e=(a*d+c*b);
g=b*d;
h=__gcd(e,g);
cout<<e/h<<'/'<<g/h;

//system ("pause");
return 0;

}
