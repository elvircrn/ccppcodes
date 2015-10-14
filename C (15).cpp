#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define INF 1<<28

char s [2100], p [510];
int lens, lenp, A [2100], dp [2100] [2100];

int main()
{
    scanf ("%s %s", &s, &p);

    lens = strlen(s);
    lenp = strlen(p);

    for (int i = 0; i < lens; i++)
    {
        int current_index = 0, counter = 0;

        for (int j = i; j < lens; j++)
        {
            counter++;
            if (s [j] == p [current_index])
                current_index++;

            if (current_index == lenp)
                break;
        }

        if (current_index == lenp)
            A [i] = counter;
        else
            A [i] = -1;
    }

    for (int i = 0; i < lens; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            dp [i + 1] [j + 1] = max (dp [i + 1] [j + 1], dp [i] [j]);
            dp [i + 1] [j]     = max (dp [i + 1] [j], dp [i] [j]);
            if (A [i] >= 0)
                dp [i + A [i]] [j + A [i] - lenp] = max(dp [i] [j] + 1, dp [i + A [i]] [j + A [i] - lenp]);
        }
    }

    printf ("%d", dp [lens] [0]);
    for (int i = 1; i <= lens; i++)
        printf (" %d", dp [lens] [i]);
    printf("\n");

    return 0;
}
/*
aaxbaxxb
ab
C:\ProgramData\Oracle\Java\javapath;C:\MinGW\bin;C:\Program Files (x86)\CodeBlocks\MinGW\bin;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;%SystemRoot%\system32;%SystemRoot%;%SystemRoot%\System32\Wbem;%SYSTEMROOT%\System32\WindowsPowerShell\v1.0\;C:\Program Files (x86)\Intel\OpenCL SDK\2.0\bin\x86;C:\Program Files (x86)\Intel\OpenCL SDK\2.0\bin\x64;c:\Program Files (x86)\Microsoft SQL Server\100\Tools\Binn\;c:\Program Files\Microsoft SQL Server\100\Tools\Binn\;c:\Program Files\Microsoft SQL Server\100\DTS\Binn\
*/
