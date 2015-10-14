#include <iostream>

using namespace std;

int izracunaj(const char *izraz);

int main() {
	int rez = izracunaj("1+5");
	if (rez != 6)
		cout << "Za izraz \"1+5\" vracen rezultat " << rez << " umjesto 6!" << endl;
	rez = izracunaj("3+2+7");
	if (rez != 12)
		cout << "Za izraz \"3+2+7\" vracen rezultat " << rez << " umjesto 12!" << endl;
	rez = izracunaj("3+2-7-4+7");
	if (rez != 1)
		cout << "Za izraz \"3+2-7-4+7\" vracen rezultat " << rez << " umjesto 1!" << endl;
	rez = izracunaj("1+2-4*3+9/3");
	if (rez != -6)
		cout << "Za izraz \"1+2-4*3+9/3\" vracen rezultat " << rez << " umjesto -6!" << endl;
	rez = izracunaj("1+(2-4)*3+9/3");
	if (rez != -2)
		cout << "Za izraz \"1+(2-4)*3+9/3\" vracen rezultat " << rez << " umjesto -2!" << endl;
	rez = izracunaj("1+((2-4)*3+9)/3");
	if (rez != 2)
		cout << "Za izraz \"1+((2-4)*3+9)/3\" vracen rezultat " << rez << " umjesto 2!" << endl;
}
