#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
//x^0 + x^1 + x^2 + ... + x^5 = (x^3 + 1)*(x^2 + x^1 + x^0)
//x^0 + x^1 + x^2 + ... + x^4 = 1 + x*(x^0 + x^1 + x^2 + x^3)
using namespace std;
long long int iks, prvi, drugi, modul, stepen, power [ 200000 ], base [ 200000 ];
int fast_pow (  long long int x,  long long int n )
{
    if ( n == 0 ) return 1;
    if ( n % 2 == 0 )
    {
        int t = fast_pow ( x, n / 2 );
        return ( t % modul * t % modul );
    }
    else
    {
        int t = fast_pow ( x, n - 1 );
        return ( x % modul * t % modul );
    }
}
int expression (  long long int current_base,  long long int current_power )
{
    if ( current_power == 0 ) return 1;
    if ( current_power % 2 == 0 ) return 1 + current_base % modul * ( expression ( current_base, current_power - 1 ) ) % modul;
    else return ( fast_pow ( current_base, current_power / 2 + 1 ) + 1 ) % modul * ( expression ( current_base, current_power / 2 ) ) % modul;
}
int main ()
{
    //freopen ( "polinom.txt", "r", stdin );
    cin>>iks>>stepen>>modul;
    cout<<abs ( expression ( iks, stepen ) )<<endl;
    return 0;
}
