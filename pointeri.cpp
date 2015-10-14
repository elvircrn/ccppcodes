#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	int myvar = 25;
	int *foo = &myvar;
	int bar = myvar;

	cout<<myvar<<' '<<foo<<' '<<bar<<endl;

	*foo = 20;

	cout<<myvar<<' '<<foo<<' '<<bar<<endl;

	return 0;
}
