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
		cout<<title<<' '<<year<<endl;
	}

	void print_info() const
	{
		cout<<title<<' '<<year<<endl;
	}

	bool operator< (const movie &B) const
	{
		return year < B.year;
	}
};

vector <movie> movies = { movie ("some movie a", 2000), movie("some movie b", 1998), movie("some movie c", 2015) };

int main()
{
	sort (movies.begin(), movies.end());
	for (movie m : movies)
		m.print_info();
	cout<<endl<<endl;

	for (movie &m : movies)
		m.year = 2000;

	for (movie m : movies)
		m.print_info();
	
	return 0;
}


