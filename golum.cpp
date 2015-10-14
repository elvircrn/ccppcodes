#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

string input;
vector <string> strings;

void solve (string current_string, string golum)
{
    string cs = current_string;
    if (current_string [input.length() - 1] == '.')
    {
        strings.push_back (golum);
        return;
    }

    for (int i = 0; i < input.length(); i++)
    {
        if (current_string [i] != '.')
        {
            if (i == input.length() - 1)
            {
                cs [i] = '.';
                solve (cs, golum + char (input [i] - '0' + 'A'));
                return;
            }
            else
            {
                int asd = (input [i] - '0') * 10 + (input [i + 1] - '0');

                if (asd >= 0 && asd <= 25)
                {
                    cs [i] = '.';
                    cs [i + 1] = '.';
                    string g = golum;
                    g += char (asd + 'A');
                    solve (cs, g);
                }

                cs = current_string;
                cs [i] = '.';

                golum += char (input [i] - '0' + 'A');

                solve (cs, golum);
                return;
            }
        }
    }

    return;
}

int main()
{
    cin>>input;
    solve (input, "");

    for (int i = 0; i < strings.size(); i++)
        cout<<strings [i]<<endl;

    return 0;
}











