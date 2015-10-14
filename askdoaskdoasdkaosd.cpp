#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <exception>
#include <stdexcept>

using namespace std;


void StirlingoviBrojeviV1 (int n)
{
    int **S =  new int*[n];

    cout<<"before: "<<n<<endl;

    for (int i = 0; i < n; i++)
    {
        n = 12;
        S [i] = new int [i + 1];
        n = 12;
        cout<<"i: "<<i<<" n: "<<n<<endl;
    }

    cout<<"finished"<<endl;

    system ("pause");
}

/*
int**a(new int*[n]);
a[0] = new int[n * m];
for(inti = 1; i < n; i++) a[i] = a[i – 1] + m;
*/

int main()
{
    StirlingoviBrojeviV1(12);

    return 0;
}



































