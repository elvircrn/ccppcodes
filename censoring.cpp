#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int lenS, lenT, b [1000100], start_index [1000100];
char S [1000100], T [1000100];

vector <char> string_stack;

void kmpPreprocess()
{
	int i = 0, j = -1;
	b [0] = -1;
	while (i < lenT)
	{
		while (j >= 0 && T [i] != T [j])
			j = b [j];
		i++;
		j++;
	}
	printf ("done\n");
}

void kmp()
{
	int i = 0, j = 0;
	while (i < lenS)
	{
		while (j >= 0 && S [i] != T [j])
			j = b [j];

		string_stack.push_back(S [i]);
		i++;
		j++;

		if (j == lenT)
		{
			//match found
			printf ("match found at: %d\n", i - j);

			for (int index = 0; index < lenT; index++)
				string_stack.pop_back();

			for (int index = 0; index < j; j++)
				start_index [i - index] = i;
		}
	}
	printf ("done\n");
}

int main()
{
	freopen ("in.txt", "r", stdin);
	
	memset (start_index, -1, sizeof start_index);

	scanf ("%s %s", &S, &T);
	printf ("%s %s\n", S, T);

	lenS = strlen(S);
	lenT = strlen(T);

	kmpPreprocess();
	kmp();


	return 0;
}
/*
whatthemomooofun
moo
*/