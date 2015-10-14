#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    string b, a = "", rijec, unos;
    int trenutna_recenica = 1;

    cin>>b;
    for (int i = 0; i < b.length(); i++)
        rijec += tolower (b [i]);

    while (cin>>unos)
    {
        for (int i = 0; i < unos.length(); i++)
        {
            if (!isalpha (unos [i]))
            {
                if (a == rijec)
                    cout<<trenutna_recenica<<endl;
                a = "";
            }
            a += tolower (unos [i]);

            if (unos [i] == '.')
                trenutna_recenica++;
        }
        if (a == rijec)
            cout<<trenutna_recenica<<endl;

        a = "";
    }

    system ("pause");
    return 0;
}
