#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

int number;

int get_number()
{
    return rand() % 100;
}

int main()
{
    number = get_number();

    cout<<"think of a number\n";

    int tries = 0, left = 1, right = 100, guess;
    string answer;

    while (left <= right)
    {
        guess = (left + right) / 2;

        cout<<"is your your number(Y) or is it higher(H) or lower(L) than "<<guess<<"?"<<endl;
        cin>>answer;

        if (answer == "Y")
            break;
        else if (answer == "H")
            left = guess + 1;
        else
            right = guess - 1;

        tries++;
    }

    cout<<"tries: "<<tries<<endl;
    return 0;
}


















