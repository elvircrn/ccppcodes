#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n;
    long long int temp = 0, suma = 2, sum1 = 1;
    printf ("Unesite broj n: ");
    scanf ("%d", &n);
    if (n > 50 || n < 1)
    {
        printf ("Greska: Pogresan unos. (0<n<=50");
        return 0;
    }
    if (n == 1 || n == 2)
    {
        printf ("F(%d)=1", n);
        return 0;
    }
    for (i = 3; i < n; i++)
    {
        temp = suma;
        suma = suma + sum1;
        sum1 = temp;
    }
    printf ("F(%d)=%lld\n", n, suma);
    return 0;
}
