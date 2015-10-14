#include <stdio.h>

int main()
{
    int n, i, j, k = 0;
    printf ("Unesite n: ");
    scanf ("%d", &n);

    if (n < 1 || n > 30)
    {
        printf ("Greska! (0 < n < 30)\n");
        return 0;
    }

    if (n % 2 == 0) k = 1;

    for (i = 0; i <n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i % 2 == 0 && j >= i && j <= (n-i-1)) printf("*");
            else if (i % 2 == k && j > (n-i-1) && j < i) printf ("*");
            else if (j % 2 == 0 && i > j && i < (n-j)) printf("*");
            else if (j % 2 == k && i >= (n-j) && i <= j) printf ("*");
            else printf (" ");
        }
        printf("\n");
    }
    return 0;
}
