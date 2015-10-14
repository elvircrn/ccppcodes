#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <string.h>

void unos(char *string)
{
    char c;
    while (!isalnum(c = getchar()));

    do
    {
        *string = c;
        string++;
    } while(isalnum(c = getchar()));
    *string = '\0';
}


int main()
{
    int i, n, trajanje, k = 0;
    char ime[100];

    while (1)
    {
        scanf ("%d", &n);
        if (n == 1)
        {
            printf ("Unesite naziv predmeta: ");
            unos(ime);
            printf ("%s\n", &unos);
            printf ("%d\n", strlen(ime));
        }


        if (n == 0) break;
    }
    return 0;
}

