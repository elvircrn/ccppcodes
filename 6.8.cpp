#include <stdio.h>
#include <stdlib.h>

void copyString(char where[], char from[])
{
    printf ("here\n");
    int len = strlen(from), i;
    *where = (char*)malloc(len + 2);

    for (i = 0; i < len; i++)
        where[i] = from[i];

    where[len] = '\0';
}

int main()
{
    char list[100] [100];

    printf ("names read form in.txt located in the same folder as the .exe file\n");
    freopen ("in.txt", "r", stdin);

    int current_index = 0;

    char name[100];
    while (scanf ("%s", &name) == 1)
        copyString(list[current_index++], name);

    printf ("number of names: %d\n", current_index);
    for (int i = 0; i < current_index; i++)
        printf ("%s\n", list[i]);

    return 0;
}



































