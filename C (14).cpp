#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int a [100100], n, p;
bool duhh [100100];
bool visited [100100];
bool visited2 [100100];

int generation [100100];
vector <int> generated;
vector <int> solution;

int main()
{
    scanf ("%d %d", &n, &p);

    if (p == 1)
    {
        printf ("%d", n);
        for (int i = n - 1; i >= 1; i--)
            printf (" %d", i); printf ("\n");
        return 0;
    }

    int diff = n - 1;

    generated.push_back(n);

    visited2 [n] = true;

    for (int i = diff; i >= 1; i--)
    {
        int top = generated[generated.size() - 1];
        generated.push_back ((top - i > 0 && !visited2 [top - i]) ? (top - i) : (top + i));
        visited2 [(top - i > 0 && !visited2 [top - i]) ? (top - i) : (top + i)] = true;
    }

    if (n == p + 1)
    {
        printf ("%d", generated [0]);
        for (int i = 1; i < generated.size(); i++)
            printf (" %d", generated [i]);
        return 0;
    }

    for (int i = 0; i < n - 1; i++)
    {
        generation [i] = n - i - 1;
    }

    int cn = n - 2;

    for (int i = 0; i < (n - p); i++)
    {
        if (n == p + 1)
            break;
        duhh [cn] = true;
        generation [cn] = 1;
        cn--;
    }

    int current_index = 0;
    int prev = n;

    solution.push_back(n);
    visited [n] = true;

    cn = (n - 1) - (n - p);

    for (int i = 1; i < n; i++)
    {
        if (duhh [i])
        {
            int current = (prev - generation [i - 1] > 0 && !visited [prev - generation [i - 1]]) ? (prev - generation [i - 1]) : (prev + generation [i - 1]);

            visited [prev] = true;

            int left = (n - i);


            if (left + current > n)
            {
                for (int j = current; j > 1; j--)
                    solution.push_back(j);
            }
            else
            {
                for (int j = current; j < n; j++)
                    solution.push_back(j);
                break;
            }
        }
        solution.push_back(((prev - generation [current_index]) > 0) ? (prev = prev - generation [current_index]) : (prev = generation [current_index] + prev));
        current_index++;
    }

    printf ("%d", solution [0]);
    for (int i = 1; i < n; i++)
        printf (" %d", solution [i]);
    printf ("\n");

    return 0;
}


/*
░░░░░░░░░░░░▄▐
░░░░░░▄▄▄░░▄██▄
░░░░░▐▀█▀▌░░░░▀█▄
░░░░░▐█▄█▌░░░░░░▀█▄
░░░░░░▀▄▀░░░▄▄▄▄▄▀▀     you have been spooked by the spooky skeleton
░░░░▄▄▄██▀▀▀▀
░░░█▀▄▄▄█░▀▀
░░░▌░▄▄▄▐▌▀▀▀
*/
