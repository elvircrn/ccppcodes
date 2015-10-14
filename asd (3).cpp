#include <stdio.h>
#include <stdlib.h>

int main()
{ /**zasad samo za neparne **/
    int n, i, j, jm, im, k, l;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
            for(j=1;j<=n;j++)
            {
                im = i % 2;
                jm = j % 2;
                if(im==1 && jm==1 && i==j)printf("*");
                else if(i==1 || i==n)printf("*");
                else if(j==1 || j==n)printf("*");
                else if(i==(n-2) && j>=3 && j<=(n-2))printf("*");
                else if(i==3 && j>=3 && j<=(n-2))printf("*");
                else if(j==(n-2) && i>=3 && i<=(n-2))printf("*");
                else if(j==3 && i>=3 && i<=(n-2))printf("*");
                else printf(" ");

            }
        printf("\n");
    }
    return 0;
}
