#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct movie
{
	//properties
	string title; 
	int year;

	//constructors
	//default constructor
	movie()
	{

	}

	movie(string _title, int _year)
	{
		title = _title;
		year = _year;
	}

	void print_info()
	{
		cout << title << ' ' << year << endl;
	}

	void print_info() const
	{
		cout << title << ' ' << year << endl;
	}

	bool operator< (const movie &B) const
	{
		return year < B.year;
	}
};

int main()
{
	movie *m = new movie("Fight Club", 2000);

	cout << (*m).title << endl;

	cout << m->title << endl;

	m->print_info();

	return 0;
}



