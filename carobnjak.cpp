#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long int ll;

#define INF 1<<27

int T, Zadaci [100000], N;

int solve(int current_index, int number_of_people)
{
    if (number_of_people >= N)
        return INF;

    //make wizards

    int make;

    if (number_of_people * 2 > N)
    {
        make = N -
    }

    int t1 = number_of_people * T + solve (current_index, number_of_people * 2);

    //use wizards

    int t2;

    if (current_index + number_of_people - 1 > N)
        t2 = Zadaci [current_index] + solve (N - 1, 1);

    int t2 = Zadaci [current_index] + solve (current_index + number_of_people - 1, 1);
}

int MinimalnoVrijeme (int n, int zadaci[], int t)
{
    memcpy (zadaci, Zadaci, sizeof (int));
    sort (Zadaci, Zadaci + n);
    reverse (Zadaci, Zadaci + n);

    printf ("%d\n", solve (0, 1));

    return 0;
}


/*


3 6 9 12 15
t = 1000

4000 + 1000


*/







