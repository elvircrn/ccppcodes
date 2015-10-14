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

typedef long long int ll;

ll** StirlingoviBrojeviV1 (int n)
{
    ll **S;
    int i;
    try
    {
        if (n < 0)
            throw domain_error("Parametar  ne smije  biti  negativan");

        ll **S = new (nothrow) ll* [n];

        if (S == NULL)
            throw range_error("Parametar prevelik za raspolozivu memoriju");

        for (i = 0; i < n; i++)
        {
            S [i] = new (nothrow)ll [i + 1];
            if (S [i] == NULL)
                throw range_error ("Parametar prevelik za raspolozivu memoriju");
        }

        return S;
    }
    catch (domain_error e)
    {
        for (int ind = 0; ind < i; ind++)
            delete[] S [ind];
        cout<<e.what()<<endl;
    }
    catch (range_error e)
    {
        delete S;
        cout<<e.what()<<endl;
    }

    return NULL;
}

ll** StirlingoviBrojeviV2 (int n)
{
    ll** S;
    int i;
    try
    {
        if (n < 0)
            throw domain_error ("Parametar  ne smije  biti  negativan");

        S = new(nothrow) ll*[n];

        if (S == NULL)
            throw range_error("Parametar prevelik za raspolozivu memoriju");

        S[0] = new(nothrow) ll[(n * (n + 1)) / 2];

        if (S [0] == NULL)
            throw range_error("Parametar prevelik za raspolozivu memoriju");

        for(i = 1; i < n; i++)
            S [i] = S [i - 1] + (i + 1);

        return S;
    }
    catch (range_error e)
    {
        cout<<e.what()<<endl;
        delete[] S;
        //delete[] S;
    }
    catch (domain_error e)
    {
        delete S;
        cout<<e.what();
    }

    return NULL;
}

/*
int**a(new int*[n]);
a[0] = new int[n * m];
for(inti = 1; i < n; i++) a[i] = a[i – 1] + m;
*/

int main()
{
    int n;
    cin>>n;

    ll **S;

    if ((S = StirlingoviBrojeviV1(n)) != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            for (ll j = 0; j <= i; j++)
            {
                if (i == 0 && j == 0)
                    S [0] [0] = 0;
                else if (j == 0)
                    S [i] [j] = 0;
                else if (i == j)
                    S [i] [j] = 1;
                else
                    S [i] [j] = S [i - 1] [j - 1] + j * S [i - 1] [j];
                cout<<S [i] [j]<<' ';
            }
            cout<<endl;
        }


        for (int i = 0; i < n; i++)
            delete[] S[i];
        delete[] S;
    }

    if ((S = StirlingoviBrojeviV2(n)) != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            for (ll j = 0; j <= i; j++)
            {
                if (i == 0 && j == 0)
                    S [0] [0] = 0;
                else if (j == 0)
                    S [i] [j] = 0;
                else if (i == j)
                    S [i] [j] = 1;
                else
                    S [i] [j] = S [i - 1] [j - 1] + j * S [i - 1] [j];
                cout<<S [i] [j]<<' ';
            }
            cout<<endl;
        }
        delete[] S;
    }

    return 0;
}


































