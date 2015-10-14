#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int test_cases;
char file_name[12], in_name[12], out_name[12];

int main()
{
    printf ("test case number? ");
    scanf ("%d", &test_cases);

    printf ("source file name: ");
    scanf ("%s", &file_name);

    printf ("in file name: ");
    scanf ("%s", &in_name);

    printf ("out file name: ");
    scanf ("%s", &out_name);

    for (int test_case = 1; test_case <= test_cases; test_case++)
    {
        printf ("case #%d result: ", test_case);

    }

    return 0;
}
