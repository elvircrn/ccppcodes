#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

float calculateCharges(float hours)
{
    if (hours < 3.0f)
        return 2.0f;
    else
        return min ((float)((hours - 3.0f) * 0.5 + 2.0f), 10.0f);
}

float customers [5];

int main()
{
    float hours, total_hours = 0.0f, total_charge = 0.0f;
    for (int i = 1; i <= 3; i++)
    {
        scanf ("%f", &customers [i]);
        total_hours += customers [i];
        total_charge += calculateCharges(customers [i]);
    }

    printf ("Car     Hours   Charge\n");
    for (int i = 1; i <= 3; i++)
        printf ("%d       %-4.1f    %-5.2f\n", i, customers [i], calculateCharges(customers [i]));
    printf ("TOTAL   %-4.1f    %-5.2f\n", total_hours, total_charge);

    return 0;
}
/*
1.5
4.0
24.0
*/
